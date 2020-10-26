/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start

#include <stack>
#include <string>
using namespace std;

// 可使用栈处理优先级
class Solution
{
public:
    int calculate(string s)
    {
        static const int STATE_BEGIN = 0;
        static const int NUMBER_STATE = 1;
        static const int OPERATION_STATE = 2;
        stack<int> number_stack;
        stack<char> operation_stack;
        int number = 0;
        int compute_flag = 0;
        int STATE = STATE_BEGIN;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            switch (STATE)
            {
            case STATE_BEGIN:
                if (s[i] >= '0' && s[i] <= '9')
                {
                    STATE = NUMBER_STATE;
                }
                else
                {
                    STATE = OPERATION_STATE;
                }
                i--;
                break;
            case NUMBER_STATE:
                if (s[i] >= '0' && s[i] <= '9')
                {
                    number = number * 10 + s[i] - '0';
                }
                else
                {
                    number_stack.push(number);
                    if (compute_flag == 1)
                    {
                        compute(number_stack, operation_stack);
                    }
                    number = 0;
                    i--;
                    STATE = OPERATION_STATE;
                }
                break;
            case OPERATION_STATE:
                if (s[i] == '+' || s[i] == '-')
                {
                    operation_stack.push(s[i]);
                    compute_flag = 1;
                }
                else if (s[i] == '(')
                {
                    //
                    compute_flag = 0;
                }
                else if (s[i] >= '0' && s[i] <= '9')
                {
                    STATE = NUMBER_STATE;
                    i--;
                }
                else if (s[i] == ')')
                {
                    compute(number_stack, operation_stack);
                }
                break;
            default:
                break;
            }
        }
        if (number != 0)
        {
            number_stack.push(number);
            compute(number_stack, operation_stack);
        }
        if (number == 0 && number_stack.empty())
        {
            return 0;
        }
        return number_stack.top();
    }

    void compute(stack<int> &numberStack, stack<char> &operationStack)
    {
        if (numberStack.size() < 2)
        {
            return; // 处理特殊数据 如“1235”
        }
        int num2 = numberStack.top();
        numberStack.pop();
        int num1 = numberStack.top();
        numberStack.pop();
        if (operationStack.top() == '+')
        { 
            numberStack.push(num1 + num2);
        }
        if (operationStack.top() == '-')
        {
            numberStack.push(num1 - num2);
        }
        operationStack.pop();
    }
};

// @lc code=end
