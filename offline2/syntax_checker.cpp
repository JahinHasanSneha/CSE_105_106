#include <stack>
#include <string>
using namespace std;

/**
 * Helper function to check if an opening bracket matches a closing bracket
 * @param opening: The opening bracket character
 * @param closing: The closing bracket character
 * @return true if they form a matching pair, false otherwise
 */
bool isMatchingPair(char opening, char closing)
{
    // TODO: Implement this helper function
    return (opening == '(' && closing == ')') ||
    (opening == '[' && closing == ']') ||
    (opening == '{' && closing == '}');
    // Check if opening and closing brackets match
    // Valid pairs: (), [], {}
    // Replace this with your implementation
}

/**
 * Checks if brackets in an arithmetic expression are properly matched
 * @param expression: A string containing an arithmetic expression
 * @return true if all brackets are properly matched and balanced, false otherwise
 */
bool isValidExpression(const string &expression)
{
    stack<char> s;
    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
            {
                return false;
            }
            char top = s.top();
            s.pop();
            if (!isMatchingPair(top, ch))
            {
                return false;
            }
        }
        }
    // TODO: Implement the syntax checker using std::stack

    return s.empty(); // Replace this with your implementation
}
