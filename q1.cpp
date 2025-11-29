#include<iostream>
using namespace std;
#include<vector>
#include<stack>
int main(){
    stack<int> arr;
    //arr = {12,5,8,9};
    arr.push(10);
    arr.push(20);
    arr.push(30);
    arr.push(40);
    arr.push(50);

cout << "size of the stack is : " << arr.size() << endl;

/*for(auto it: arr){    THIS DOES NOT WORK IN STACKS
    cout << it;
}*/

// THIS WILL MAKE THE STACK EMPTY MAKE A COPY IF U DONT WANNA LOSE ELEMENTS
cout << "Stack elements (top to bottom): ";

    while (!arr.empty()) {
        cout << arr.top() << " "; 
        arr.pop();                
    }
    cout << endl;

    return 0;


//COPY

stack<int> temp = arr; 

while (!temp.empty()) {
    cout << temp.top() << " ";
    temp.pop();
}


}
