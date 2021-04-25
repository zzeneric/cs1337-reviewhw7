#ifndef STACK_H
#define STACK_H

#include "Node.h"


class Stack{
    public:
        Stack(); // Default constructor
        Stack(Node* origin); // Overloaded constructor (node pointer parameter, assigns head to node passed in)
        
        void destroy(Node* head); // Destructor (deletes linked list)
        //Node* copy(Node* head); // Copy constructor

        Node* getHead() const; // Accessor
        void setHead(Node* newHead); // Mutator

        void push(Node* head, Node* newHead); // Push
        void display(Node* head); // Display
    private:
        Node* head; // Head pointer
};

#endif