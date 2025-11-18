#include "bstClass.h"
int main(){
    BST* b=new BST();
    b->createTree();
    cout<<"OG tree: \n";
    b->printBst();

    b->insertBst(3);
    cout<<"NEW BST equal: \n";
    b->printBst();
    b->deleteBst(3);
    cout<<"TREE: \n";
    b->printBst();

}