#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;


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
    stack<int> st;

    for(char c:expression){

        if(isdigit(c)){
            st.push(c-'0');
        }

        else if(isOperator(c)){
            int num1= st.top();
            st.pop();
            int num2= st.top();
            st.pop();

            if(c=='+'){
                st.push(num2+num1);
            }
            else if(c=='-'){
                st.push(num2-num1);
            }
            else if(c=='*'){
                st.push(num2*num1);
            }
            else if(c=='/'){
                st.push(num2/num1);
            }
            else if(c=='^'){
                st.push(pow(num2,num1));
            }
        }
    }
    int result=st.top();
    st.pop();
    if(!st.empty()){
        cout<<"Error!";
    }
    cout<<"Result: "<<result;

    return 0;
}