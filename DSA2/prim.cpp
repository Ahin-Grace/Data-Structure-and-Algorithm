#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;

    while (T > 0) {
        T--;

        int N, M;
        cin >> N >> M;

        vector<vector<pair<int,int>>> E(N + 1);

        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            E[u].push_back(make_pair(v, w));
            E[v].push_back(make_pair(u, w));
        }

        vector<bool> inMST(N + 1, false);
        vector<int> parent(N + 1, -1);
        vector<int> key(N + 1, INT_MAX);

        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;

        key[1] = 0;
        pq.push(make_pair(0, 1));

        while (!pq.empty()) {
            pair<int,int> topElement = pq.top();
            pq.pop();
            int u = topElement.second;
            if (inMST[u] == true)
                continue;
            inMST[u] = true;

            for (int i = 0; i < E[u].size(); i++) {
                int v = E[u][i].first;
                int wt = E[u][i].second;

                if (inMST[v] == false && wt < key[v]) {
                    key[v] = wt;
                    parent[v] = u;
                    pq.push(make_pair(wt, v));
                }
            }
        }

        for (int v = 2; v <= N; v++) {
            if (parent[v] != -1)
                cout << parent[v] << " " << v << " " << key[v] << endl;
        }
    }
    return 0;
}
