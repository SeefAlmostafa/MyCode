#include <iostream>
#include "stack.h"
using namespace std;


Stack* create_stack(unsigned int capacity){
    // The stack should have a capacity > 0
    if (capacity == 0){
        cout<<" The Stack does not exist !"<<endl;
        return NULL;
    }
    else{
        Stack *new_stack = new Stack;
        if (new_stack == NULL){
            cout<<"Meomory is full"<<endl;
            return new_stack;
        }
        new_stack->content= new char[capacity];
        if(new_stack->content == NULL){
            cout<<"Meomory is full"<<endl;
            return new_stack;
        }
        // First index of the Stack is 0  -> (capacity-1)
        new_stack->depth = capacity-1;
        new_stack->top = 0;
        return new_stack;
    }
}

// Push/store ch into the array
void push(Stack* new_stack, char ch){
    if(new_stack->top > new_stack->depth){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        new_stack->content[new_stack->top]= ch;
        new_stack->top++;
    }
}
// LIFO: return top character
char pop(Stack* new_stack){
    if(isEmpty(new_stack)){
        cout<<"Stack Underflow"<<endl;
        return '?';
    }
    else{
        char value;
        new_stack->top--;
        return value = new_stack->content[new_stack->top];
    }
}
// Check if the stack is empty !
bool isEmpty(Stack* new_stack){
    return (new_stack->top == 0);
}

// Free the memory
void destroy_stack(Stack* new_stack){
    delete[] new_stack->content;
    delete new_stack;
}
