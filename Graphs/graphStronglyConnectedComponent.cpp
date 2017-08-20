#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph{

private:
    vector< vector<int> > graph;
    int n;
    vector<bool> visit;

    void callRecSCC(int v,stack<int> &trace);
    Graph *getTranspose();
    void callRecDFS(int v);

    void clearVisit(){
        fill(visit.begin(),visit.end(),0);
    }

    bool checkVisit(int v){
        if(visit[v])
            return true;

        return false;
    }

public:

    Graph(int size){
        n = size;
        graph.resize(n);
        visit.resize(n);
    }

    void addEdge(int s,int d){
        graph[s].push_back(d);
    }

    void RecSCC();

};

void Graph::RecSCC(){

    clearVisit();

    stack<int> trace;

    for(int i=0;i<n;i++)
        if(visit[i] == false)
            callRecSCC(i,trace);

    Graph *transposeG = getTranspose();

    (*transposeG).clearVisit();

    while(!trace.empty()){
        int v = trace.top();
        trace.pop();

        if((*transposeG).checkVisit(v) == false){
            (*transposeG).callRecDFS(v);
            cout<<endl;
        }
    }

    free(transposeG);

}

void Graph::callRecDFS(int v){

    visit[v] = true;
    cout<<v<<" ";

    vector<int>::iterator iter;

    for(iter = graph[v].begin(); iter != graph[v].end(); iter++){
        if(visit[*iter] == false)
            callRecDFS(*iter);
    }
}

Graph* Graph::getTranspose(){

    Graph *transG = new Graph(n);

    for(int v=0;v<n;v++){
        vector<int>::iterator iter;
        for(iter = graph[v].begin(); iter != graph[v].end(); iter++)
            (*transG).addEdge(*iter,v);
    }

    return transG;

}

void Graph::callRecSCC(int v,stack<int> &trace){

    visit[v] = true;
    vector<int>::iterator iter;

    for(iter = graph[v].begin(); iter != graph[v].end(); iter++){
        if(visit[*iter] == false){
            callRecSCC(*iter,trace);
        }
    }

    trace.push(v);
}

int main(){

    Graph g(7);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(1, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 6);
    g.addEdge(6, 5);
    g.addEdge(5, 4);

    g.RecSCC();
    cout<<endl;

    return 0;
}
