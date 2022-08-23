#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
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
    //All Nodes 
    //HashMap
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

};
int main(){
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);

    g.addEdge("Delhi", "London");
    g.addEdge("New York","London");
    g.addEdge("Delhi", "Paris");

    g.PrintAdjList();
}