#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp){
    stack<char> pt;

    for(char ch:exp){
        if(ch=='{' || ch=='(' || ch=='['){
            pt.push(ch);
        }
        else if(ch=='}' || ch==')' || ch==']'){
            if(pt.empty()){
                return false;
            }
            char top=pt.top();
            pt.pop();

            if(ch=='}' && top!='{' || ch==')' && top!='(' || ch==']' && top!='['){
                return false;
            }
        }
    }
    return pt.empty();
}

int main(){

    string word;
    stack<char> pt;

    cout<<"Enter the expression: ";
    cin>> word;

    bool balanced=isBalanced(word);

    if(balanced){
        cout<<"The expression is balnced";
    }
    else{   
        cout<<"Expression is not balanced";
    }

    return 0;
}