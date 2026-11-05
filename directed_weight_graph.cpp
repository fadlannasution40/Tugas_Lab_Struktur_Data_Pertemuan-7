#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numberVertex;
    vector<vector<int>> adjmatrix;

public:
    Graph(int banyaktitik) {
        numberVertex = banyaktitik;
        adjmatrix.resize(numberVertex, vector<int>(numberVertex, 0));
    }

    
    void addEdge(int i, int j, int weight) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjmatrix[i][j] = weight;
            adjmatrix[j][i] = weight;
        } else {
            cout << "index nonvalid" << endl;
        }
    } 

  
    void printadjmatrix() {
        for (int i = 0; i < numberVertex; i++) {
            for (int j = 0; j < numberVertex; j++) {
                cout << adjmatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

}; 

int main() {
    Graph g(5);
    g.addEdge(0, 1, 1); 
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    cout << "Adjacency Matrix:" << endl;
    g.printadjmatrix();

    return 0;
}
