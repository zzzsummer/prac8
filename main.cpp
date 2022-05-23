#include <iostream>
#include <sstream>
#include "Linklist.h"
#include <string>
#include "Node.h"
using namespace std;

bool isNumber(string str)
{
    for (int i = 0; i < str.length(); i++)
        {
            if (isdigit(str[i]) == false)
            return false;
        }
    
    return true;
}

int main()
{
   int array[100];
   int count=0;
   int num,num1,num2;
   string item;
   while(true){ 
       cin>>item;
       if(isNumber(item)==false)
           break;
       stringstream(item)>>num;
       array[count]=num;
       count++;
   }
   Linklist *L=new Linklist(array,count);
   cin>>num1;
   cin>>num2;
  
   if(!item.compare("AF")){
       L->addFront(num1);  
   }
   else if(!item.compare("AE")){
       L->addEnd(num1);
   }
   else if(!item.compare("AP")){
       L->addAtPosition(num1,num2);
   }
   else if(!item.compare("S")){  
       L->search(num1);
   }
   else if(!item.compare("DF")){
       L->deleteFront();
   }
   else if(!item.compare("DE")){
       L->deleteEnd();
   }
   else if(!item.compare("DP")){
       L->deletePosition(num1);
   }
   else if(!item.compare("GI")){
       L->getItem(num1);
   }
   L->printItems();
   return 0;
}