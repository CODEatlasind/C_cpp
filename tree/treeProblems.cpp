#include "implement.cpp"

//count the number of nodes in a tree
int nodeCount(treeNode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=nodeCount(root->children[i]);
    }
    return ans;
}

//to find the sum of all nodes in a tree
int nodeSum(treeNode<int>* root){
    treeNode<int>* start=root;
    if(start->children.size()==0)
        return start->data;

        int sum=root->data;
    for(int i=0;i<start->children.size();i++){
        sum+=nodeSum(start->children[i]);
    }
    return sum;
}

//height of a tree
int height(treeNode<int>* root){
    treeNode<int>* top=root;
    int maxheight=0;

    if(top->children.size()==0)
        return 1;

    for(int i=0;i<top->children.size();i++){
        int treeheight=1+height(top->children[i]);
        if(treeheight>maxheight)
            maxheight=treeheight;
    }
    return maxheight;
}

//print elements at depth k
void printAtK(treeNode<int>* root, int k){
    if(k==0){
        cout<<root->data<<",";
        return;
    }
    
    for(int i=0;i<root->children.size();i++)
        printAtK(root->children[i],k-1);
    
    if(k>0){
        cout<<"Data NOT found";
        return;
    }
}
//count leaf node
int countLeaf(treeNode<int>* root){
    if(!root->children.size()){
        return 1;
    }
    int leaf=0;
    for(int i=0;i<root->children.size();i++){
        leaf+=countLeaf(root->children[i]);
    }
    return leaf;

}
void printOrder(treeNode<int>* root)
{
    for(int i=0;i<root->children.size();i++){
        printOrder(root->children[i]);
        
    }
    cout<<root->data<<",";
}
//delete nodes due to dynamic allocation
void deleteTree(treeNode<int>* root){
    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
        
    }
    cout<<"DATA " <<root->data <<" Deleted:"<<endl;
    delete root;

}

//to finnd x in tree
bool containX(treeNode<int>* root,int x){
    if(root->data==x){
        return true;
    }
    for(int i=0;i<root->children.size();i++){
            return containX(root->children[i],x)*false;
    }
}
// to count nodes in tree
int numT(treeNode<int>* root,int x){
    int sum=0;
    if(root->data>x)
    {
        sum=1;
    }
    for(int i=0;i<root->children.size();i++){
            sum = sum + numT(root->children[i],x);
    }
    return sum;
}
int sumChild(treeNode<int>* root){
    int sum=0;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    return root->data+sum;
}

//maximum amoung root and children
treeNode<int>* maxNode(treeNode<int>* root){
    treeNode<int>* maxroot=root;
    int sum=sumChild(root);

    for(int i=0;i<root->children.size();i++){
        treeNode<int>* x=maxNode(root->children[i]);
        int xsum=sumChild(root->children[i]);
        cout<<xsum<<endl;
        if(xsum>sum){
            maxroot=x;
        }
    }
    return maxroot;
}

//using pair to calculate maximum node

pair<treeNode<int>*,int> pairMaxNode(treeNode<int>* root){
    pair<treeNode<int>*,int> maxroot;
    maxroot.first=root;
    maxroot.second=sumChild(root);

    for(int i=0;i<root->children.size();i++){
        pair<treeNode<int>*,int> x=pairMaxNode(root->children[i]);
    
    
        if(x.second>maxroot.second){
            maxroot.first=x.first;
        }
    }
    return maxroot;
}

// to chechk for structural integrity
bool symCheck(treeNode<int>* r1,treeNode<int>* r2){
    if(r1->data!=r2->data ){
        return false;
    }
    if(r1->children.size()!=r2->children.size()){
        return false;
    }
    for(int i=0;i<r1->children.size();i++){
        if(!symCheck(r1->children[i],r2->children[i])){
            return false;
        }
    }
    return true;
}

//find the next greates number in the tree
treeNode<int>* nextGreatest(treeNode<int>* root , int n){
    
    treeNode<int>* ans;
    if(root->data>n){
        ans=root;
    }
    else{
        ans=NULL;
    }
    for(int i=0;i<root->children.size();i++){
        
        treeNode<int>* temp=nextGreatest(root->children[i],n);
        if(temp->data<ans->data ){
            ans=temp;
        }
        if(ans==NULL){
            ans=temp;
        }
        // return nextGreatest(root->children[i],n);
    }
    
    return ans;
    

}

