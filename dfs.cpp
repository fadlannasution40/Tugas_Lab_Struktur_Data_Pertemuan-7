#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int numberVertex;
    vector<vector<int>> adjmatrix;
    void dfsUtil(int currentvertex, vector<bool>& visited);

public:
    Graph(int banyaktitik);
    void addEdge(int i, int j);
    void printadjmatrix();
    void dfs(int startvertex);
};

Graph::Graph(int banyaktitik) {
    numberVertex = banyaktitik;
    adjmatrix.resize(numberVertex, vector<int>(numberVertex, 0));
}

void Graph::addEdge(int i, int j) {
    if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
        adjmatrix[i][j] = 1;
        adjmatrix[j][i] = 1;
    } else {
        cout << "index nonvalid" << endl;
    }
}

void Graph::printadjmatrix() {
    for (int i = 0; i < numberVertex; i++) {
        for (int j = 0; j < numberVertex; j++) {
            cout << adjmatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::dfs(int startvertex) {
    vector<bool> visited(numberVertex, false);
    dfsUtil(startvertex, visited);
    cout << endl;
}

void Graph::dfsUtil(int currentvertex, vector<bool>& visited) {
    visited[currentvertex] = true;
    cout << "visited: " << currentvertex << " ";
    for (int i = 0; i < numberVertex; i++) {
        if (adjmatrix[currentvertex][i] == 1 && !visited[i]) {
            dfsUtil(i, visited);
        }
    }
}

int main() {
    Graph g(9);  
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 8);

    g.printadjmatrix();
    cout << "DFS traversal starting from vertex 0:" << endl;
    g.dfs(0);

    return 0;
}
