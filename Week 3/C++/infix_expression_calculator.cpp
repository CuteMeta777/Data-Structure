#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void fast_IO() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int get_priority(char op) 
{
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    if (op == '(' || op == ')') return 0;
    return -1;
}

string convert_infix_to_postfix(string infix_expression)
{
    string postfix_expression = "";
    char target;
    stack<char> s;

    for (int i = 0; i < infix_expression.size(); i++)
    {
        target = infix_expression[i];

        // 연산자인 경우
        if (target == '+' || target == '-' || target == '*' || target == '/')
        {
            while (!s.empty() && get_priority(target) <= get_priority(s.top()))
            {
                postfix_expression += s.top();
                s.pop();
            }
            s.push(target);
        }
        // ( 의 경우
        else if (target == '(')
        {
            s.push(target);
        }
        // ) 의 경우
        else if (target == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix_expression += s.top();
                s.pop();
            }
            s.pop();
        }
        // 피연산자인 경우
        else
        {
            postfix_expression += target;
        }
    }

    while (!s.empty())
    {
        postfix_expression += s.top();
        s.pop();
    }

    return postfix_expression;
}

int calculate_postfix(string postfix_expression)
{
    stack<int> s;
    char target;

    for (int i = 0; i < postfix_expression.size(); i++)
    {
        target = postfix_expression[i];

        // 피연산자인 경우
        if (target >= '0' && target <= '9')
        {
            s.push(target - '0');
        }
        // 연산자인 경우
        else
        {
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();

            if (target == '+') s.push(left + right);
            else if (target == '-') s.push(left - right);
            else if (target == '*') s.push(left * right);
            else if (target == '/') s.push(left / right);
        }
    }

    return s.top();
}

int main(void)
{
    fast_IO();

    string infix_expression_input;
    cin >> infix_expression_input;
    
    cout << calculate_postfix(convert_infix_to_postfix(infix_expression_input)) << endl;

    return 0;
}