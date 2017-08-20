#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph{

private:
    vector< vector<int> > graph;
    int n;
    vector<bool> visit;

    void topoSortRec(int v,stack<int> &topoStack);
    int detectCycleRec(int v,vector<bool> &currStack);

public:

    Graph(int size){
        n = size;
        graph.resize(n);
        visit.resize(n);
    }

    void addEdge(int s,int d){
        graph[s].push_back(d);
    }

    void topoSort();
    int detectCycle();

};

void Graph::topoSort(){

    fill(visit.begin(),visit.end(),0);

    stack<int> topoStack;

    for(int i=0;i<n;i++)
        if(visit[i] == false)
            topoSortRec(i,topoStack);

    while(!topoStack.empty()){
        cout<<topoStack.top()<<" ";
        topoStack.pop();
    }
    cout<<endl;
}

void Graph::topoSortRec(int v,stack<int> &topoStack){

    visit[v] = true;

    for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++){
        if(visit[*it] == false){
            topoSortRec(*it,topoStack);
        }
    }

    topoStack.push(v);
}

int Graph::detectCycle(){

    fill(visit.begin(),visit.end(),0);
    vector<bool> currStack(n);
    fill(currStack.begin(),currStack.end(),0);

    for(int i=0;i<n;i++){
        if(visit[i] == false){
            if(detectCycleRec(i,currStack)){
                return 1;
            }
        }
    }

    return 0;
}

int Graph::detectCycleRec(int v,vector<bool> &currStack){

    visit[v] = true;
    currStack[v] = true;

    vector<int>::iterator it;

    for(it = graph[v].begin(); it != graph[v].end(); it++){
        if(visit[*it] == false){
            if(detectCycleRec(*it,currStack)){
                return 1;
            }
        }
        else if(currStack[*it]){
            return 1;
        }
    }

    currStack[v] = false;

    return 0;
}

int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    //g.topoSort();
    cout<<endl;

    if(g.detectCycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";

    cout<<endl;
    return 0;
}