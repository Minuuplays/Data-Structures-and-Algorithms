#include <bits/stdc++.h>
using namespace std;

// Build adjacency matrix from edge list
vector<vector<int>> createGraph(int n, vector<vector<int>>& edges) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (auto& it : edges) {
        int u = it[0], v = it[1];
        mat[u][v] = 1;
        mat[v][u] = 1;   // undirected: symmetric
    }
    return mat;
}

// BFS traversal from vertex 'str'
void BFS(int str, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[str] = true;
    q.push(str);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// DFS traversal helper (recursive)
void DFS_Visit(int v, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";
    int n = adj.size();
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS_Visit(i, adj, visited);
        }
    }
}

// DFS traversal from vertex 'str'
void DFS(int str, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    DFS_Visit(str, adj, visited);
}

int main() {
    int n = 8;
    vector<vector<int>> edge;
    edge.push_back({1, 2});
    edge.push_back({1, 3});
    edge.push_back({2, 4});
    edge.push_back({2, 5});
    edge.push_back({3, 6});
    edge.push_back({5, 6});
    edge.push_back({4, 7});
    edge.push_back({6, 7});

    vector<vector<int>> mat = createGraph(n, edge);

    cout << "Adjacency Matrix Representation:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    cout << "\nBFS Traversal (from vertex 1):" << endl;
    BFS(1, mat);
    cout << endl;

    cout << "\nDFS Traversal (from vertex 1):" << endl;
    DFS(1, mat);
    cout << endl;

    return 0;
}