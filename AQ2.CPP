#include <iostream>
#include <stack>
using namespace std;

int main(){

    string word;
    stack<char> reverseWord;

    cout<<"Enter the string you want to reverse: ";
    cin>>word;

    for(char ch:word){
        reverseWord.push(ch);
    }

    cout<<"Reversed string: ";
    while(!reverseWord.empty()){
        cout<<reverseWord.top();
        reverseWord.pop();
    }

    return 0;
}
