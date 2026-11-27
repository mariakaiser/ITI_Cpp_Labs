class NodeTree
{
public:
    int data;
    NodeTree * left;
    NodeTree * right;
    NodeTree(int data )
    {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;

    }
};