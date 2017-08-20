#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph{

private:
    vector< vector<int> > graph;
    int n;
    vector<bool> visit;

    int callCheckBipartite(vector<int> &color,int v,int val);

public:

    Graph(int size){
        n = size;
        graph.resize(n);
        visit.resize(n);
    }

    void addEdge(int s,int d){
        graph[s].push_back(d);
    }

    int CheckBipartite();

};

int Graph::CheckBipartite(){

    fill(visit.begin(),visit.end(),0);
    vector<int> color(n);
    fill(color.begin(),color.end(),-1);

    color[0] = 0;
    for(int i=0;i<n;i++)
        if(visit[i] == false)
            if(callCheckBipartite(color,i,0) == 0)
                return 0;

    return 1;
}

int Graph::callCheckBipartite(vector<int> &color,int v,int val){

    if(graph[v].size() == 0)
        return 1;

    visit[v] = true;
    color[v] = val;

    vector<int>::iterator itr;
    for(itr = graph[v].begin(); itr != graph[v].end(); itr++){
        if(visit[*itr] && color[*itr] == color[v])
            return 0;
        else if(visit[*itr] == false)
            if(callCheckBipartite(color,*itr,(val?0:1)) == 0)
                return 0;

    }

    return 1;
}

int main(){

    Graph g(7);
    g.addEdge(0, 6);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(4, 6);

    //g.topoSort();
    cout<<endl;

    if(g.CheckBipartite())
        cout << "Graph is Bipartite Graph";
    else
        cout << "Graph is not a Bipartite Graph";

    cout<<endl;
    return 0;
}
