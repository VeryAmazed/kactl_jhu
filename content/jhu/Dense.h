/**
 * Author: cp-algos
 * Date: 
 * License: 
 * Description: Dense Djikstra's
 * Time: O(V^2)
 * Status: 
 */
vector<vector<pair<int, int>>> vec;
vector<ll> dists;
vector<int> paths;
vector<bool> visited;
void denseDjik(int start) {
    dists[start] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (v == -1 || dists[j] < dists[v]))
                v = j;
        }
        if (dists[v] == INF) break;
        visited[v] = true;
        for (auto e : vec[v]) {
            int to = e.first;
            int len = e.second;
            if (dists[v] + len < dists[to]) {
                dists[to] = dists[v] + len;
                paths[to] = v;
            }
        }
    }
}