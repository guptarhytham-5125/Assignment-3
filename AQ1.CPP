#include <iostream>
using namespace std;

int main(){

    cout<<"Enter the size of Array: ";
    int size;
    cin>>size;

    int arr[size];
    int top=-1;

    while(true){
		cout<<("\nWhat do you want to perform: \n");
		cout<<("1.Push\n");
		cout<<("2.Pop\n");
		cout<<("3.isEmpty\n");
		cout<<("4.isFull\n");
		cout<<("5.Display\n");
        cout<<("6.Peek\n");
		cout<<("7.Exit\n");
		int num;
		cin>>num;
		switch (num) {
  			case 1:{
                int num_push;
		    	cout<<"Enter the number ot push: ";
                cin>>num_push;
                if(top==size-1){
                    cout<<"Stack is full already";
                }
                else{
                    top++;
                    arr[top]=num_push;
                }
                break;
			}
			case 2:{
                if(top==-1){
                    cout<<"Stack is already empty";
                }
                else{
                    top--;
                    cout<<"Removed element: "<<arr[top+1];
                }
                break;			    
			}
			case 3:{
                if(top==-1){
                    cout<<"Stack is empty";
                }
                else{
                    cout<<"Stack is not empty";
                }
                break;
			}
			case 4:{
                if(top==size-1){
                    cout<<"Stack is full";
                }
                else{
                    cout<<"Stack is not full";
                }
			    break;
			}
			case 5:{
                cout<<"\nThe stacks is: ";
                for(int i=0;i<=top;i++){
                    cout<<arr[i]<<"\t";
                }
                break;
			    
			}
			case 6:{
                cout<<arr[top];
                break;    
			}
            case 7:{
                cout << "Exiting";
			    return 0;
            }
			default:
				cout<<"Invalid code! Try again";
		}
    }


    return 0;
}
