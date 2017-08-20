#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{

private:
    vector< vector<int> > graph;
    int n;
    vector<bool> visit;

    void dfsRec(int v);

public:
    Graph(int size){
        n = size;
        graph.resize(n);
        visit.resize(n);
    }

    void addEdge(int s,int d){
        graph[s].push_back(d);
    }

    void bfs();

    void dfs();

};

void Graph::bfs(){

    queue<int> bfsQueue;
    fill(visit.begin(),visit.end(),0);

    for(int i=0;i<n;i++){

        if(visit[i] == false){

            visit[i] = true;
            bfsQueue.push(i);

            while(!bfsQueue.empty()){

                int v = bfsQueue.front();
                bfsQueue.pop();

                cout<<"Visited Node : "<<v<<endl;
                for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++){
                    if(visit[*it] == false){
                        visit[*it] = true;
                        bfsQueue.push(*it);
                    }
                }
            }

        }

    }
}

void Graph::dfs(){

    fill(visit.begin(),visit.end(),0);

    for(int i=0;i<n;i++){
        if(visit[i] == false)
            dfsRec(i);
    }
}

void Graph::dfsRec(int v){

    visit[v] = true;
    cout<<"Visited Node : "<<v<<endl;

    for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++){
        if(visit[*it] == false)
            dfsRec(*it);
    }
}

int main(){

    Graph obj(8);

    obj.addEdge(0,1);
    obj.addEdge(0,2);
    obj.addEdge(1,3);
    obj.addEdge(1,4);
    obj.addEdge(2,5);
    obj.addEdge(4,6);
    obj.addEdge(4,7);

    cout<<"BFS Output : "<<endl;
    obj.bfs();

    cout<<"DFS Output : "<<endl;
    obj.dfs();

    return 0;

}