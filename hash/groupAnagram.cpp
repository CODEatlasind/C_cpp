#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool occurence(string a,string b){
        if(a.length()!=b.length()){
            return false;
        }
        unordered_set<char> mp;
        for( int i=0;i<a.length();i++){
            mp.insert(a[i]);
        }

        for( int k=0;k<b.length();k++){
            
            if(mp.count(b[k])==0){
                    return false;
            }
            
        }   
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        for(int i=0;strs.size();i++){
            vector<string> temp;
            for(int j=i+1;j<strs.size();j++){
                if(occurence(strs[i],strs[j])){
                    temp.push_back(strs[j]);
                    strs.erase(strs.begin()+j);
                }
            }
            group.push_back(temp);
        }
        return group;
    }

int main(){
    vector<vector<string>> sp;
    vector<string> temp={"eat","tea","tan","ate","nat","bat"};
    sp=groupAnagrams(temp);

    for(int i=0;i<sp.size();i++){
        for(int j=0;j<sp[i].size();j++){
            cout<<sp[i][j]<<",";
        }
    }

}