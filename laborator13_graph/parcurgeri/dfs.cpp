#include "header.h"
#include "../structuri/stiva/stiva.h"

void DFS_recursiv(int A[100][100], int n, int i, int M[], vector<int>& L) {
    L.push_back(i);
    M[i] = 1;
    for (int k = 1; k <= n; ++k) {
        if (A[i][k] != 0 && M[k] == 0)
            DFS_recursiv(A, n, k, M, L);
    }
}

void DFS_iterativ(int A[100][100], int n, int i, int M[], vector<int>& L) {
    Stack s = nullptr;
    push(s, i);

    while (!isEmpty(s)) {
        int j = top(s);
        pop(s);
        if (!M[j]) {
            L.push_back(j);
            M[j] = 1;
            for (int k = n; k >= 1; --k) {
                if (A[j][k] == 1)
                    push(s, k);
            }
        }
    }
}

int main() {
    int n, m;
    int A[100][100] = {0}; // matrice de adiacență

    cout << "Numar noduri: ";
    cin >> n;
    cout << "Numar arce: ";
    cin >> m;

    cout << "Introdu " << m << " muchii (i j):\n";
    for (int x = 0; x < m; ++x) {
        int i, j;
        cin >> i >> j;
        A[i][j] = 1;
        // pentru graf neorientat: A[j][i] = 1;
    }

    int start;
    cout << "Nod de start pentru DFS: ";
    cin >> start;

    // DFS recursiv
    vector<int> dfs_rec;
    int M1[100] = {0};
    DFS_recursiv(A, n, start, M1, dfs_rec);

    cout << "DFS Recursiv: ";
    for (int x : dfs_rec) cout << x << ' ';
    cout << '\n';

    // DFS iterativ
    vector<int> dfs_it;
    int M2[100] = {0};
    DFS_iterativ(A, n, start, M2, dfs_it);

    cout << "DFS Iterativ: ";
    for (int x : dfs_it) cout << x << ' ';
    cout << '\n';

    return 0;
}


