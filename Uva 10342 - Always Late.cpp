//
//  main.cpp
//  Uva 10342 - Always Late
//
//  Created by S M HEMEL on 10/8/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct edge {
    int to, v;
    edge(int a, int b):
    to(a), v(b) {}
};
vector<edge> g[105];
#define oo 0xfffffff
void spfa(int st, int n, int dis[]) {
    int i, tn;
    int used[105] = {};
    queue<int> Q;
    for(i = 0; i < n; i++)
        dis[i] = oo;
    dis[st] = 0;
    Q.push(st);
    while(!Q.empty()) {
        tn = Q.front();
        Q.pop();
        used[tn] = 0;
        for(vector<edge>::iterator it = g[tn].begin();
            it != g[tn].end(); it++) {
            if(dis[it->to] > dis[tn] + it->v) {
                dis[it->to] = dis[tn] + it->v;
                if(used[it->to] == 0) {
                    used[it->to] = 1;
                    Q.push(it->to);
                }
            }
        }
    }
}
struct E {
    int node, g, h;
    E(int a, int b, int c):
    node(a), g(b), h(c) {}
    bool operator<(const E &a) const {
        return g + h > a.g + a.h;
    }
};
void sol_kpath(int st, int ed, int k, int node) {
    int H[105];
    int cntkpath[105], kpath[105];
    spfa(ed, node, H);
    for(int i=0; i<node; i++){
        cntkpath[i] = 0;
        kpath[i] = -1;
    }
    cntkpath[st] = 0; // st->st 0
    kpath[st] = -1;
    priority_queue<E, vector<E> > pQ;
    E tn(0,0,0);
    pQ.push(E(st,0,H[st]));
    while(!pQ.empty()) {
        tn = pQ.top();
        pQ.pop();
        //printf("%d %d %d\n", tn.node, tn.g, tn.h);
        if(cntkpath[tn.node] >= k ||
           kpath[tn.node] == tn.g+tn.h)
            continue;
        cntkpath[tn.node]++;
        kpath[tn.node] = tn.g+tn.h;
        if(tn.node == ed && cntkpath[tn  .node] == k) {
            printf("%d\n", tn.g);
            return;
        }
        for(vector<edge>::iterator it = g[tn.node].begin();
            it != g[tn.node].end(); it++) {
            pQ.push(E(it->to, tn.g + it->v, H[it->to]));
        }
    }
    puts("?");
}
int main() {
    int node, m, q, cases = 0;
    int u, v, w;
    while(scanf("%d%d",&node,&m) == 2) {
        for(int i=0; i<node; i++)
            g[i].clear();
        while(m--) {
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(edge(v, w));
            g[v].push_back(edge(u, w));
        }
        printf("Set #%d\n", ++cases);
        scanf("%d",&q);
        while(q--) {
            scanf("%d %d", &u, &v);
            sol_kpath(u, v, 2, node);
        }
    }
    return 0;
}
