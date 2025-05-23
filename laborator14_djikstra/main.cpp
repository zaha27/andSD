

int main() {
    int G[100][100] = { {0, 4, 0, 0, 0, 0},
                        {0, 0, 8, 0, 0, 0},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 9, 14},
                        {0, 0, 0, 0, 0, 10},
                        {0, 0, 0, 0, 0, 0} };

    unsigned int dist[100];
    int prev[100];

    int n = 6;
    int sursa = 0;
    dijkstra_algo(G, n, sursa, dist, prev);

    for (int i = 0; i < n; ++i)
        std::cout << "Distanta minima de la " << sursa << " la " << i << " este " << dist[i] << "\n";
}
