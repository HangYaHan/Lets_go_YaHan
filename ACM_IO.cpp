#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

// ACM 输入输出模式专项练习（仅题目注释，无代码）
// 使用建议：每次选择 1 题，在本文件下方自行实现并删除实现后继续下一题。
// 目标：覆盖实习面试里常见的所有输入输出组织方式与坑位。
// 批改命令： .\tests\judge.ps1 -Problem 0X -Compile

// ------------------------------------------------------------
// 01. 固定字段（单组）
// 输入：一行两个整数 a, b
// 输出：a + b
// 要点：最基础 cin/cout

// int main()
// {
//     int a, b;
//     std::cin >> a >> b;
//     std::cout << (a + b);
// }

// 02. 固定字段（混合类型）
// 输入：一行，依次为 int x, double y, string z
// 输出：按 "x y(保留2位) z" 输出
// 要点：fixed + setprecision

// int main()
// {
//     int x;
//     double y;
//     std::string z;
//     std::cin >> x >> y >> z;
//     std::cout << x << " " << std::fixed << std::setprecision(2) << y << " " << z;
// }

// 03. 固定多行
// 输入：两行，每行两个整数
// 输出：每行的和，各占一行
// 要点：多行输入映射多行输出

// int main()
// {
//     int a1, b1, a2, b2;
//     std::cin >> a1 >> b1 >> a2 >> b2;
//     std::cout << (a1 + b1) << "\n"
//               << (a2 + b2);
// }

// 04. T 组测试
// 输入：第一行 T，后续 T 行每行两个整数
// 输出：每组输出一行和
// 要点：for/while 循环次数准确

// int main()
// {
//     int T;
//     std::cin >> T;
//     for (int i = 0; i < T; ++i)
//     {
//         int a, b;
//         std::cin >> a >> b;
//         std::cout << (a + b) << "\n";
//     }
// }

// int main()
// {
//     int T;
//     std::cin >> T;

//     std::vector<int> ans;
//     ans.reserve(T);

//     for (int i = 0; i < T; ++i)
//     {
//         int a, b;
//         std::cin >> a >> b;
//         ans.push_back(a + b); // 先收集结果
//     }

//     for (int i = 0; i < T; ++i)
//     {
//         if (i)
//             std::cout << '\n'; // 避免最后多一行空白
//         std::cout << ans[i];
//     }
// }

// 05. T 组 + 组内变长
// 输入：第一行 T；每组先给 n，再给 n 个整数
// 输出：每组元素总和
// 要点：嵌套循环

// int main()
// {
//     int T;
//     std::cin >> T;

//     for (int i = 0; i < T; ++i)
//     {
//         int n;
//         std::cin >> n;

//         long long sum = 0;
//         for (int j = 0; j < n; ++j)
//         {
//             int x;
//             std::cin >> x;
//             sum += x;
//         }

//         std::cout << sum;
//         if (i + 1 < T)
//         {
//             std::cout << "\n";
//         }
//     }
// }

// int main()
// {
//     int T;
//     std::cin >> T;

//     std::vector<long long> results;
//     results.reserve(T);

//     for (int i = 0; i < T; ++i)
//     {
//         int n;
//         std::cin >> n;

//         long long sum = 0;
//         for (int j = 0; j < n; ++j)
//         {
//             int x;
//             std::cin >> x;
//             sum += x;
//         }

//         results.push_back(sum); // 先保存每组答案
//     }

//     for (int i = 0; i < T; ++i)
//     {
//         if (i > 0)
//         {
//             std::cout << '\n';
//         }
//         std::cout << results[i]; // 最后统一输出
//     }

//     return 0;
// }

// 06. EOF 连续读取（定长）
// 输入：若干行，每行两个整数，直到 EOF
// 输出：每行和
// 要点：while (cin >> a >> b)

// int main()
// {
//     int a, b;
//     while (std::cin >> a >> b)
//     {
//         std::cout << a + b << '\n';
//     }
// }

// 07. EOF 连续读取（每行不定长）
// 输入：若干行，每行有不定个整数，直到 EOF
// 输出：每行的和（空行输出 0）
// 要点：getline + stringstream

// int main()
// {
//     std::string line;
//     while (std::getline(std::cin, line))
//     {
//         std::istringstream iss(line);
//         int sum = 0, x;
//         while (iss >> x)
//         {
//             sum += x;
//         }
//         std::cout << sum << '\n';
//     }
// }

