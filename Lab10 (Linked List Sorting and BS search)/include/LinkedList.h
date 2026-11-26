#ifndef LL_H
#define LL_H

#include "Node.h"

// Day1 - LinkedList:
// ======================
//    //1. indsert node after given node
//         void InsertAfter(int data, int afterData); 
//    //2. indsert node before given node
//         void InsertBefore(int data, int beforeData); 	
//    //3. get number of nodes 
//         int GetCount();
//    //4. get data in the given 		 			               
//         int GetDataByIndex(int index);

class LinkedList
{
    public:
    Node * head;
    Node *tail;
    
    LinkedList();
    void Insert(int data);
    void display();


    Node * FindData(int data); // helper
    void InsertAfter(int data, int afterData); 
    void InsertBefore(int data, int beforeData); 
    int GetCount();
    int GetDataByIndex(int index);

    Node* GetPtrToIndex(int index);

};

#endif

