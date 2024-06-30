/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include <string.h>
#include <stack>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class MinStack {
public:
    stack<pair<int, int>> stk;
    MinStack() {
    }
    
    void push(int val) {
        // 如果栈不为空并且val值不是最小值, 将 val 值和栈顶的最值入栈
        if (!stk.empty() && val > getMin()) {
            stk.push({val, getMin()});
        } else {
            stk.push({val, val});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << "最小值: " << minStack.getMin() << endl;  // 返回 -3
    minStack.pop();
    cout << "栈顶元素: " << minStack.top() << endl;    // 返回 0
    cout << "最小值: " << minStack.getMin() << endl;  // 返回 -2

    return 0;
}
