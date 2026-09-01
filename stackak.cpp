#include<iostream>
#define MAX 5
using namespace std;

class Stack
{
  public:
    int A[MAX];
    int Top;
    Stack()
    {
      Top = -1;
    }
  
  void push(int value)
  {
    if(Top == MAX-1)
      {
      cout<<"Stack is Full i.e. Overflow\n";
      }
    else
      {
        Top++;
        A[Top]=value;
        cout<<A[Top]<<"Value is pushed in Stack\n";
      }
  }
  
  void pop()
  {
    if(Top==-1)
    {
      cout<<"Stack is Empty i.e. Underflow\n";
    }
    else
      {
      cout<<A[Top]<<" is popped From Stack.\n";
      Top--;
      } 
  }
  
  void display()
  {
    if(Top == -1)
    {
      cout<<"Stack is empty.\n";
    }
    else
    {
      for(int i=Top;i>-1;i--)
      {
        cout<<A[i]<<"\t";
      }
    }
  }
};

int main()
{
  Stack s1;
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.pop();
  s1.push(50);
  s1.display();
  return 0;
}
