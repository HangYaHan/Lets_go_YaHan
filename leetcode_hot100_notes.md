# LeetCode Hot 100 数据结构与解题思路 + 题目摘要

说明：
- 本文的“题目摘要”是对经典 Hot 100 题意的改写总结，便于复习，不是官方原文。
- 不同年份/页面版本的 Hot 100 题单可能有细微差异，本文按常见经典版组织。

## 1. Hot 100 常用数据结构

1. 数组 Array
- 典型操作：双指针、前缀和、原地标记、滑动窗口。
- 适用信号：连续区间、子数组、原地修改、下标关系。

2. 字符串 String
- 典型操作：双指针回文、分割拼接、状态机、哈希计数。
- 适用信号：子串匹配、回文、字符频次、格式化。

3. 哈希表 HashMap / HashSet
- 典型操作：去重、计数、查补数、记录最早出现位置。
- 适用信号：需要 O(1) 查询、判断存在性、频次统计。

4. 链表 Linked List
- 典型操作：快慢指针、虚拟头结点、反转、归并。
- 适用信号：节点重连、删除倒数第 k 个、环检测。

5. 栈 Stack
- 典型操作：括号匹配、单调栈、表达式处理。
- 适用信号：最近更大/更小、后进先出、括号合法性。

6. 队列 / 双端队列 Queue / Deque
- 典型操作：BFS、单调队列维护窗口最值。
- 适用信号：层序遍历、最短步数、窗口最大值。

7. 二叉树 Binary Tree
- 典型操作：前中后序 DFS、层序 BFS、递归返回信息。
- 适用信号：路径、高度、最近公共祖先、重建树。

8. 堆 Heap / Priority Queue
- 典型操作：Top K、合并 k 路、中位数维护。
- 适用信号：动态最值、实时第 k 大/小。

9. 图 Graph
- 典型操作：BFS/DFS、拓扑排序、并查集。
- 适用信号：连通性、课程依赖、岛屿问题。

10. 并查集 Union-Find
- 典型操作：路径压缩 + 按秩合并。
- 适用信号：动态连通、冗余边、集合合并。

11. Trie（前缀树）
- 典型操作：前缀插入/查询、DFS 回溯剪枝。
- 适用信号：单词搜索、前缀匹配。

12. DP 表（本质是状态数组）
- 典型操作：一维/二维状态转移、滚动优化。
- 适用信号：最优子结构、计数、编辑距离、子序列。

## 2. 高频解题思路（模板化）

1. 双指针
- 对撞型：有序数组求和、盛水容器、三数之和。
- 快慢型：去重、链表找环、移动零。

2. 滑动窗口
- 固定窗口：求窗口最大值。
- 可变窗口：最小覆盖子串、无重复最长子串。

3. 前缀和 + 哈希
- 子数组和等于 k、和为 0 的最长区间。

4. 二分查找
- 在有序空间中找边界：左边界、右边界、答案二分。

5. 回溯
- 子集、组合、全排列、括号生成、N 皇后。

6. 单调栈
- 每个元素找“左/右第一个更大(小)”：柱状图、接雨水。

7. 树形递归
- 定义递归函数含义，后序汇总子树信息。

8. 图搜索
- BFS 求最短步数，DFS 求连通块。

9. 动态规划
- 明确状态定义、转移方程、初始化和遍历顺序。

10. 贪心
- 局部最优推出全局最优：跳跃游戏、买卖股票 II。

## 3. 经典 Hot 100 题目摘要（改写版）

### A. 哈希 / 数组 / 双指针

1. Two Sum（两数之和）
- 给定数组和目标值，找两元素下标使其和等于目标。

2. Group Anagrams（字母异位词分组）
- 把由相同字母重排形成的字符串分到同一组。

3. Longest Consecutive Sequence（最长连续序列）
- 无序数组中求最长连续整数序列长度，要求线性复杂度。

4. Move Zeroes（移动零）
- 保持非零元素相对顺序，把所有 0 移到数组末尾。

5. Container With Most Water（盛最多水的容器）
- 两条竖线与 x 轴构成容器，求可盛水最大面积。

6. 3Sum（三数之和）
- 找出所有和为 0 且不重复的三元组。

7. Trapping Rain Water（接雨水）
- 给柱高数组，求下雨后能接住多少水。

8. Best Time to Buy and Sell Stock（买卖股票的最佳时机）
- 只允许一次买卖，求最大利润。

9. Find All Numbers Disappeared in an Array（找到所有数组中消失的数字）
- 数组元素范围 1..n，找未出现的数字。

10. Subarray Sum Equals K（和为 K 的子数组）
- 统计连续子数组和等于 k 的个数。

11. Sliding Window Maximum（滑动窗口最大值）
- 求每个长度为 k 的窗口中的最大值。

12. Merge Intervals（合并区间）
- 合并所有有交叠的区间。

13. Rotate Array（轮转数组）
- 将数组向右轮转 k 步。

