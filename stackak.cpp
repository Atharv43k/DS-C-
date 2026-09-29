#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;

// Return precedence of operator
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

// Check whether character is an operator
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           ch == '^';
}

// Convert infix to postfix
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        // Operand: A-Z or number
        if (isalnum(ch))
        {
            postfix += ch;
            postfix += ' ';
        }

        // Opening bracket
        else if (ch == '(')
        {
            st.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }

        // Operator
        else if (isOperator(ch))
        {
            while (!st.empty() &&
                   st.top() != '(' &&
                   precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }

            st.push(ch);
        }
    }

    // Empty remaining stack
    while (!st.empty())
    {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    return postfix;
}

// Evaluate postfix
double evaluatePostfix(string postfix, map<char, double> values)
{
    stack<double> st;

    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        char ch = token[0];

        // If token is a variable
        if (isalpha(ch))
        {
            st.push(values[ch]);
        }

        // If token is a number
        else if (isdigit(ch))
        {
            st.push(stod(token));
        }

        // If token is an operator
        else
        {
            double b = st.top();
            st.pop();

            double a = st.top();
            st.pop();

            switch (ch)
            {
                case '+':
                    st.push(a + b);
                    break;

                case '-':
                    st.push(a - b);
                    break;

                case '*':
                    st.push(a * b);
                    break;

                case '/':
                    if (b == 0)
                    {
                        cout << "Error: Division by zero!" << endl;
                        return 0;
                    }
                    st.push(a / b);
                    break;

                case '^':
                    st.push(pow(a, b));
                    break;
            }
        }
    }

    return st.top();
}

int main()
{
    string infix;

    cout << "Enter marks formula: ";
    getline(cin, infix);

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);

    cout << "\nPostfix expression: " << postfix << endl;

    // Store values of variables
    map<char, double> values;

    // Find variables in expression
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        bool found = false;

        for (char c : infix)
        {
            if (c == ch)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "Enter value of " << ch << ": ";
            cin >> values[ch];
        }
    }

    // Evaluate postfix
    double result = evaluatePostfix(postfix, values);

    cout << "\nFinal Result = " << result << endl;

    return 0;
}


