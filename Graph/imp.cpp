#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printDFS(int **a,int n,int start, bool *visited){
    cout<<start<<",";
    visited[start]= true;
        for( int j=0;j<n;j++){
            if(j==start){
                continue;
            }
            if(a[start][j]==1){
                if(visited[j]==true){
                    continue;
                }
                printDFS(a,n,j,visited);
            }
        }
}
void printBFS(int **a,int n,int sv,bool *visited){
    queue<int> q;
    q.push(sv);
    
    visited[sv]=true;

    while(!q.empty()){
        int dat=q.front();
        q.pop();
        cout<<dat<<",";

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




//disconnected graph
void BFS(int **edge,int n){
    bool *visited = new bool(n);
    for( int i=0;i<n;i++){
        visited[i]=false;
    }

    for( int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edge,n,i,visited);
        }
    }

}
void DFS(int **edge, int n){
    bool *visited = new bool(n);
    for( int i=0;i<n;i++){
        visited[i]=false;
    }

    for( int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edge,n,i,visited);
        }
    }
}


//Find Path
bool GFSearch(int **edge,int n,int sv, int ev,bool *visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;

    while(!q.empty()){
        int dat=q.front();
        q.pop();
        if(dat==ev){
            return true;
        }

        for(int i=0;i<n;i++){
            if(i==dat){
                continue;
            }
            if(edge[dat][i]==1){
                if(visited[i]==false){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }     
    }
    return false;
}
bool DFSearch(int **a,int n,int start, int ev,bool *visited){
    
    visited[start]= true;
        for( int j=0;j<n;j++){
            if(j==start){
                continue;
            }
            if(a[start][j]==1){
                if(visited[j]==true){
                    continue;
                }
                return DFSearch(a,n,j,ev,visited);
            }
        }
}



bool pathBFS(int **edge,int n,int sv,int ev){
    bool *visited = new bool(n);
    for( int i=0;i<n;i++){
        visited[i]=false;
    }
    
    for( int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edge[sv][i]==1){
            if(i==ev){
                return true;
            }
        }
    }
    bool z;
        for( int i=0;i<n;i++){
            if(!visited[i]){
                if(GFSearch(edge,n,sv,ev,visited)){
                    return true;
                }
                

            }
        }
    return false;
}


bool pathDFS(int **edge,int n,int sv,int ev){
    bool *visited = new bool(n);
    for( int i=0;i<n;i++){
        visited[i]=false;
    }
    
    for( int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edge[sv][i]==1){
            if(i==ev){
                return true;
            }
        }
    }
    bool z;
        for( int i=0;i<n;i++){
            if(!visited[i]){
                if(DFSearch(edge,n,sv,ev,visited)){
                    return true;
                }
                

            }
        }
    return false;
}

//to FIND PATH FROM ONE TO OTHER POINT

vector<int> findPath(int **edge,int n, int sv,int ev,bool* visited){
    visited[sv]=true;
    vector<int> s;
    

    for( int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edge[sv][i]==1){
            if(visited[i]==true){
                continue;
            }
            if(i==ev){
                s.push_back(i);
                
            }
            else{
                s=findPath(edge,n,i,ev,visited);
                
            }
        }
    }
    if(s.size()>0){
        s.push_back(sv);
    }
    return s;
}

vector<int> findPathBFS(int **edge, int n, int sv, int ev, bool *visited){
    queue<int> q;
    map<int,int> map1;
    vector<int> path;

    q.push(sv);
    visited[sv]=true;
    int c=0;
    while(!q.empty() && c==0){
        int data=q.front();
        q.pop();

        for( int i=0;i<n;i++){
            if( i== data){
                continue;
            }
            else if(i==ev){
                c=1;
            }
            if( edge[data][i]==1 ){
                if(visited[i]!=true && c==0){
                    q.push(i);
                    visited[i]=true;
                }
            }
            map1[i]=data;
        }
    }

    if(c!=1){
        return path;
    }
    map<int, int> ::iterator it=map1.find(ev);
    path.push_back(ev);
    while(it!=map1.end()){
        path.push_back(it->second);
        it=map1.find(it->second);
    }
    return path;
}


int main(){
    //graph : 7 8 0 1 0 2 1 3 1 4 3 5 4 5 2 6 5 6
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

    // bool *visited=new bool[n];
    // for( int i=0;i<n;i++){
    //     visited[i]=false;
    // }
    // cout<<"DFS Traversal:"<<endl;
    // printDFS(edge,n,0,visited);

    // // bool *visited=new bool[n];
    // for( int i=0;i<n;i++){
    //     visited[i]=false;
    // }
    // cout<<endl;
    // cout<<"BFS Traversal:"<<endl;
    // printBFS(edge,n,0,visited);
    // delete[] visited;

    // cout<<"DFS Traversal:"<<endl;
    // DFS(edge,n);
    // cout<<endl;
    // cout<<"BFS Traversal:"<<endl;
    // BFS(edge,n); 
    
    //Find path
    // int sv,ev;
    // cout<<"ENTER Killu Node:"<<endl;
    // cin>>sv;
    
    // cout<<"ENTER GF Node:"<<endl;
    // cin>>ev;

    // cout<<(pathBFS(edge,n,sv,ev)?" GF Found !!":" GF NOT Found ;");
    
    // find the path between two nodes of graph
    // bool* visited=new bool[n];
    // for( int i=0;i<n;i++){
    //     visited[i]=false;
    // }

    // vector<int> path=findPath(edge,n,0,3,visited);

    // if(path.size()<=0){
    //     cout<<"NO PATH";
    // }
    // for(auto it : path){
    //     cout<<it<<",";
    // }
    
    // Find path usind BFS
    // vector<int> path=findPathBFS(edge,n,0,5,visited);
    // for(auto it : path){
    //     cout<<it<<",";
    // }

    // connected
    cout<<(isConnected(edge,n)? "Connected" : "Not Connected")<<endl;

    for( int i=0;i<n;i++){
        delete edge[i];
    }

    delete[] edge;
}