#include <iostream>

#include "Stack.h"
#include "Node.h"

using namespace std;

Stack::Stack(){ // Default constructor
    head = NULL;
}

Stack::Stack(Node* origin){ // Overloaded constructor
    head = origin;
}

void Stack::destroy(Node* head){ // Destroyer
    Node* iterator = head;
    cout << "DESTROYING: " << endl;
    while (iterator != 0){
        Node* next = iterator->getNext();
        head = next;
        Stack::display(head);
        delete iterator;
        iterator = head;
    }
    cout << endl;
    
    delete head;
}

/*Node* Stack::copy(Node* head){
    Node* temp = head;
    Node* copy = new Node();

    copy->setOperand(temp->getOperand());
    copy->setOperator(temp->getOperator());
    copy->setNext(NULL);

    Node* newHead = copy;

    temp = temp->getNext();

    while (temp != NULL){
        copy = temp;

        copy->setOperand(temp->getOperand());
        copy->setOperator(temp->getOperator());

        copy->setNext(NULL);

        temp = temp->getNext();
    }
    
    return newHead;
}*/

Node* Stack::getHead() const{
    return head;
}

void Stack::setHead(Node* newHead){
    head = newHead;
}

void Stack::push(Node* head, Node* newHead){
    Node* temp = new Node();

    temp->setOperand(newHead->getOperand());
    temp->setOperator(newHead->getOperator());
    
    newHead->setOperand(head->getOperand());
    newHead->setOperator(head->getOperator());

    head->setOperand(temp->getOperand());
    head->setOperator(temp->getOperator());

    delete temp;
 
    // Put top pointer reference into temp link
    newHead->setNext(head->getNext());
    head->setNext(newHead);
}

void Stack::display(Node* head){
    struct Node* temp;
    cout << "DISPLAY: " << endl;

    if (head == NULL){
        cout << "No items left in stack!";
    }else{
        temp = head;
        while (temp != NULL){
            cout << temp->getOperand() << "/" << temp->getOperator() << " -> ";
 
            temp = temp->getNext();
        }
    }
    cout << endl;
    delete temp;
}