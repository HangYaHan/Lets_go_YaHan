$root = Join-Path $PSScriptRoot "inputs"
New-Item -ItemType Directory -Force -Path $root | Out-Null

$data = @{
    "01" = @(
        @"
1 2
"@,
        @"
-5 9
"@,
        @"
0 0
"@,
        @"
123456 654321
"@
    )
    "02" = @(
        @"
3 2.5 hello
"@,
        @"
-7 0 world
"@,
        @"
0 -12.3456 z
"@,
        @"
42 99999.995 abcXYZ
"@
    )
    "03" = @(
        @"
1 2
3 4
"@,
        @"
-1 -2
10 -3
"@,
        @"
0 0
0 0
"@,
        @"
1000000 2000000
-3000000 1
"@
    )
    "04" = @(
        @"
3
1 2
3 4
5 6
"@,
        @"
1
-10 7
"@,
        @"
4
0 0
-1 1
100 -100
9 9
"@,
        @"
2
123456 654321
-500000 499999
"@
    )
    "05" = @(
        @"
2
3 1 2 3
4 4 5 6 7
"@,
        @"
3
1 10
5 1 1 1 1 1
2 -5 5
"@,
        @"
2
4 -1 -2 -3 -4
3 0 0 0
"@,
        @"
1
8 100 -50 25 -25 10 -10 1 -1
"@
    )
    "06" = @(
        @"
1 2
3 4
5 6
"@,
        @"
-1 10
0 0
9 -9
"@,
        @"
1000000 1
-1000000 -1
"@,
        @"
7 8
"@
    )
    "07" = @(
        @"
1 2 3
4 5
6
"@,
        @"

1 1 1

2 2
"@,
        @"
10 -10 20 -20 30
0
"@,
        @"
   3    4    5   

-1 -2 -3
"@
    )
    "08" = @(
        @"
1 2
3 4
0 0
"@,
        @"
-1 1
5 5
0 0
9 9
"@,
        @"
0 0
"@,
        @"
100 200
-5 3
7 8
0 0
"@
    )
    "09" = @(
        @"
3
alice 90
bob 80
carol 70
"@,
        @"
1
solo 100
"@,
        @"
4
u1 0
u2 100
u3 50
u4 50
"@,
        @"
2
tom 88.5
jerry 91.5
"@
    )
    "10" = @(
        @"
2 3
1 2 3
4 5 6
"@,
        @"
1 4
10 20 30 40
"@,
        @"
3 2
-1 1
-2 2
-3 3
"@,
        @"
2 2
0 0
0 0
"@
    )
    "11" = @(
        @"
2 2
1 2
3 4
1 3
5 6 7
"@,
        @"
1 1
9
2 1
-1
1
"@,
        @"
3 1
1
2
3
"@,
        @"
2 3
1 1 1
2 2 2
2 2
3 3
4 4
"@
    )
    "12" = @(
        @"
5 4
1 2
2 3
3 4
4 5
"@,
        @"
3 3
1 2
2 3
1 3
"@,
        @"
4 0
"@,
        @"
6 7
1 2
1 3
1 4
2 5
2 6
3 6
4 5
"@
    )
    "13" = @(
        @"
ADD 5
MUL 2
PRINT
END
"@,
        @"
PRINT
ADD 3
PRINT
MUL 10
PRINT
END
"@,
        @"
ADD -2
MUL -3
PRINT
END
"@,
        @"
ADD 1
ADD 2
ADD 3
PRINT
MUL 0
PRINT
END
"@
    )
    "14" = @(
        @"
hello world from cpp
"@,
        @"
   multiple   spaces   here   
"@,
        @"

"@,
        @"
one
"@
    )
    "15" = @(
        @"
I love algorithm practice
"@,
        @"
  too   many   spaces  
"@,
        @"
word
"@,
        @"

"@
    )
    "16" = @(
        @"
3
hello world
acm io
line 3
"@,
        @"
1
single line with spaces
"@,
        @"
2

second line text
"@,
        @"
4
a
b c
   d   
end
"@
    )
    "17" = @(
        @"
a,b,c
"@,
        @"
a,,b,
"@,
        @"
,
"@,
        @"
field1,field2,field3,field4,field5
"@
    )
    "18" = @(
        @"
1
2.345
-6.7
"@,
        @"
0.0049
0.005
"@,
        @"
1000000.9999
-1000000.1111
"@,
        @"
3.1415926
"@
    )
    "19" = @(
        @"
10 2
"@,
        @"
5 0
"@,
        @"
-7 2
"@,
        @"
0 3
"@
    )
    "20" = @(
        @"
3
1 2
3 4
5 6
"@,
        @"
1
100 200
"@,
        @"
2
-1 -2
-3 3
"@,
        @"
4
0 0
9 1
10 -10
7 8
"@
    )
    "21" = @(
        @"
3
1 2
3 4
5 6
"@,
        @"
1
9 9
"@,
        @"
2
-5 5
10 0
"@,
        @"
4
0 0
1 1
2 2
3 3
"@
    )
    "22" = @(
        @"
123
456
"@,
        @"
999999999999999999999999
1
"@,
        @"
0
0
"@,
        @"
1234567890123456789012345678901234567890
9876543210987654321098765432109876543210
"@
    )
    "23" = @(
        @"
1 2 3
4 5
"@,
        @"

  -1   -2
	3	4
"@,
        @"
abc 10 def -20 ghi 30
"@,
        @"
0

   
100   200   -300
"@
    )
    "24" = @(
        @"
4
12:00|INFO|start
12:01|WARN|slow
12:02|INFO|ok
12:03|ERROR|oops
"@,
        @"
3
00:00|DEBUG|a
00:01|DEBUG|b
00:02|DEBUG|c
"@,
        @"
5
1|INFO|x
2|INFO|y
3|WARN|z
4|WARN|w
5|ERROR|e
"@,
        @"
1
23:59|FATAL|down
"@
    )
    "25" = @(
        @"
INT 1 2
FLOAT 3.5 2.0
LINE hello world
"@,
        @"
LINE this is a line with spaces
INT -5 10
FLOAT 1.25 0.75
"@,
        @"
INT 0 0
INT 100 -1
LINE x
"@,
        @"
FLOAT 10 3
LINE trailing spaces test   
FLOAT -7 2
"@
    )
}

foreach ($q in $data.Keys) {
    $dir = Join-Path $root $q
    New-Item -ItemType Directory -Force -Path $dir | Out-Null
    $cases = $data[$q]
    for ($i = 0; $i -lt $cases.Count; $i++) {
        $path = Join-Path $dir (("{0}.in" -f ($i + 1)))
        [System.IO.File]::WriteAllText($path, $cases[$i].TrimStart("`r", "`n") + "`n")
    }
}

Write-Host "Generated test inputs under: $root"
