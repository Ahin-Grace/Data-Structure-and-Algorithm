#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, int N, vector<vector<pair<int, int> > >& adj) {
    vector<int> dist(N + 1, INT_MAX);

    priority_queue<pair<int, int>,
                   vector<pair<int, int> >,
                   greater<pair<int, int> > > pq;

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        pair<int, int> topElement = pq.top();
        pq.pop();

        int d = topElement.first;
        int u = topElement.second;

        if (d > dist[u])
            continue;

        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    int T;
    cin >> T;
    vector<int> answers;

    while (T--) {
        int N, M, L;
        cin >> N >> M >> L;

        vector<int> B(L);

        for (int i = 0; i < L; i++)
            cin >> B[i];

        vector<vector<pair<int, int> > > adj(N + 1);
        map<pair<int, int>, int> edgeWeight;

        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));

            edgeWeight[make_pair(u, v)] = w;
            edgeWeight[make_pair(v, u)] = w;
        }

        map<int, vector<int> > distFrom;

        for (int i = 0; i < L; i++) {
            if (distFrom.find(B[i]) == distFrom.end()) {
                distFrom[B[i]] = dijkstra(B[i], N, adj);
            }
        }

        bool valid = true;
        int K = 1;
        int prevIdx = 0;

        for (int i = 1; i < L; i++) {
            int u = B[i - 1];
            int v = B[i];

            int w = -1;

            if (edgeWeight.find(make_pair(u, v)) != edgeWeight.end())
                w = edgeWeight[make_pair(u, v)];

            int du = distFrom[B[prevIdx]][u];
            int dv = distFrom[B[prevIdx]][v];

            if (w == -1 || du == INT_MAX || du + w != dv) {
                if (distFrom[B[prevIdx]][B[i - 1]] == INT_MAX) {
                    valid = false;
                    break;
                }

                K++;
                prevIdx = i - 1;

                du = distFrom[B[prevIdx]][u];
                dv = distFrom[B[prevIdx]][v];

                if (w == -1 || du == INT_MAX || du + w != dv) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid)
            answers.push_back(K);
        else
            answers.push_back(-1);
    }

    cout<<"Output: "<<endl;

    for (int i = 0; i < answers.size(); i++) {
        cout << answers[i] << endl;
    }
    return 0;
}
