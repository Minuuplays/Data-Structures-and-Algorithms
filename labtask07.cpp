#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int n, vector<vector<int>>& edges) {
vector<vector<int>> mat(n, vector<int>(n, 0));
for (auto& it : edges) {
int u = it[0], v = it[1];
mat[u][v] = 1;
mat[v][u] = 1;
}
return mat;
}
bool DFS_Cycle(int v, int parent, const vector<vector<int>>& adj,
vector<bool>& visited, vector<int>& path) {
visited[v] = true;
path.push_back(v);
int n = adj.size();
for (int i = 0; i < n; i++) {
    if (adj[v][i] == 1) {
        if (!visited[i]) {
            if (DFS_Cycle(i, v, adj, visited, path))
                return true;
        }
        else if (i != parent) {
            // Found a back edge — cycle detected
            path.push_back(i); // close the cycle
            return true;
        }
    }
}

path.pop_back(); // backtrack
return false;
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

int startNode = 1;
vector<bool> visited(n, false);
vector<int> path;

bool hasCycle = DFS_Cycle(startNode, -1, mat, visited, path);

if (hasCycle) {
    cout << "Cycle detected: YES" << endl;

    // Extract and print just the cycle portion
    int cycleStart = path.back();
    cout << "Cycle path: ";
    bool inCycle = false;
    for (int node : path) {
        if (node == cycleStart) inCycle = true;
        if (inCycle) cout << node << " ";
    }
    cout << endl;
} else {
    cout << "Cycle detected: NO" << endl;
}

return 0;
}