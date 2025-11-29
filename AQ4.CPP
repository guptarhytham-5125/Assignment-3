#include <iostream>
#include <stack>
#include <string>
using namespace std;

int checkPrecedence(char c){
    if(c=='+'||c=='-'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='^'){
        return 3;
    }
    else{
        return 0;
    }
}

bool isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    
    string expression;
    cout<<"Enter the expression: ";
    cin>>expression;

    string result;
    stack<char> st;

    for (char c:expression){

        if(isdigit(c)){
            result+=c;
        }

        else if(isalpha(c)){
            result+=c;
        }

        else if(isOperator(c)){
            int precExperession=checkPrecedence(c);
            int precStack=checkPrecedence(st.top());

            while (!st.empty() && precExperession<=precStack){
                result+=st.top();
                st.pop();
                precExperession=checkPrecedence(c);
                precStack=checkPrecedence(st.top());
            }
            st.push(c);
        }

        else if(c=='('){
            st.push(c);
        }

        else if(c==')'){
            while(st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            cout<<"Error!";
        }

    }
    cout<<result;

    return 0;
}