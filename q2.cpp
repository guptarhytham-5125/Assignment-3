#include<iostream>
#include<stack>
using namespace std;
 
void reverseUsingStack(string str){
    stack<char> ch;

  for (char c : str) {
        ch.push(c);
    }

  while (!ch.empty())
  {
    cout << ch.top();

   ch.pop();
  }

}

int main(){
string x ="DataStructure";
reverseUsingStack(x);


return 0;
}