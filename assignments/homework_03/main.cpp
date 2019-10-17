/*
 * Leila Kalantari
 * Date: 13/15/2019
 * CMPS 1063- Dr .Griffin
 * List stack definition file. This stack hold animal types. 
*/
#include "ListStack.h"    // include our stack definition
#include <fstream>        
#include <iostream>

using namespace std;

int main() {
    ifstream fin("animals.txt");  // input file of animal info                   
     Animal *a; 
     Animal *b;                   // animal pointer used to hold popped animals
    ListStack LS;                 // List based stack object
    cout<<"Leila Kalantari"<<endl<<endl;
    // While still animals in the file
    while (!fin.eof()) {
       a = new Animal();  // allocate memory for an animal
       fin >> a->name >> a->weight >> a->scary;  // load animal with file data
       LS.Push(a);}
       b = new Animal("tiger",170,0.87);
       LS.Push(b);                              // push animal onto the stack
    


    LS.Print();             // Print the stack

    cout << endl;           // ummm

    a = LS.Pop();           // get animal off top of stack
    
    cout << a <<" is poped animal "<< endl;      // print animal (cout operator overloaded)

    a = LS.Pop();           // get animal off top of stack again
    
    cout << a <<" is poped animal "<< endl;      // print animal (cout operator overloaded)

    LS.Print();             // print the stack
}
