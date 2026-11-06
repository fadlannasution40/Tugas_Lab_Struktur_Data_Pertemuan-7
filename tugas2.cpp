#include <iostream>
#include <climits>
using namespace std;

const int V2 = 6;
const int INF = INT_MAX;

int kota[V2][V2];

void inisialisasiKota() {
    for (int i = 0; i < V2; i++)
        for (int j = 0; j < V2; j++)
            kota[i][j] = 0;

    kota[0][1] = kota[1][0] = 4;
    kota[0][2] = kota[2][0] = 2;
    kota[1][2] = kota[2][1] = 1;
    kota[1][3] = kota[3][1] = 5;
    kota[1][4] = kota[4][1] = 3;
    kota[2][3] = kota[3][2] = 8;
    kota[2][4] = kota[4][2] = 6;
    kota[3][4] = kota[4][3] = 2;
    kota[3][5] = kota[5][3] = 4;
    kota[4][5] = kota[5][4] = 3;
}

int minJarak(int dist[], bool visited[]) {
    int min = INF, minIdx = -1;
    for (int v = 0; v < V2; v++)
        if (!visited[v] && dist[v] <= min) { min = dist[v]; minIdx = v; }
    return minIdx;
}

void dijkstra(int src, int dist[], int parent[]) {
    bool visited[V2] = {false};
    for (int i = 0; i < V2; i++) { dist[i] = INF; parent[i] = -1; }
    dist[src] = 0;
    for (int count = 0; count < V2 - 1; count++) {
        int u = minJarak(dist, visited);
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < V2; v++)
            if (!visited[v] && kota[u][v] != 0 && dist[u] != INF &&
                dist[u] + kota[u][v] < dist[v]) {
                dist[v] = dist[u] + kota[u][v];
                parent[v] = u;
            }
    }
}

void cetakRute(int parent[], int dest) {
    if (parent[dest] == -1) { cout << (char)('A' + dest); return; }
    cetakRute(parent, parent[dest]);
    cout << " -> " << (char)('A' + dest);
}

void tampilSemuaRute(int src) {
    int dist[V2], parent[V2];
    dijkstra(src, dist, parent);
    cout << "\nRute terpendek dari " << (char)('A' + src) << " ke semua lokasi:" << endl;
 
    for (int i = 0; i < V2; i++) {
        if (i == src) continue;
        cout << "  " << (char)('A' + src) << " -> " << (char)('A' + i) << "  ";
        if (dist[i] == INF) cout << "Tidak ada rute" << endl;
        else { cetakRute(parent, i); cout << "  " << dist[i] << " km" << endl; }
    }
;
}

void rekomendasiRute() {
    char dari, ke;
    cout << "\nInput lokasi asal  (A-F): "; cin >> dari;
    cout << "Input lokasi tujuan (A-F): "; cin >> ke;
    int src = toupper(dari) - 'A', dest = toupper(ke) - 'A';
    if (src < 0 || src >= V2 || dest < 0 || dest >= V2) { cout << "Lokasi tidak valid!" << endl; return; }
    if (src == dest) { cout << "Anda sudah berada di lokasi tujuan!" << endl; return; }
    int dist[V2], parent[V2];
    dijkstra(src, dist, parent);
    cout << "\n REKOMENDASI RUTE " << endl;
    cout << "Dari : " << (char)('A' + src) << endl;
    cout << "Ke   : " << (char)('A' + dest) << endl;
    if (dist[dest] == INF) cout << "Tidak ada rute yang tersedia." << endl;
    else { cout << "Rute : "; cetakRute(parent, dest); cout << endl; cout << "Jarak: " << dist[dest] << " km" << endl; }
}

int main() {
    inisialisasiKota();

    cout << "\nPeta jarak antar lokasi (km):" << endl;
    cout << "A-B:4  A-C:2" << endl;
    cout << "B-C:1  B-D:5  B-E:3" << endl;
    cout << "C-D:8  C-E:6" << endl;
    cout << "D-E:2  D-F:4" << endl;
    cout << "E-F:3" << endl;

    tampilSemuaRute(0);

    char lagi;
    do {
        rekomendasiRute();
        cout << "\nCari rute lain? (y/n): ";
        cin >> lagi;
    } while (tolower(lagi) == 'y');

    return 0;
}
