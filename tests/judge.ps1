param(
    [string]$Problem = "01",
    [switch]$All,
    [switch]$Compile
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$repoRoot = Split-Path $PSScriptRoot -Parent
$inputRoot = Join-Path $PSScriptRoot "inputs"
$outRoot = Join-Path $PSScriptRoot "outputs"
$gotRoot = Join-Path $PSScriptRoot "got"

New-Item -ItemType Directory -Force -Path $gotRoot | Out-Null

Push-Location $repoRoot
try {
    if ($Compile -or -not (Test-Path ".\\main.exe")) {
        Write-Host "[build] g++ -std=c++17 -O2 -Wall -Wextra ACM_IO.cpp -o main.exe"
        g++ -std=c++17 -O2 -Wall -Wextra ACM_IO.cpp -o main.exe
        if ($LASTEXITCODE -ne 0) {
            throw "Compile failed."
        }
    }

    $targets = @()
    if ($All) {
        $targets = Get-ChildItem $inputRoot -Directory | Sort-Object Name | Select-Object -ExpandProperty Name
    }
    else {
        $targets = @($Problem)
    }

    foreach ($p in $targets) {
        $inDir = Join-Path $inputRoot $p
        if (-not (Test-Path $inDir)) {
            Write-Host "[skip] problem ${p}: no input folder"
            continue
        }

        $problemGot = Join-Path $gotRoot $p
        New-Item -ItemType Directory -Force -Path $problemGot | Out-Null

        Write-Host "== Problem $p =="
        $cases = Get-ChildItem $inDir -Filter *.in -File | Sort-Object Name
        foreach ($case in $cases) {
            $base = [System.IO.Path]::GetFileNameWithoutExtension($case.Name)
            $got = Join-Path $problemGot ($base + ".got")
            $expected = Join-Path (Join-Path $outRoot $p) ($base + ".out")

            $runCmd = ".\\main.exe < `"$($case.FullName)`" > `"$got`""
            cmd /c $runCmd
            if ($LASTEXITCODE -ne 0) {
                Write-Host "  [runtime error] case $base"
                continue
            }

            if (Test-Path $expected) {
                $same = (Get-Content -Raw $expected) -ceq (Get-Content -Raw $got)
                if ($same) {
                    Write-Host "  [PASS] case $base"
                }
                else {
                    Write-Host "  [FAIL] case $base (see: tests/got/$p/$base.got)"
                }
            }
            else {
                Write-Host "  [RAN ] case $base (no expected output: tests/outputs/$p/$base.out)"
            }
        }
    }
}
finally {
    Pop-Location
}
