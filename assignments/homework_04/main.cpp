/**
 * Leila Kalantari
 * Date: 13/15/2019
 * CMPS 1063- Dr .Griffin
 */
#include <iostream>
#include <fstream>
#include "ListQueue.hpp"

using namespace std;


int main() {
  ListQueue LQ;                 // Queue instance 
  ifstream fin("animals.txt");
  string animal;
  cout<<"Leila Kalantari"<<endl<<endl;
  
    while (!fin.eof()) {
      fin >> animal;//read animals from file
      cout<<animal<<" ";
      LQ.Push(animal);
  }

  cout<<endl;                     // ummmm 

  LQ.Print();                     // print queue to see where values are


  for(int i=0;i<5;i++){           // remove 5 items
    if(!LQ.Empty()){
      string t = LQ.Pop();
      cout<<"Item: "<<t<<endl;    // print out items
    }else{
      cout<<"Empty queue!"<<endl;
    }

  }

  LQ.Print();                     // print again to show front removal
  LQ.PrintPointers();

  Node* f = LQ.GetFront();        // We added this in class JUST to see what front
  cout<<f->animal<<endl;            // pointed to.
}
