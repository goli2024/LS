#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int tspUtil(const vector<vector<int>>& graph, vector<bool>& visited, int currPos, int n, int count, int cost, int& minCost, vector<int>& tempPath, vector<int>& path) {
    if (count == n && graph[currPos][0] > 0) {
        if (cost + graph[currPos][0] < minCost) {
            minCost = cost + graph[currPos][0];
            path = tempPath;
        }
        return minCost;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i] > 0) {
            visited[i] = true;
            tempPath.push_back(i);
            tspUtil(graph, visited, i, n, count + 1, cost + graph[currPos][i], minCost, tempPath, path);
            visited[i] = false;
            tempPath.pop_back();
        }
    }
    return minCost;
}

int tsp(const vector<vector<int>>& graph, int n) {
    int minCost = INF;
    vector<int> path;
    vector<int> tempPath;
    vector<bool> visited(n, false);
    
    visited[0] = true;
    tempPath.push_back(0);
    tspUtil(graph, visited, 0, n, 1, 0, minCost, tempPath, path);
    
    for (int city : path) {
        cout << city << "->";
    }
    cout << "0" << endl;
    
    return minCost;
}

int main() {
    cout << "Travelling Salesman using Branch and Bound" << endl;
    cout << "Input: Number of cities (n), adjacency matrix (graph)" << endl;
    cout << "Output: Minimum distance path" << endl;
    
    int n;
    cout<<"Enter no of cities"<<endl;
    cin >> n;
    
    vector<vector<int>> graph(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    int result = tsp(graph, n);
    cout << "Minimum cost: " << result << endl;
    
    return 0;
}

