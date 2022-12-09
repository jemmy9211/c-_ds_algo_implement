#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    bool havecycle(int v,bool visited[],bool rs[]);
    public:
        Graph(int V);
        void addedge(int v,int w);
        bool iscyclic();
};

Graph::Graph(int V){
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addedge(int v,int w){
    adj[v].push_back(w);
}

bool Graph::havecycle(int v,bool visited[],bool rs[]){
    if(visited[v]==false){
        visited[v]=true;
        rs[v]=true;
        list<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i] && havecycle(*i,visited,rs)){
                return true;
            }else if(rs[v]==true){
                return true;
            }
        }
    }
    rs[v]=false;
    return false;
}

bool Graph::iscyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if ( !visited[i] && havecycle(i, visited, recStack))
            return true;
 
    return false;
}

int main(){
    Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
 
    if(g.iscyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
    return 0;
}