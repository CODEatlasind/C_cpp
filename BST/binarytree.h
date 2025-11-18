template <typename T>
// #define NULL nullptr
class binaryTreeNode{
    public:
    T data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(T data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    ~binaryTreeNode(){
        delete left;
        delete right;
    }
    
};