14. Product of Array Except Self（除自身以外数组的乘积）
- 不用除法，返回每个位置除自身外元素乘积。

15. First Missing Positive（缺失的第一个正数）
- 在线性时间、常数额外空间找最小缺失正整数。

16. Set Matrix Zeroes（矩阵置零）
- 若元素为 0，将其所在行列全部置 0，尽量原地。

17. Spiral Matrix（螺旋矩阵）
- 按顺时针螺旋顺序输出矩阵元素。

18. Rotate Image（旋转图像）
- 将 n x n 矩阵原地顺时针旋转 90 度。

19. Search a 2D Matrix II（搜索二维矩阵 II）
- 行列均递增的矩阵中查找目标值是否存在。

20. Sort Colors（颜色分类）
- 仅含 0/1/2 的数组原地排序。

### B. 字符串

21. Longest Substring Without Repeating Characters（无重复字符的最长子串）
- 求不含重复字符的最长连续子串长度。

22. Find All Anagrams in a String（找到字符串中所有字母异位词）
- 找到所有与模式串同字母组成的子串起点。

23. Minimum Window Substring（最小覆盖子串）
- 找最短子串，覆盖目标串所有字符及次数。

24. Valid Anagram（有效的字母异位词）
- 判断两个字符串是否由相同字符频次构成。

25. Valid Parentheses（有效括号）
- 判断括号序列是否合法匹配。

26. Decode String（字符串解码）
- 解码形如 k[encoded_string] 的嵌套表达式。

27. Palindromic Substrings（回文子串）
- 统计字符串中回文子串总数。

28. Longest Palindromic Substring（最长回文子串）
- 找字符串中最长回文子串。

29. Longest Common Subsequence（最长公共子序列）
- 求两个字符串的 LCS 长度。

30. Edit Distance（编辑距离）
- 计算将字符串 A 变为 B 的最少编辑次数。

### C. 链表

31. Reverse Linked List（反转链表）
- 将单链表整体反转。

32. Linked List Cycle（环形链表）
- 判断链表是否存在环。

33. Linked List Cycle II（环形链表 II）
- 若有环，返回入环节点。

34. Merge Two Sorted Lists（合并两个有序链表）
- 合并成一个有序链表。

35. Add Two Numbers（两数相加）
- 两链表逆序表示整数，返回它们和的链表。

36. Remove Nth Node From End of List（删除链表倒数第 N 个结点）
- 删除并返回新链表头。

37. Swap Nodes in Pairs（两两交换链表中的节点）
- 每两个相邻节点交换位置。

38. Reverse Nodes in k-Group（K 个一组翻转链表）
- 每 k 个节点一组翻转，不足 k 保持。

39. Copy List with Random Pointer（随机链表的复制）
- 深拷贝带 random 指针的链表。

40. Sort List（排序链表）
- 在 O(n log n) 时间内对链表排序。

41. Intersection of Two Linked Lists（相交链表）
- 找两单链表的首个相交节点。

42. Palindrome Linked List（回文链表）
- 判断链表值序列是否为回文。

### D. 二叉树

43. Binary Tree Inorder Traversal（二叉树中序遍历）
- 返回中序遍历结果。

44. Validate Binary Search Tree（验证二叉搜索树）
- 判断一棵树是否满足 BST 性质。

45. Symmetric Tree（对称二叉树）
- 判断左右子树是否镜像对称。

46. Maximum Depth of Binary Tree（二叉树最大深度）
- 返回根到最深叶子的层数。

47. Diameter of Binary Tree（二叉树的直径）
- 求任意两节点最长路径长度（边数）。

48. Level Order Traversal（二叉树层序遍历）
- 按层返回节点值。

49. Convert Sorted Array to BST（将有序数组转换为二叉搜索树）
- 构建高度平衡 BST。

50. Flatten Binary Tree to Linked List（二叉树展开为链表）
- 原地按先序顺序展开为右指针链。

51. Path Sum III（路径总和 III）
- 统计路径和等于目标值的路径条数。

52. Binary Tree Maximum Path Sum（二叉树中的最大路径和）
- 求任意起止节点路径和最大值。

53. Construct Binary Tree from Preorder and Inorder Traversal（前序与中序构造二叉树）
- 根据遍历结果重建二叉树。

54. Lowest Common Ancestor of a Binary Tree（二叉树的最近公共祖先）
- 找两个节点最近公共祖先。

55. Kth Smallest Element in a BST（二叉搜索树中第 K 小元素）
- 返回 BST 中第 k 小值。

56. Binary Tree Right Side View（二叉树的右视图）
- 从右侧可见的每层节点。

57. Invert Binary Tree（翻转二叉树）
- 交换每个节点左右子树。

58. Balanced Binary Tree（平衡二叉树）
- 判断每个节点左右子树高度差是否不超过 1。

### E. 图 / 回溯 / 矩阵搜索

59. Number of Islands（岛屿数量）
- 统计网格中由 1 组成的连通块数量。

