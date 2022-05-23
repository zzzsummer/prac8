#pragma once
#include <iostream>

class Node
{
private:
    int data;
    Node * next;
public:
    //CONSTRUCTOR
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    //getter
    int getData()
    {
        return data;
    }

    Node * getNext()
    {
        return next;
    }

    //setter
    void setData(int data)
    {
        this->data = data;
    }

    void setNext(Node * next)
    {
        this ->next = next;
    }
};