// 08. 哨兵结束
// 输入：若干行两个整数，遇到 "0 0" 结束
// 输出：终止行之前每行和
// 要点：先判终止再输出

// int main()
// {
//     int a, b;
//     while (std::cin >> a >> b)
//     {
//         if (a == 0 && b == 0)
//         {
//             break; // 遇到哨兵值，结束循环
//         }
//         std::cout << a + b << '\n'; // 输出当前行的和
//     }
//     return 0;
// }

// 09. 记录型输入
// 输入：第一行 n，后续 n 行：name score
// 输出：平均分（保留 2 位）
// 要点：字符串与数字混合读取

// int main()
// {
//     int n;
//     std::cin >> n;

//     double totalScore = 0.0;
//     for (int i = 0; i < n; ++i)
//     {
//         std::string name;
//         double score;
//         std::cin >> name >> score; // 先读字符串再读数字
//         totalScore += score;       // 累加分数
//     }

//     double average = (n > 0) ? (totalScore / n) : 0.0;          // 避免除以零
//     std::cout << std::fixed << std::setprecision(2) << average; // 输出平均分，保留两位小数

//     return 0;
// }

// 10. 矩阵输入
// 输入：n m，后接 n 行 m 列整数
// 输出：每行和
// 要点：双层循环

// int main()
// {
//     int n, m;
//     std::cin >> n >> m;

//     for (int i = 0; i < n; ++i)
//     {
//         int rowSum = 0;
//         for (int j = 0; j < m; ++j)
//         {
//             int x;
//             std::cin >> x;
//             rowSum += x; // 累加当前行的元素
//         }
//         std::cout << rowSum << '\n'; // 输出当前行的和
//     }

//     return 0;
// }

// 11. 多组矩阵（EOF）
// 输入：多组 n m + n*m 数据，直到 EOF
// 输出：每组输出矩阵总和
// 要点：每组状态重置

// int main()
// {
//     int n, m;
//     while (std::cin >> n >> m)
//     {
//         long long matrixSum = 0; // 使用 long long 防止溢出
//         for (int i = 0; i < n; ++i)
//         {
//             for (int j = 0; j < m; ++j)
//             {
//                 int x;
//                 std::cin >> x;
//                 matrixSum += x; // 累加当前矩阵的元素
//             }
//         }
//         std::cout << matrixSum << '\n'; // 输出当前矩阵的总和
//     }

//     return 0;
// }

// 12. 图边列表
// 输入：n m，后接 m 条边 u v（无向图）
// 输出：1..n 每个点度数
// 要点：数组初始化与下标范围

// int main()
// {
//     int n, m;
//     std::cin >> n >> m;

//     std::vector<int> degree(n + 1, 0); // 使用 n+1 大小，1-based indexing

//     for (int i = 0; i < m; ++i)
//     {
//         int u, v;
//         std::cin >> u >> v;
//         degree[u]++; // 增加 u 的度数
//         degree[v]++; // 增加 v 的度数
//     }

//     for (int i = 1; i <= n; ++i)
//     {
//         std::cout << degree[i] << '\n'; // 输出每个点的度数
//     }

//     return 0;
// }

// 13. 命令流解析
// 输入：多行命令（ADD x / MUL x / PRINT / END）
// 输出：每次 PRINT 输出当前值
// 要点：字符串分支解析

// int main()
// {
//     std::string command;
//     long long value = 0; // 使用 long long 防止溢出

//     while (std::cin >> command)
//     {
//         if (command == "END")
//         {
//             break; // 遇到 END 命令，结束循环
//         }
//         else if (command == "ADD")
//         {
//             long long x;
//             std::cin >> x; // 读取 ADD 后的数值
//             value += x;    // 执行加法操作
//         }
//         else if (command == "MUL")
//         {
//             long long x;
//             std::cin >> x; // 读取 MUL 后的数值
//             value *= x;    // 执行乘法操作
//         }
//         else if (command == "PRINT")
//         {
//             std::cout << value << '\n'; // 输出当前值
//         }
//     }

//     return 0;
// }

// 14. 整行文本统计
// 输入：一整行文本（含空格）
// 输出：单词个数
// 要点：连续空格处理

// int main()
// {
//     std::string line;
//     std::getline(std::cin, line); // 读取整行文本

