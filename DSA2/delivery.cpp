#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, int N, vector<vector<pair<int, int> > >& adj) {
    vector<int> dist(N, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

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
    int N;
    cin >> N;

    vector<vector<pair<int, int> > > T(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int k;
            cin >> k;

            if (i != j)
                T[i].push_back(make_pair(j, k));
        }
    }

    vector<vector<int> > dist(N);

    for (int i = 0; i < N; i++) {
        dist[i] = dijkstra(i, N, T);
    }

    cout<<"Enter the number of scenarios: ";
    int M;
    cin >> M;

    vector<pair<int, int> > ans;

    cout<<"Please enter the restaurant, gas station and delivery street number respectively:"<<endl;

    for (int i = 0; i < M; i++) {
        int S, G, D;
        cin >> S >> G >> D;

        int viaGas = dist[S][G] + dist[G][D];
        int direct = dist[S][D];

        ans.push_back(make_pair(viaGas, viaGas - direct));
    }

    cout<<"Output: "<<endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
