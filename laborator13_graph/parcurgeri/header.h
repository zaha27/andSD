// dfs.h

#ifndef DFS_H
#define DFS_H

#include <vector>
#include <stack>
#include <queue>
using namespace std;

void DFS_recursiv(int A[100][100], int n, int i, int M[], vector<int>& L);
void DFS_iterativ(int A[100][100], int n, int i, int M[], vector<int>& L);

#endif