//     std::istringstream iss(line);
//     int wordCount = 0;
//     std::string word;

//     while (iss >> word) // 使用流提取单词，自动跳过空格
//     {
//         wordCount++; // 每成功提取一个单词，计数器加一
//     }

//     std::cout << wordCount; // 输出单词个数

//     return 0;
// }

// 15. 单词反转
// 输入：一整行文本
// 输出：反转单词顺序，单词间仅一个空格
// 要点：标准化空白

// int main()
// {
//     std::string line;
//     std::getline(std::cin, line); // 读取整行文本

//     std::istringstream iss(line);
//     std::vector<std::string> words;
//     std::string word;

//     while (iss >> word) // 提取单词，自动跳过多余空格
//     {
//         words.push_back(word); // 将单词存储在向量中
//     }

//     // 反转单词顺序并输出
//     for (int i = static_cast<int>(words.size()) - 1; i >= 0; --i)
//     {
//         std::cout << words[i]; // 输出当前单词
//         if (i > 0)
//         {
//             std::cout << ' '; // 在单词之间添加一个空格，但最后一个单词后不添加
//         }
//     }

//     return 0;
// }

// 16. cin + getline 混用
// 输入：先给 n，再给 n 行句子（可含空格）
// 输出：原样逐行输出
// 要点：处理残留换行

// int main()
// {
//     int n;
//     std::cin >> n;
//     std::cin.ignore(); // 忽略 n 后的换行符

//     for (int i = 0; i < n; ++i)
//     {
//         std::string sentence;
//         std::getline(std::cin, sentence); // 读取整行句子
//         std::cout << sentence << '\n';    // 原样输出
//     }

//     return 0;
// }

// 17. 分隔符解析（CSV 简化）
// 输入：一行 "a,b,c,..."（无引号）
// 输出：字段个数
// 要点：末尾空字段与连续逗号

// int main()
// {
//     std::string line;
//     std::getline(std::cin, line); // 读取整行输入

//     int fieldCount = 0;
//     std::istringstream iss(line);
//     std::string field;

//     while (std::getline(iss, field, ',')) // 使用逗号作为分隔符提取字段
//     {
//         fieldCount++; // 每成功提取一个字段，计数器加一
//     }

//     std::cout << fieldCount; // 输出字段个数

//     return 0;
// }

// 18. 浮点 EOF
// 输入：若干浮点数直到 EOF
// 输出：每个数保留 2 位小数
// 要点：浮点格式一致性

// int main()
// {
//     double x;
//     while (std::cin >> x) // 读取浮点数直到 EOF
//     {
//         std::cout << std::fixed << std::setprecision(2) << x << '\n'; // 输出每个数，保留两位小数
//     }
//     return 0;
// }

// 19. 异常分支
// 输入：a b（浮点）
// 输出：a/b（保留 6 位）；若 b=0 输出 "Error"
// 要点：分母为零判断

// int main()
// {
//     double a, b;
//     std::cin >> a >> b;

//     if (b == 0)
//     {
//         std::cout << "Error"; // 分母为零时输出错误信息
//     }
//     else
//     {
//         double result = a / b;                                     // 执行除法运算
//         std::cout << std::fixed << std::setprecision(6) << result; // 输出结果，保留6位小数
//     }

//     return 0;
// }

// 20. Case 格式
// 输入：T 组，每组两个整数
// 输出："Case i: ans"
// 要点：编号从 1 开始

// int main()
// {
//     int T;
//     std::cin >> T;

//     for (int i = 1; i <= T; ++i) // 从 1 开始编号
//     {
//         int a, b;
//         std::cin >> a >> b;
//         std::cout << "Case " << i << ": " << (a + b) << '\n'; // 输出格式化结果
//     }

//     return 0;
// }

// 21. 组间空行控制
// 输入：T 组数据
// 输出：组与组之间空一行，最后一组后不额外空行
// 要点：避免尾部多空行

// int main()
// {
//     int T;
//     std::cin >> T;

//     for (int i = 0; i < T; ++i)
//     {
//         int a, b;
//         std::cin >> a >> b;
//         std::cout << (a + b); // 输出当前组的结果

//         if (i + 1 < T) // 如果不是最后一组，输出一个空行
//         {
//             std::cout << '\n';
//         }
//     }

//     return 0;
// }

