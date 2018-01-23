//
// Created by ealvarenga on 08/12/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>

#ifndef ALL_GRAPH_H
#define ALL_GRAPH_H
typedef map<string, vector<string>> Graph;

typedef map<string, int> Distance;

Distance BFS(Graph g, string strart) {
    Distance d;

    for(Graph::iterator it = g.begin(); it != g.end(); it++) d[*it->first] = -1; //mapeia as distance pela chave e start como não visitado

    d[start] = 0;

    queue<string> q;

    q.push(start);

    while(!q.empty()) {
        string explorer = q.front();
        q.pop();

        for(auto it = g[explorer].begin(); it != g[explorer].end(); it++) {
            if(d[*it] == -1) {
                q.push(*it);
                d[*it] = d[explorer] + 1;
            }

        }
    }

    return d;

}

#endif //ALL_BFS_H
