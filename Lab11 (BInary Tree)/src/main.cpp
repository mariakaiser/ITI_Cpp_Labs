#include <iostream>
#include "../include/Tree.h"

using namespace std;
/*
            50
          /    \
        40      60 
       /  \       \
     30    45      70
                  /
                65
*/



int main()
{
    Tree t;
    t.add(50);
    t.add(50);
    t.add(40);
    t.add(30);
    t.add(45);
    t.add(60);
    t.add(70);
    t.add(65);

    // int parentData=t.getParentData(60);
    // cout<<t.getParentData(60)<<endl;
    // cout<<t.getParentData(50)<<endl;
    // cout<<t.getParentData(65)<<endl;
    // cout<<t.getParentData(45)<<endl;
    // t.getNodeData(60)? cout<<"Found"<<endl: cout<<"NotFound"<<endl;
    // t.getNodeData(50)? cout<<"Found"<<endl: cout<<"NotFound"<<endl;
    // t.getNodeData(30)? cout<<"Found"<<endl: cout<<"NotFound"<<endl;
    // t.getNodeData(100)? cout<<"Found"<<endl: cout<<"NotFound"<<endl;
    // cout<<t.maxRightData(40)<<endl;
    // cout<<t.maxRightData(50)<<endl;
    // cout<<t.maxRightData(30)<<endl; // if it has no right it returns the node itself

    // t.DisplayLDR();
    // cout<<endl;

    // t.removeNode(50);
    // //cout<<t.getNodeData(50); // root removed

    // t.removeNode(40);
    // //cout<<t.getNodeData(40); 

    // t.removeNode(65);
    // //cout<<t.getNodeData(65); 

    // cout<<endl;

    // t.DisplayLDR();

    cout<< t.MaxDepthDFS(t.root);
    cout<< t.MaxDepthBFS(t.root);


    return 0;
}