#include <iostream>
#include <limits>
#include "algo.h"
#include "../andSD/laborator14_djikstra/coada/heap.h"
/*
void initHeap(Heap& H, int cap);
void push(Heap& H, Atom val);
Atom top(Heap H);
void pop(Heap& H);
int isEmpty(Heap H);
void destroyHeap(Heap& H);
*/

const unsigned int INF = std::numeric_limits<unsigned int>::max();

void dijkstra_algo(int G[][100], int n, int S, unsigned int dist[], int prev[]) {
    Heap Q;
    initHeap(Q, n * n);

    for(int v = 0; v < n; ++v) {
        dist[v] = INF;
        push(Q, {v, dist[v]});
        prev[v] = -1;
    }
    dist[S] = 0;
    while(!isEmpty(Q)) {
        Atom current = top(Q); pop(Q); 
        int u = current.nod;

        for(int v = 0; v < n; ++v) {
            if(G[u][v]) {
                alt = dist[u] + G[u][v];
                if(alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                }
            }
        }
    }
}