//return the second largest number with only numbers
pair<int,int> maximii(treeNode<int>* root){
    pair<int,int> p(root->data,-1);

    for(int i=0;i<root->children.size();i++){
        pair<int,int> temp = maximii(root->children[i]);
        if(temp.first>p.first){
            if(temp.second>p.second){
                p.second=temp.second;
            }
            else{
                p.second=p.first;
            }
            p.first=temp.first;
        }
    }
    return p;
}
//greatest of 3 nodes
treeNode<int>* greatNode(treeNode<int>*n1, treeNode<int>* n2, treeNode<int>*n3){
    if(n1->data>n2->data){
        if(n1->data>n3->data){
            return n1;
        }
    }
    else if(n2->data>n1->data){
        if(n2->data>n3->data){
            return n2;
        }
        else{
            return n3;
        }
    }
}
treeNode<int>* greatNode(treeNode<int>*n1, treeNode<int>* n2){
    if(n1->data>n2->data){
        return n1;
    }
    else if(n2->data>n1->data){
            return n2;
    }
}


pair<treeNode<int>*,treeNode<int>*> maximiiNodus(treeNode<int>* root){
    pair<treeNode<int>*,treeNode<int>*> p(root,NULL);

    for(int i=0;i<root->children.size();i++){
        pair<treeNode<int>*,treeNode<int>*> temp = maximiiNodus(root->children[i]);
        treeNode<int>* x;
        if(temp.first->data>p.first->data){
            x=p.first;
            p.first=temp.first;
            if(p.second==NULL && temp.second==NULL ){
                p.second=x;
            }
            else if(p.second==NULL && temp.second!=NULL){
                p.second=greatNode(x,temp.second);
            }
            else if(p.second!=NULL && temp.second==NULL){
                p.second=greatNode(x,p.second);
            }
            else{
                p.second=greatNode(x,p.second,temp.second);
            }
        }
        else{
            x=temp.first;
            if(p.second==NULL && temp.second==NULL ){
                p.second=x;
            }
            else if(p.second==NULL && temp.second!=NULL){
                p.second=greatNode(x,temp.second);
            }
            else if(p.second!=NULL && temp.second==NULL){
                p.second=greatNode(x,p.second);
            }
            else{
                p.second=greatNode(x,p.second,temp.second);
            }
        }
        // pair<treeNode<int>*,treeNode<int>*> temp = maximii(root->children[i]);
        // if(p.second==NULL){
        //     if(p.first>temp.first){
        //         p.second=temp.first;
        //     }
        //     else{
        //         p.second=p.first;
        //         p.first=temp.first;
        //     }
        // }
        // else if(temp.second==NULL){
        //     if(p.first>temp.first){
        //         p.second=temp.first;
        //     }
        //     else{
        //         p.second=p.first;
        //         p.first=temp.first;
        //     }
        // }
        // else{
        //     if(p.first>temp.first){
        //         if(p.second<temp.first){
        //             p.second=temp.first;
        //         }
        //         else if(p.second<temp.second){
        //             p.second=temp.second;
        //         }
        //     }
        //     else{
        //         p.second=p.first;
        //         p.first=temp.first;
        //     }

        // }
    }
    return p;
}

int main(){
    //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    // treeNode<int>* root=takeLevelInputs();
    // cout<<"\n x DATA"<<endl;
    // printLevels(root);
    // cout<<nodeCount(root);
    // cout<<"Node Sum :"<<nodeSum(root);
    // cout<<"height :"<<height(root);

    // cout<<"Elements at level k : ";
    // printAtK(root,2);1

    // cout<<"leafNode :"<<countLeaf(root);
    // printOrder(root);
    // cout<<endl;

    
    //print 

    //containns x
    // int x;
    // cin>>x;
    // cout<<containX(root,x)<<endl;
    
    // printOrder(root); 
    cout<<endl;
    // cout<<"Number of node="<<numT(root,5)<<endl;
    // cout<<"Maximum sum="<<maxNode(root)->data<<endl;
    // cout<<"sumchi"<<sumChild(root->children[0]);
    
    // cout<<"Maximum sum="<<pairMaxNode(root).first->data<<endl;

    // deleteTree(root);
    // treeNode<int>* r1=takeLevelInputs();
    // cout<<"\n";
    // treeNode<int>* r2=takeLevelInputs();
    // cout<<"\n";

    // cout<<"Check If so: "<<symCheck(r1,r2)<<endl;

    // deleteTree(r1);
    // deleteTree(r2);
    // treeNode<int>* r1=takeLevelInputs();
    // cout<<endl;
    // int n;
    // cout<<"ENTER number to be tested:"<<endl;
    // cin>>n;
    // cout<<"Second Greatest:"<<nextGreatest(r1,n)->data<<endl;
    // deleteTree(r1);
    treeNode<int>* r1=takeLevelInputs();
    cout<<endl;
    cout<<"Second Greatest:"<<maximiiNodus(r1).second->data<<endl;
    
    deleteTree(r1);
    
    
    

}