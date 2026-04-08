#include <iostream>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void printVector(const vector<int> &v, const string &name)
{
    cout << name << " = [";
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << (i + 1 == v.size() ? "" : ", ");
    }
    cout << "]\n";
}

void demoVectorBasics()
{
    cout << "===== vector common member functions =====\n";

    vector<int> nums = {1, 2, 3};
    printVector(nums, "Initial nums");

    cout << "size(): " << nums.size() << "\n";
    cout << "empty(): " << (nums.empty() ? "true" : "false") << "\n";

    nums.push_back(4);
    nums.emplace_back(5);
    printVector(nums, "After push_back / emplace_back");

    cout << "front(): " << nums.front() << ", back(): " << nums.back() << "\n";
    cout << "at(2): " << nums.at(2) << ", operator[](2): " << nums[2] << "\n";

    nums.insert(nums.begin() + 1, 99);
    printVector(nums, "After insert(pos, val)");

    nums.erase(nums.begin() + 1);
    printVector(nums, "After erase(pos)");

    nums.pop_back();
    printVector(nums, "After pop_back()");

    nums.resize(7, 0);
    printVector(nums, "After resize(7, 0)");

    nums.assign(4, 8);
    printVector(nums, "After assign(4, 8)");

    nums.clear();
    cout << "After clear(), size = " << nums.size()
         << ", empty = " << (nums.empty() ? "true" : "false") << "\n\n";
}

void demoStringBasics()
{
    cout << "===== string common member functions =====\n";

    string s = "leetcode";
    cout << "Initial s: " << s << "\n";

    cout << "size(): " << s.size() << ", empty(): " << (s.empty() ? "true" : "false") << "\n";
    cout << "front(): " << s.front() << ", back(): " << s.back() << "\n";
    cout << "at(3): " << s.at(3) << ", operator[](3): " << s[3] << "\n";

    s.push_back('!');
    cout << "After push_back('!'): " << s << "\n";

    s.pop_back();
    cout << "After pop_back(): " << s << "\n";

    s.append("-practice");
    cout << "After append(\"-practice\"): " << s << "\n";

    s.insert(8, "-");
    cout << "After insert(pos, str): " << s << "\n";

    s.erase(8, 1);
    cout << "After erase(pos, len): " << s << "\n";

    s.replace(0, 4, "code");
    cout << "After replace(pos, len, str): " << s << "\n";

    string part = s.substr(0, 4);
    cout << "substr(0, 4): " << part << "\n";

    size_t idx = s.find("practice");
    cout << "find(\"practice\"): "
         << (idx == string::npos ? -1 : static_cast<int>(idx)) << "\n";

    s.clear();
    cout << "After clear(), size = " << s.size()
         << ", empty = " << (s.empty() ? "true" : "false") << "\n\n";
}

void demoStackQueueDeque()
{
    cout << "===== stack / queue / deque =====\n";

    stack<int> st;
    st.push(10);
    st.push(20);
    cout << "stack top(): " << st.top() << ", size(): " << st.size() << "\n";
    st.pop();
    cout << "stack after pop, top(): " << st.top()
         << ", empty(): " << (st.empty() ? "true" : "false") << "\n";

    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);
    cout << "queue front(): " << q.front() << ", back(): " << q.back() << "\n";
    q.pop();
    cout << "queue after pop, front(): " << q.front() << ", size(): " << q.size() << "\n";

    deque<int> dq = {5, 6, 7};
    dq.push_front(4);
    dq.push_back(8);
    cout << "deque front(): " << dq.front() << ", back(): " << dq.back() << "\n";
    dq.pop_front();
    dq.pop_back();
    dq.insert(dq.begin() + 1, 99);
    dq.erase(dq.begin() + 1);
    cout << "deque at(1): " << dq.at(1) << ", size(): " << dq.size() << "\n\n";
}

void demoSetAndMap()
{
    cout << "===== set / map (ordered) =====\n";

    set<int> s = {3, 1, 2};
    s.insert(2);
    s.insert(4);
    cout << "set size(): " << s.size() << ", count(2): " << s.count(2)
         << ", count(8): " << s.count(8) << "\n";
    s.erase(1);
    auto sit = s.find(3);
    cout << "set find(3): " << (sit != s.end() ? "found" : "not found") << "\n";

    map<string, int> mp;
    mp["apple"] = 2;
    mp.insert({"banana", 5});
    mp["banana"]++;
    cout << "map[\"banana\"]: " << mp["banana"] << ", size(): " << mp.size() << "\n";
    cout << "map count(\"apple\"): " << mp.count("apple") << "\n";
    mp.erase("apple");
    cout << "after erase(\"apple\"), count: " << mp.count("apple") << "\n\n";
}

void demoUnorderedSetAndMap()
{
    cout << "===== unordered_set / unordered_map =====\n";

    unordered_set<int> us = {10, 20, 30};
    us.insert(20);
    us.insert(40);
    cout << "unordered_set size(): " << us.size() << ", count(20): " << us.count(20) << "\n";
    us.erase(10);
    cout << "after erase(10), count(10): " << us.count(10) << "\n";

    unordered_map<string, int> ump;
    ump["a"] = 1;
    ump["b"] = 2;
    ump["b"] += 3;
    cout << "unordered_map[\"b\"]: " << ump["b"] << ", size(): " << ump.size() << "\n";
    auto it = ump.find("a");
    cout << "find(\"a\"): " << (it != ump.end() ? "found" : "not found") << "\n";
    ump.erase("a");
    cout << "after erase(\"a\"), count(\"a\"): " << ump.count("a") << "\n\n";
}

void demoPriorityQueue()
{
    cout << "===== priority_queue =====\n";

    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(5);
    cout << "maxHeap top(): " << maxHeap.top() << ", size(): " << maxHeap.size() << "\n";
    maxHeap.pop();
    cout << "maxHeap after pop, top(): " << maxHeap.top() << "\n";

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(5);
    cout << "minHeap top(): " << minHeap.top() << ", empty(): "
         << (minHeap.empty() ? "true" : "false") << "\n\n";
}

int main()
{
    demoVectorBasics();
    demoStringBasics();
    demoStackQueueDeque();
    demoSetAndMap();
    demoUnorderedSetAndMap();
    demoPriorityQueue();
    return 0;
}