// 22. 超长整数相加
// 输入：两个非负整数字符串（长度可到 10000）
// 输出：它们的和
// 要点：字符串模拟加法

// int main()
// {
//     std::string num1, num2;
//     std::cin >> num1 >> num2;

//     // 确保 num1 是较长的那个
//     if (num1.length() < num2.length())
//     {
//         std::swap(num1, num2);
//     }

//     std::string result;
//     int carry = 0;
//     int i = static_cast<int>(num1.length()) - 1;
//     int j = static_cast<int>(num2.length()) - 1;

//     while (i >= 0 || j >= 0 || carry > 0)
//     {
//         int digit1 = (i >= 0) ? (num1[i] - '0') : 0; // 从 num1 获取当前位数字
//         int digit2 = (j >= 0) ? (num2[j] - '0') : 0; // 从 num2 获取当前位数字

//         int sum = digit1 + digit2 + carry;  // 当前位的和
//         carry = sum / 10;                   // 更新进位
//         result.push_back((sum % 10) + '0'); // 将当前位结果添加到结果字符串中

//         --i; // 移动到下一位
//         --j;
//     }

//     std::reverse(result.begin(), result.end()); // 反转结果字符串得到正确顺序
//     std::cout << result;                        // 输出最终结果

//     return 0;
// }

// 23. 脏输入鲁棒性
// 输入：可能含多个空格、空行、TAB 的文本
// 输出：所有整数的个数
// 要点：空白字符统一处理

// int main()
// {
//     std::string line;
//     int integerCount = 0;

//     while (std::getline(std::cin, line)) // 逐行读取输入
//     {
//         std::istringstream iss(line);
//         std::string token;

//         while (iss >> token) // 提取每个非空白的 token
//         {
//             try
//             {
//                 std::stoi(token); // 尝试将 token 转换为整数
//                 integerCount++;   // 成功转换则计数器加一
//             }
//             catch (const std::invalid_argument &)
//             {
//                 // 如果转换失败，说明 token 不是整数，忽略它
//             }
//         }
//     }

//     std::cout << integerCount; // 输出整数的总个数

//     return 0;
// }

// 24. 日志行解析
// 输入：n 行日志，格式 "time|level|message"
// 输出：各 level 出现次数
// 要点：多分隔段提取

// int main()
// {
//     int n;
//     std::cin >> n;
//     std::cin.ignore(); // 忽略剩余的换行符

//     std::unordered_map<std::string, int> levelCount; // 统计日志级别出现次数

//     for (int i = 0; i < n; ++i)
//     {
//         std::string logLine;
//         std::getline(std::cin, logLine); // 读取整行日志

//         size_t firstPipe = logLine.find('|');
//         size_t secondPipe = logLine.find('|', firstPipe + 1);

//         if (firstPipe != std::string::npos && secondPipe != std::string::npos)
//         {
//             std::string level = logLine.substr(firstPipe + 1, secondPipe - firstPipe - 1); // 提取日志级别
//             levelCount[level]++;                                                           // 增加对应级别的计数
//         }
//     }

//     for (const auto &pair : levelCount)
//     {
//         std::cout << pair.first << ": " << pair.second << '\n'; // 输出每个级别及其出现次数
//     }

//     return 0;
// }

// 25. 综合协议输入
// 输入：多组，首字段为类型标记（INT/FLOAT/LINE）
// 输出：按类型执行对应解析并输出
// 要点：状态切换与多模式兼容

// int main()
// {
//     std::string type;
//     while (std::cin >> type)
//     {
//         if (type == "INT")
//         {
//             int x;
//             std::cin >> x;
//             std::cout << "Integer: " << x << '\n';
//         }
//         else if (type == "FLOAT")
//         {
//             double y;
//             std::cin >> y;
//             std::cout << "Float: " << std::fixed << std::setprecision(2) << y << '\n';
//         }
//         else if (type == "LINE")
//         {
//             std::cin.ignore(); // 忽略类型标记后的换行符
//             std::string line;
//             std::getline(std::cin, line);
//             std::cout << "Line: " << line << '\n';
//         }
//     }

//     return 0;
// }

// ------------------------------------------------------------
// 自测清单（每题至少覆盖）
// 1) 正常样例
// 2) 边界样例（0、负数、空行、最小规模）
// 3) 格式样例（多空格、末尾无换行、额外空白）
// 4) 输出严格匹配（无多余空格/换行）
