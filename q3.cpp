#include<iostream>
#include<stack>
using namespace std;
void balancedParentheses(string str){
    stack<char> ch;

    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            ch.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            // No opening bracket available
            if (ch.empty()) {
                cout << "Not Balanced\n";
                return;
            }

            char top = ch.top();
            bool mismatch =
                (c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[');

            if (mismatch) {
                cout << "Not Balanced\n";
                return;
            }

            ch.pop(); // matched pair removed
        }
        // else: ignore non-bracket characters (letters, digits, operators, etc.)
    }

    if (ch.empty())
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}

/*while (temp.size()>1)
{
    temp.pop();
}
if (temp.top()==ch.top())
cout << "balancedParentheses";


}*/

int main(){

string x ="({abvdbfvbnsovv])";

 balancedParentheses(x);

return 0;
}