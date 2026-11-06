#include <iostream>
#include <queue>
using namespace std;

const int V1 = 6; 

int adjMatrix[V1][V1];

void tambahEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void BFS(int start) {
    bool visited[V1] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "\nUrutan BFS mulai dari vertex " << (char)('A' + start) << ": ";
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << (char)('A' + curr) << " ";
        for (int i = 0; i < V1; i++)
            if (adjMatrix[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
    }
    cout << endl;
}

void tampilMatrix() {
    cout << "\nAdjacency Matrix:" << endl;
    cout << "  ";
    for (int i = 0; i < V1; i++) cout << (char)('A' + i) << " ";
    cout << endl;
    for (int i = 0; i < V1; i++) {
        cout << (char)('A' + i) << " ";
        for (int j = 0; j < V1; j++) cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

int main() {

    for (int i = 0; i < V1; i++)
        for (int j = 0; j < V1; j++)
            adjMatrix[i][j] = 0;

    int jumlahEdge;
    cout << "Masukkan jumlah edge: ";
    cin >> jumlahEdge;

    cout << "Masukkan edge (contoh: A B):" << endl;
    for (int i = 0; i < jumlahEdge; i++) {
        char u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        int a = toupper(u) - 'A';
        int b = toupper(v) - 'A';
        if (a >= 0 && a < V1 && b >= 0 && b < V1)
            tambahEdge(a, b);
        else {
            cout << "  [!] Vertex tidak valid, dilewati." << endl;
            i--;
        }
    }

    tampilMatrix();

    char startVertex;
    cout << "\nMasukkan vertex awal BFS (A-F): ";
    cin >> startVertex;
    int start = toupper(startVertex) - 'A';

    if (start >= 0 && start < V1) BFS(start);
    else cout << "Vertex tidak valid!" << endl;

    return 0;
}
