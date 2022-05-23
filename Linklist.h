#pragma once
#include "Node.h"
#include <iostream>
#include <limits>

class Linklist
{
    private:
    Node * head;

    public:
    //constructor
    Linklist()
    {
        head = NULL;
    }
    //A constructor that takes an array of integers and makes a linked list, containing all the elements of the array, in the same order. As the second parameter, it takes the size of the array.
   
    Linklist(int array[],int size)
    {
        head = NULL;
        for(int i = 0; i < size; i++)
        {
            addEnd(array[i]);
        }
    }
    //destructor
    ~Linklist()
    {
        //Traversal
        for(Node* temp = head; temp != NULL; temp = temp -> getNext())
        {
            Node* node = temp;
            delete(node);
        }
        head = NULL;
    }



    void addFront(int newItem)
    {
        Node *temp;
        Node * n = new Node(newItem);
        n -> setNext(head);
        head = n;
    }
   void addEnd(int newItem)
    {
        if(head == NULL)
        {
            addFront(newItem);
            return;
        }
        Node * temp;
        Node * n = new Node(newItem);
        n ->setNext(NULL);
        
        for (temp = head; temp -> getNext() != NULL; temp = temp -> getNext() )
        {
            ;
        }
        
        temp ->setNext(n);        
    }

    void addAtPosition(int position, int newItem)
    {
        Node *temp;
        Node *n = new Node(newItem);
        int pos = 1;
        
        // assume the first element of the list is in position 1. If position is larger than the size of the list, the new item is added to the end of the list. If position < 1, the new item is added at the beginning of the list.
        if(position < 1  || position == 1)
        {
            addFront(newItem);
            return;
        }
        
        
        for (temp = head; temp != NULL; temp = temp -> getNext() )
        {
            if((pos + 1) == position)
            {
                n -> setNext(temp -> getNext());
                temp -> setNext(n);
                return;
            }
            pos ++;
        }

        addEnd(newItem);

    }
    // The function searches the list for the first instance of the item, and if found, both prints the position of the of the item (followed by a space) and returns the position of the item in the list (positions start from 1). If not found, both prints 0 (followed by a space) and returns 0. Note that the returning type is different from what was explained in the search function in the lecture.
    int search(int item)
    {
        int index = 1;
        Node *temp;
        for( temp = head; temp != NULL; temp = temp -> getNext())
        {
            if (item == temp -> getData())
            {
                std::cout << index << " " << std::endl;//note

            }
            index ++;
        }

        std::cout << "0 ";
        return 0;

    }

    void deleteFront() //The function deletes the first element of the list.
    {
        Node *temp = head;
        //head switch to next
        head = temp ->getNext();
        delete(temp);
    }

    void deleteEnd() //The function deletes the last element of the list.
    {
        Node * temp;
       
        if(head -> getNext() == NULL)
        {
            delete(head);
            head = NULL;
        }
        
        for(temp = head; temp -> getNext() ->getNext() != NULL; temp -> getNext())
        {
            ;//set temp to last 2 position;
        }
        delete(temp -> getNext());
        temp ->setNext(NULL);

    }
    //The function deletes the element at the given position of the list. If the position < 1 or it is larger than the size of the list, only print ”outside range”.
    void deletePosition(int position)
    {
        if ( position < 1)
        {
            std::cout << "outside range";
            return;
        }

        if (position == 1 )
        {
            Node * temp = head;
            head = head -> getNext();
            delete(temp);
            return; 
        }
        int pos = 1;
        for(Node *temp = head; temp != NULL; temp = temp -> getNext())
        {
            if (pos + 1 == position)
            {
                Node * node = temp -> getNext();
                if (node = NULL)
                {
                    std::cout << "outside range";
                    return; 
                }
                temp ->setNext( node -> getNext());
                delete(node);
                return;
            }
            pos ++;
        }
    }
    
    // The function both prints the value of the item (followed by a space) and returns the value of the item at the given position of the list 
    // If beyond the size of the array, both prints std::numeric_limits < int >::max() (followed by a space) and returns std::numeric_limits< int >::max().
    int getItem(int position) 
    {
        int pos = 1;
        Node * temp;
        for (temp = head; temp != NULL; temp = temp -> getNext())
        {
            if (pos == position)
            {
                std::cout << temp ->getData() <<" ";
                return temp ->getData();
            }
            pos ++;
        }
        return 0;

    }
    // The function prints the value of the items of the list from head to tail. In case of an empty list, it does not print anything
    void printItems()
    {
         for(Node *temp = head; temp != NULL; temp = temp->getNext())
         {
               std::cout<<temp->getData()<<" ";
        }
    }



 




};