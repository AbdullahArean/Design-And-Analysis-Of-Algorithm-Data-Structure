#include<iostream>
#include<list>
#include<climits>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std; 

 class Node{
    public:
    string name;
    list<string> nbrs;
    Node(string name){
        this->name= name;
    }
};
class Graph{
    unordered_map<string, Node*> ma;
    public:
    Graph(vector<string> datas){
        for(auto data : datas){
            ma[data]= new Node(data);
        }
    }
    void addEdge(string x, string y, bool undir=false){
        ma[x]->nbrs.push_back(y);
        if(undir){
            ma[y]->nbrs.push_back(x);
        }
    }
    void PrintAdjList(){
        for(auto citypair : ma){
            auto city = citypair.first;
            cout<<city<<"--> ";
            Node *node = citypair.second;
            for(auto nbr : node->nbrs){
                cout<< nbr << " ";
            }
            cout<<endl;

        }

    }
    int bfs(string beginWord, string endWord){
        int len= ma.size();
        unordered_map<string,bool> vis;
        unordered_map<string,int> dis;
        for(auto i:ma){
            vis[i.first]= 0;
            dis[i.first]= INT_MAX;
        }
        vis[beginWord]=1;
        dis[beginWord]=1;
        queue<string> cont;
        cont.push(beginWord);
        while(!cont.empty()){
            string u= cont.front();
            cont.pop();
            //cout<<u<<endl;
            for(auto j:ma[u]->nbrs){
                if(vis[j]==false){
                string v= j;
                vis[v]=true;
                dis[v]= dis[u]+1;
                cont.push(v);
                }
            }
        }
        if(ma.count(endWord)!=0){
            if(dis[endWord]==INT_MAX) return 0;
            else return dis[endWord];
            }
        return 0;

    }

};
bool isonewordaway(string a, string b){
    int len= a.length();
    int count=0;
    for(int i=0; i<len; i++){
        if(a[i]!=b[i]) count++;
    }
    if(count==1) return true;
    return false;

}
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    //https://leetcode.com/problems/word-ladder/
    wordList.push_back(beginWord);
    Graph g = Graph(wordList);
    int wlistlen= wordList.size();
    for(int i=0; i<wlistlen; i++){
        for(int j=i+1; j<wlistlen; j++){
            if(isonewordaway(wordList[i], wordList[j])){
                g.addEdge(wordList[i], wordList[j],true);
            }

        }
    }
    //g.PrintAdjList();
    return g.bfs(beginWord, endWord);
        
}
int main(){
    vector<string> wordli = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength("hit", "cog", wordli);
}