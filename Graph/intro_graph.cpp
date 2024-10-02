#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>>adj;

    void addEdge(int u,int v,bool direction){
        //direction 0 ->Undirected Graph
        //direction 1 ->Directed Graph
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i : adj ){
            cout<<i.first<<" --> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }cout<<endl;
        }
    }

};
int main(){
    Graph G;

    while(true){

        cout<<"Enter Edge and Direction : ";
        int u,v,d;
        cin>>u>>v>>d;
        if(u==-1 && v==-1 && d==-1){
            break;
        }
        G.addEdge(u,v,d);
    }
    G.print();
}