#include <iostream>
#include "../include/Tree.h"

using namespace std;

NodeTree * Tree::getNodeByData(int data)
{
    NodeTree * current=root;
    while(current != nullptr )
    {
        if(data == current ->data)
        {
            return current;
        }
        else if (data > current ->data)
        {
            current=current->right;
        }
        else
        {
            current=current->left;
        }

    }
    return nullptr;
}

NodeTree * Tree::getParent(int data)
{
    NodeTree * current =getNodeByData(data);
    if(current ==nullptr || current == root)
    {
        return nullptr;
    }
    else
    {
        NodeTree *parent=root;//Counter
        while(parent != nullptr)
        {
            if(parent->left ==current || parent ->right == current)
            {
                return parent;
            }
            else
            {
                // JUMP ==> check data ??
                if(current->data > parent ->data)
                {
                    parent=parent->right;
                }
                else
                {
                    parent=parent->left;
                }


            }

        }
    }


}

Tree::Tree()
{
    root=nullptr;
}

void Tree::add(int data)
{
    //Create Node
    NodeTree * newNode=new NodeTree(data);
    //Tree Empty
    if(root ==nullptr)
    {
        root=newNode;
        root->left=nullptr;
        root->right=nullptr;
    }
    else
    {
        //Tree Not Empty
        NodeTree * current =root;
        NodeTree * parent =nullptr;
        while( current != nullptr )
        {
            parent =current;
            if(data <current->data)
            {
                current=current->left;
            }
            else if(data == current->data)
            {
                delete newNode;
                return ;
            }
            else   //(data >current->data)
            {
                current=current->right;
            }
        }
        if(parent != nullptr)
        {
            if(data > parent->data )
            {
                parent->right=newNode;
            }
            else
            {
                parent->left=newNode;
            }
        }


    }
}

bool Tree::getNodeData(int data)
{
    NodeTree * current=getNodeByData(data);
    if(current !=nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int Tree::getParentData(int data)
{
    NodeTree * current=getParent(data);
    if(current !=nullptr)
    {
        return current->data;
    }
    else
    {
        return -1;
    }
}

NodeTree * Tree::maxRight(int data)
{
    NodeTree * current = getNodeByData(data);
    // Root
    if(current == nullptr)
    {
        return nullptr;
    }
    while(current->right != nullptr )
    {
        current=current->right;
    }

    return current;
}

int Tree::maxRightData(int data)
{
    NodeTree * current =maxRight(data);
    if(current == nullptr)
    {
        return -1;
    }
    else
    {
        return current->data;
    }

}

void Tree::removeNode(int data)
{
    NodeTree * current = getNodeByData(data);
    if(current == nullptr){
        return ;
    }
    if(current == root){
            //ROOT Only
            if(current ->right == nullptr && current->left ==nullptr)
            {
                root=nullptr;
            }
            else if(current ->right == nullptr) //ROOT & leftSide
            {
                root=root->left;

            }
            else if(current->left ==nullptr) //Root & Right Side
            {
                root=root->right;
            }
            else //RooT Right Side &Left Side
            {  
                NodeTree * newRoot=root->left; // Arwa
                NodeTree * maxRightNode = maxRight(newRoot->data); // Skills
                maxRightNode->right=root->right; // Team2
                root=newRoot; //
            }
    }
    else if (current->left != nullptr || current->right != nullptr) // is an internel node
    {
        NodeTree * parent = getParent(data); // get its parent

        if(parent->data < current->data)  // is on the right side of its parent
        {
            if(current->left == nullptr) // has 1 right child
            {
                parent->right = current->right;
            }
            else if(current->right == nullptr) // has 1 left child
            {
                parent->right = current->left;
            }
            else // has 2 children :(   make the left child take its place
            {
                NodeTree * rightest = maxRight(current->left->data); // rightest of its left child
                rightest->right = current->right;

                parent->right = current->left;
            }
        }
        else // is on the left side of its parent so its child will take its place
        {
            if(current->left == nullptr) // has 1 right child
            {
                parent->left = current->right;
            }
            else if(current->right == nullptr) // has 1 left child
            {
                parent->left = current->left;
            }
            else // has 2 children :(   make its left child take its place
            {
                NodeTree * rightest = maxRight(current->left->data); // rightest of its left child
                rightest->right = current->right;

                parent->left = current->left;
            }
        }
    }
    else // is a leaf node :)
    {
        NodeTree * parent = getParent(data); // get its parent
        if(parent->data < current->data) // is on the right of its parent
        {
            parent->right = nullptr;
        }
        else // is on the left of its parent
        {
            parent->left = nullptr;
        }
    }

    delete current;
}

// void display Data LDR using Recusion
void Tree::DisplayLDR() // left -> data -> right (Inorder) -> prints sorted asc
{
    NodeTree * current = this->root;
    if(current == nullptr)
        return ;
    LDR_helper(current);
}

void Tree::LDR_helper(NodeTree * current)
{
    if(current->left != nullptr) // go left untill there are no more left
        LDR_helper(current->left);
    
    cout<<current->data<<'\t'; // print it

    if(current->right != nullptr) // if there is right go right
        LDR_helper(current->right);
}

// 3. Write a function that takes the root of a binary tree and returns its Maximum Depth / Height, 
// measured by the number of nodes along the longest path.
// 3.a.  Approach 1 (Recursive - DFS): Using recursion to explore subtrees.

// DC
// 1. divide -> the problem into left and right subtree
// 2. conquer -> get max depth of each subtree
// 3. combine -> get the max depth of the 2 subtrees + 1 which is the max depth of my current node

int Tree::MaxDepthDFS(NodeTree * Node) 
{
    if(Node == nullptr)
        return 0;

    if(Node->left == nullptr && Node->right == nullptr) // leaf
        return 1;

    int left_path = 0;
    int right_path = 0;

    if(Node->left != nullptr)
        left_path = MaxDepthDFS(Node->left) + 1; // get max depth of the left tree

    if(Node->right != nullptr)
        right_path = MaxDepthDFS(Node->right) + 1; // get max depth of the right tree

    if (left_path > right_path)
        return left_path;
    else
        return right_path;
}

//3.b. Approach 2 (Iterative - BFS): Using a Queue to traverse the tree level by level without recursion.

int Tree::MaxDepthBFS(NodeTree * Node)
{
    if(Node == nullptr)
        return 0;

    queue<NodeTree *> q;

    int height = 0;
    q.push(Node);

    // in each iteration remove current level nodes and push their children
    // if at least one of the nodes has a child increment height by 1
    while (!q.empty()) 
    {
        height++;
        int current_level_children = q.size();

        for(int i = 0;i<current_level_children;i++)
        {
            if(q.front()->left)
                q.push(q.front()->left);

            if(q.front()->right)
                q.push(q.front()->right);

            q.pop();
        }
    }
    
    return height;
}
