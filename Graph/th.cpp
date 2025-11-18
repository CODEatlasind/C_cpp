#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void checkDFS(int **a,int n,int start, bool *visited){
    
    visited[start]= true;
        for( int j=0;j<n;j++){
            if(j==start){
                continue;
            }
            if(a[start][j]==1){
                if(visited[j]==true){
                    continue;
                }
                checkDFS(a,n,j,visited);
            }
        }
}
void checkBFS(int **a,int n,int sv,bool *visited){
    queue<int> q;
    q.push(sv);
    
    visited[sv]=true;

    while(!q.empty()){
        int dat=q.front();
        
        q.pop();

        for(int i=0;i<n;i++){
            if(i==dat){
                continue;
            }
            if(a[dat][i]==1){
                if(visited[i]==false){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        
    }
}
vector<int> BFS(int **a,int n,int sv,bool *visited){
    queue<int> q;
    vector<int> s;
    q.push(sv);
    
    visited[sv]=true;

    while(!q.empty()){
        int dat=q.front();
        s.push_back(dat);
        q.pop();

        for(int i=0;i<n;i++){
            if(i==dat){
                continue;
            }
            if(a[dat][i]==1){
                if(visited[i]==false){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        
    }
    return s;
}
// connected
bool isConnected(int **edge,int n){
    // 6 4 5 3 0 1 3 4 0 3
    // 4 4 0 1 1 2 2 3 3 0
    bool* visited=new bool(n);
    for( int i=0;i<n;i++){
        visited[i]=false;
    }
    
    // checkDFS(edge,n,0,visited);
    checkBFS(edge,n,0,visited);

    for(int i=0;i<n;i++){
        if(visited[i]==false){
            return false;
        }
   }
   return true;
}
// connected components
vector<vector<int>> connected_comp(int **edge,int n){
    vector<vector<int>> ans;
    bool* visited=new bool(n);
    for( int i=0;i<n;i++){
        visited[i]=false;
    }

    
    for( int i=0;i<n;i++){
        if(!visited[i])
            ans.push_back(BFS(edge,n,i,visited));
    }
    return ans;
}

// wighted

int main(){
    int n,e;
    cout<<"ENTER the Number of Nodes:"<<endl;
    cin>>n;
    cout<<"ENTER the Number of Edges:"<<endl;
    cin>>e;
    int **edge=new int*[n];
    for(int i=0;i<n;i++){
        edge[i]=new int[n];
        for(int j=0;j<n;j++){
            edge[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        printf("ENTER the first edge %d : \n",i);
        cin>>f;
        printf("ENTER the second edge %d : \n",i);
        cin>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }
    //Is connected or not
    // cout<<(isConnected(edge,n)? "Connected" : "Not Connected")<<endl;

    //connected components
    vector<vector<int>> ans=connected_comp(edge,n);
    for(auto it:ans){
        for(auto it2:it){
            cout<<it2<<",";

        }
        cout<<endl;
    }

    for( int i=0;i<n;i++){
        delete edge[i];
    }

    delete[] edge;
}