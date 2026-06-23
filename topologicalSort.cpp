#include <iostream>
using namespace std;

const int MAX = 100;

int adjMatrix[MAX][MAX];   // adjacency matrix
int inDegree[MAX];
int queueArr[MAX];         // manual queue using array
int topoOrder[MAX];

void topologicalSortKahn(int V) {
    // Step 1: Compute in-degree of each vertex
    for (int u = 0; u < V; u++) {
        inDegree[u] = 0;
    }
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] == 1) {
                inDegree[v]++;
            }
        }
    }

    // Step 2: Manual queue setup (front and rear pointers)
    int front = 0, rear = 0;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            queueArr[rear] = i;
            rear++;
        }
    }

    int topoIndex = 0;
    int count = 0;

    // Step 3: Process the queue
    while (front < rear) {
        int u = queueArr[front];
        front++;
        topoOrder[topoIndex] = u;
        topoIndex++;
        count++;

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] == 1) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queueArr[rear] = v;
                    rear++;
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != V) {
        cout << "Graph contains a cycle. Topological sort not possible." << endl;
        return;
    }

    cout << "Topological Order: ";
    for (int i = 0; i < topoIndex; i++) {
        cout << topoOrder[i] << " ";
    }
    cout << endl;
}

int main() {
    int V = 6;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Example DAG edges
    adjMatrix[5][2] = 1;
    adjMatrix[5][0] = 1;
    adjMatrix[4][0] = 1;
    adjMatrix[4][1] = 1;
    adjMatrix[2][3] = 1;
    adjMatrix[3][1] = 1;

    topologicalSortKahn(V);

    return 0;
}

/*  -- using vector and queue from STL --
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSortKahn(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);

    // Step 1: Compute in-degree of each vertex
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 2: Enqueue all vertices with in-degree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    int count = 0;

    // Step 3: Process the queue
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);
        count++;

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Step 4: Check for cycle
    if (count != V) {
        cout << "Graph contains a cycle. Topological sort not possible." << endl;
        return;
    }

    cout << "Topological Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Example DAG edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    topologicalSortKahn(V, adj);

    return 0;
}
*/    