#include <iostream>
#include "stack.h"

using namespace std;

// Default constructor
Stack::Stack(){
  Size = 10;
  A = new int [Size];
  Top = -1;
  count=0;
}

// overloaded constructor
Stack::Stack(int s){
  Size = s;
  A = new int [Size];
  Top = -1;
}

bool Stack::Push(int val){
  if(!Full()){
    Top++;
    A[Top] = val;
    count++;
     checkResize(); 
    return true;
  }else{
    return false;
  }
}

int Stack::Pop(){
  if(!Empty()){
    int temp = 0;   
    temp = A[Top];
    Top--;
    count--;
    checkResize();
    return temp;
  }else{
    cout<<"Cannot remove item from empty stack"<<endl;
  }
  return 0;
}

void Stack::Print(){
  for(int i = Top;i>=0 ; i--){
    cout<<A[i]<<endl;
  }
}

/**
*
*/
bool Stack::Empty(){
  return Top < 0;
}

bool Stack::Full(){
  return (Top == Size - 1);
}


/**
*
*/

void Stack::checkResize(){
   
 double ratio;
 ratio=count/Size;
 cout<<ratio<<endl;
 if(ratio<=0.2 && Size >= 10 ){
   cout<<"reducing"<<endl;
    Reduce();
  }else if(ratio>=0.8){
    Enlarge();
  }

}
/*
void Stack::checkResizePush(){
  double ratio;
 ratio=count/Size ;
 if(ratio>=0.8){
    Enlarge();
    }
else if(ratio<=0.2){
      Reduce();
       }
}


*/



  void Stack::Enlarge(){
     int new_size = Size * 1.5;
  
    int *Array2 = new int [new_size];
    for(int i=0;i<count;i++){
        Array2[i] = A[i];
    }
        int *temp = A;
        A = Array2;
        delete [] temp;
        Size=new_size;
        cout<<"the largest size is "<< new_size<<endl; 
        }
   
   
    
  

void Stack::Reduce(){
    int new_size = Size * 0.5;
    int *Array2 = new int [new_size];
    for(int i=0;i<count;i++){
    Array2[i] = A[i];
    }
    int *temp = A;
    A = Array2;
    delete [] temp;
    Size=new_size;
    cout<<"the smallest size is "<< new_size<<endl; 
    for(int i=0;i<new_size;i++){
      cout<<A[i] << " ";
    }
    }


#include <iostream>
#include "stack.h"
#include "stdlib.h"
#include <fstream>


using namespace std;

int main() {
  //srand(34234);
  Stack S1;
  Stack S2(200);

  int a;
 string op;
 ifstream fin("input.txt");
 while(!fin.eof()){
    fin>>op>>a;
    if(op=="+"){
    S1.Push(a);
    }
     else if(op=="-"){
    S1.Pop();
    }
    }
  //S1.Print();
  
  return 0;
}



#include <iostream>
#include "stack.h"
#include "stdlib.h"
#include <fstream>


using namespace std;

int main() {
  //srand(34234);
  Stack S1;
  Stack S2(200);

  int a;
 string op;
 ifstream fin("input.txt");
 while(!fin.eof()){
    fin>>op>>a;
    if(op=="+"){
    S1.Push(a);
    }
     else if(op=="-"){
    S1.Pop();
    }
    }
  //S1.Print();
  
  return 0;
}
  



