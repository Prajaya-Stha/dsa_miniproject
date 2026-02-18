#ifndef STACK_H
#define STACK_H

#include "travel.h"

#define MAX 50

class Stack
{
    Place arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(Place p)
    {
        if (top < MAX - 1)
            arr[++top] = p;
    }

    Place pop()
    {
        if (!isEmpty())
            return arr[top--];
        return Place();
    }
};

#endif
