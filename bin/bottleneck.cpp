#include <bits/stdc++.h>
using namespace std;

vector <vector <pair <int, int> > > conn;
queue <pair <int, int> > q, qCopy;
vector <int> memory;
bool stop = false;

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C) {
    conn.resize(N);
    memory.resize(N, INT_MAX);
    W--;
    L--;

    for (size_t i = 0; i < M; ++i) {
        conn[arco_da[i] - 1].push_back(make_pair(arco_a[i] - 1, capacita[i]));
        conn[arco_a[i] - 1].push_back(make_pair(arco_da[i] - 1, capacita[i]));
    }

    q.push(make_pair(W, INT_MAX));
    memory[W] = 0;

    while (!stop) {
        swap(q, qCopy);

        while (!qCopy.empty()) {
            pair <int, int> front = qCopy.front();
            qCopy.pop();

            for (size_t i = 0; i < conn[front.first].size(); ++i) {
                int tmp = min(front.second, conn[front.first][i].second);
                //cout << conn[front.first][i].first << "\t" << tmp << "\t" << memory[conn[front.first][i].first] << endl;
                if (memory[conn[front.first][i].first] > tmp) {
                    memory[conn[front.first][i].first] = tmp;
                    q.push(make_pair(conn[front.first][i].first, tmp));
                }
                if (conn[front.first][i].first == L)
                    stop = true;
            }
        }        
    }
    
    return memory[L];
}