60. Max Area of Island（岛屿的最大面积）
- 求单个岛屿最大面积。

61. Rotting Oranges（腐烂的橘子）
- 多源扩散，求全部腐烂所需最短分钟数。

62. Course Schedule（课程表）
- 判断先修关系下能否完成全部课程。

63. Course Schedule II（课程表 II）
- 返回可行的课程学习顺序。

64. Trie（实现 Trie 前缀树）
- 实现插入、查词、查前缀。

65. Word Search（单词搜索）
- 矩阵中按相邻格回溯匹配目标单词。

66. Word Break（单词拆分）
- 判断字符串能否由词典单词拼接而成。

67. Letter Combinations of a Phone Number（电话号码的字母组合）
- 根据数字按键映射生成全部组合。

68. Generate Parentheses（括号生成）
- 生成 n 对括号的所有合法组合。

69. Combination Sum（组合总和）
- 候选数可重复选，找和为目标的组合。

70. Permutations（全排列）
- 返回数组所有排列。

71. Subsets（子集）
- 返回集合全部子集。

72. N-Queens（N 皇后）
- 放置 n 个皇后使其互不攻击，返回方案。

73. Search in Rotated Sorted Array（搜索旋转排序数组）
- 在旋转有序数组中 O(log n) 查目标。

74. Find Minimum in Rotated Sorted Array（寻找旋转排序数组中的最小值）
- 旋转后数组找最小元素。

75. Search Insert Position（搜索插入位置）
- 有序数组中找目标下标或应插入位置。

### F. 栈 / 堆 / 频次

76. Min Stack（最小栈）
- 支持 push/pop/top 且能 O(1) 取最小值。

77. Daily Temperatures（每日温度）
- 对每一天，求下一个更高温度要等几天。

78. Largest Rectangle in Histogram（柱状图中最大的矩形）
- 求柱状图最大矩形面积。

79. Top K Frequent Elements（前 K 个高频元素）
- 返回出现频率最高的 k 个元素。

80. Find Median from Data Stream（数据流的中位数）
- 动态插入数字并实时查询中位数。

81. Kth Largest Element in an Array（数组中的第 K 个最大元素）
- 返回无序数组第 k 大元素。

82. Merge k Sorted Lists（合并 K 个升序链表）
- 合并成一个升序链表。

### G. 动态规划

83. Climbing Stairs（爬楼梯）
- 每次爬 1 或 2 阶，求到顶方案数。

84. Pascal's Triangle（杨辉三角）
- 生成前 numRows 行。

85. House Robber（打家劫舍）
- 相邻房屋不能同时偷，求最大金额。

86. House Robber II（打家劫舍 II）
- 房屋成环，求最大金额。

87. Unique Paths（不同路径）
- 网格从左上到右下的路径总数。

88. Minimum Path Sum（最小路径和）
- 网格中到右下角路径和最小值。

89. Partition Equal Subset Sum（分割等和子集）
- 判断能否分成和相等的两个子集。

90. Coin Change（零钱兑换）
- 用给定硬币凑目标金额，最少硬币数。

91. Perfect Squares（完全平方数）
- 用最少完全平方数和表示 n。

92. Integer Break（整数拆分）
- 将 n 拆成至少两数之和，乘积最大。

93. Maximum Product Subarray（乘积最大子数组）
- 求连续子数组乘积最大值。

94. Longest Increasing Subsequence（最长递增子序列）
- 求严格递增子序列最大长度。

95. Maximum Subarray（最大子数组和）
- 求连续子数组和最大值。

96. Jump Game（跳跃游戏）
- 判断能否跳到最后一个位置。

97. Jump Game II（跳跃游戏 II）
- 求到达末尾最少跳跃次数。

98. Target Sum（目标和）
- 给每个数加正负号，使表达式值为目标，求方案数。

99. Distinct Subsequences（不同的子序列）
- 统计字符串 s 中等于 t 的子序列个数。

100. Regular Expression Matching（正则表达式匹配）
- 支持 '.' 和 '*'，判断字符串是否完全匹配模式。

## 4. 复习顺序建议（高效版）

1. 第一轮（建立模板）
- 哈希 + 双指针 + 滑窗：两数之和、三数之和、无重复子串、最小覆盖。
- 链表：反转、环检测、删除倒数第 N。
- 树：前中后序、层序、LCA。

2. 第二轮（提升难度）
- 单调栈：接雨水、每日温度、柱状图最大矩形。
- 回溯：子集、排列、组合总和、N 皇后。
- 图：岛屿数量、课程表。

3. 第三轮（DP 专项）
- 线性 DP：打家劫舍、最大子数组、LIS。
- 背包 DP：零钱兑换、分割等和子集、目标和。
- 字符串 DP：编辑距离、最长公共子序列、正则匹配。

## 5. 一句话方法论

- 先认题型，再套模板，再做边界。
- 能降维就降维，能剪枝就剪枝。
- 复杂题先写状态定义，再写转移。
- 写完先用极小样例手推一遍。
