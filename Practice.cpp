#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

void DFS(int node, int delNode, int& count);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    adjList.resize(N);
    visited.resize(N);

    int rootNode;

    for (int i = 0; i < N; i++) {
        int node;
        cin >> node;

        if (node == -1)
            rootNode = i;
        else {
            adjList[i].push_back(node);
            adjList[node].push_back(i);
        }
    }

    int delNode;
    cin >> delNode;

    int count = 0;
    DFS(rootNode, delNode, count);

    cout << count;
}

void DFS(int node, int delNode, int& count) {
    if (node != delNode) {
        visited[node] = true;

        bool flag = true;

        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor] && neighbor != delNode) {
                flag = false;

                DFS(neighbor, delNode, count);
            }
        }

        if (flag)
            count++;
    }
}
