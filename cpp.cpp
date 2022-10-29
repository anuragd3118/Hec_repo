#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

void dfs(int node) {
    for (int i : adjList[node]) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    int v, n;
    cin >> v >> n;
    adjList.resize(v);
    visited = vector<bool>(v, 0);
    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }

    int count = 0;
    vector<int> newRoad;
    for (int i = 0; i < adjList.size(); ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            newRoad.push_back(i);
            ++count;
            dfs(i);
        }
    }

    cout << count - 1 << endl;
    for (int i = 0; i < newRoad.size() - 1; ++i) {
        cout << newRoad[i] + 1 << " " << newRoad[i + 1] + 1 << endl;
    }

    return 0;
}
