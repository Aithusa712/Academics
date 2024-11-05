#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to perform arithmetic operations
float applyOp(float a, float b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        throw invalid_argument("Invalid operator");
    }
}

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to evaluate infix arithmetic expression and return result as float
float evaluateInfix(const string& expression)
{
    stack<float> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ')
        {
            continue;
        }
        else if (isdigit(expression[i]))
        {
            // Read number
            float num = 0;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.'))
            {
                if (expression[i] == '.')
                {
                    float decimal = 0.1;
                    i++;
                    while (i < expression.length() && isdigit(expression[i]))
                    {
                        num = num + (expression[i] - '0') * decimal;
                        decimal /= 10;
                        i++;
                    }
                }
                else
                {
                    num = num * 10 + (expression[i] - '0');
                    i++;
                }
            }
            values.push(num);
            i--; // Move back one position to handle the increment in the loop
        }
        else if (isOperator(expression[i]))
        {
            // Process operator
            while (!operators.empty() && (operators.top() != '(') &&
                    (precedence(operators.top()) >= precedence(expression[i])))
            {
                char op = operators.top();
                operators.pop();
                float b = values.top();
                values.pop();
                float a = values.top();
                values.pop();
                values.push(applyOp(a, b, op));
            }
            operators.push(expression[i]);
        }
        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                char op = operators.top();
                operators.pop();
                float b = values.top();
                values.pop();
                float a = values.top();
                values.pop();
                values.push(applyOp(a, b, op));
            }
            operators.pop(); // Pop '('
        }
        else
        {
            throw invalid_argument("Invalid character in expression");
        }
    }

    // Process remaining operators in the stack
    while (!operators.empty())
    {
        char op = operators.top();
        operators.pop();
        float b = values.top();
        values.pop();
        float a = values.top();
        values.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

int main()
{
    string expression;

    // Get user input for infix expression
    cout << "Enter an infix arithmetic expression (e.g., 3 + 4 * 2 - 1): ";
    getline(cin, expression);

    try
    {
        float result = evaluateInfix(expression);
        cout << "Result: " << result << endl;
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
