#include "NodeTree.h"
#include <queue>

// 3. Write a function that takes the root of a binary tree and returns its Maximum Depth / Height, measured by the number of nodes along the longest path.
//             3.a.  Approach 1 (Recursive - DFS): Using recursion to explore subtrees.
//             3.b. Approach 2 (Iterative - BFS): Using a Queue to traverse the tree level by level without recursion.

class Tree
{
private:
    NodeTree * getNodeByData(int data);
    NodeTree * getParent(int data);
    NodeTree * maxRight(int data);
    void LDR_helper(NodeTree * current);
  
public:
    NodeTree * root; //Parent Start of Tree
    Tree();
    void add(int data);
    bool getNodeData(int data);
    int getParentData(int data);
    int maxRightData(int data);
    void removeNode(int data); // 3 cases : root / internel / leaf
    void DisplayLDR(); // left -> data -> right (Inorder) -> prints sorted asc
    int MaxDepthDFS(NodeTree * Node);
    int MaxDepthBFS(NodeTree * Node);
    
};
