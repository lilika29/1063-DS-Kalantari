/*
 * Leila Kalantari
 * Date: 13/15/2019
 * CMPS 1063- Dr .Griffin
 * List stack definition file. This stack hold animal types. 
*/
#include <iostream>

using namespace std;

/**
 * Animal Type
 */
struct Animal {
    string name;
    double weight;
    double scary;

    // Default constructor
    Animal() {
        name = "";
        weight = 0.0;
        scary = 99.0;
    }

    // Should add an overloaded constructor
     //my hw code
    Animal(string N,double W,double S){
      name=N;
      weight=W;
      scary=S;
       }


};

// Overload "<<" operator for animals
ostream &operator<<(ostream &, const Animal *);

/**
 * Node type.
 * 
 * We seperate Animal from Node so we can return an "Animal"
 * when we pop the stack, and don't have to return a "node"
 */
struct Node {
    Animal *A;
    Node *Next;

    // Needs a default constructor

    Node(Animal *a) {
        A = a;
        Next = NULL;
    }
};

/**
 * ListStack
 * 
 * List based stack implementation
 * 
 */
class ListStack {
private:
    Node *Top;

public:
    ListStack();          // constructor
    void Push(Animal *);  // stack gets Animals
    Animal *Pop();        // Pop returns top animal
    void Print();         // print stack for debugging
};
