#include "q.h"

#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// Implement each function of `q.h` here.

// Returns a map of a node to a set of its predecessors.
std::map<int, std::set<int>> Graph::GetPredecessors() {
    // u->v
    std::map<int, std::set<int>> pre;
    //std::map<int, std::set<std::pair<int, int>>> weight_map_;
    for(auto& u:weight_map_) {
        pre[u.first];
        for(auto& v:u.second) {
            pre[v.first].insert(u.first);
        }
    }
    return pre;
}

// Returns a set of all (u,v) edges in a graph.
std::set<std::pair<int, int>> Graph::GetEdges() {
    std::set<std::pair<int, int>> edges;
    //std::map<int, std::set<std::pair<int, int>>> weight_map_;
    for(auto& u:weight_map_) {
        for(auto& v:u.second) {
            edges.insert({u.first,v.first});
        }
    }
    return edges;
}

// Returns the weight of the (i,j) edge. Returns INT_MAX if no edge between
// them exits.
int Graph::GetWeight(int i, int j) {
    for(auto& v:weight_map_[i]) {
        if(v.first==j) return v.second;
    }
    return INT_MAX;
}

// Returns the weight of the minimum edge in the graph.
int Graph::GetMinWeight() {
    int minWeight=INT_MAX;
    for(auto& u:weight_map_) {
        for(auto& v:u.second) {
            minWeight=std::min(minWeight,v.second);
        }
    }
    return minWeight;
}

// Returns a vector of size n, which has the shortest distances from the
// source to all other nodes in the graph.
std::vector<long> Graph::Dijkstra(int source) {
    int n = 0;
    for (auto& p : weight_map_) {
        n = std::max(n, p.first);
        for (auto& q : p.second) {
            n = std::max(n, q.first);
        }
    }
    n = n + 1;

    std::vector<long> d(n,INT_MAX);
    std::vector<bool> visited(n,false);
    d[source]=0;
    visited[source]=true;

    int cnt_visited=1;
    for(auto& v:weight_map_[source]) {
        d[v.first]=v.second;
    }

    while(cnt_visited<n) {
        //find the min unvisited node
        int min_d=INT_MAX;
        int min_idx=-1;
        for(int i=0;i<d.size();i++) {
            if(visited[i]==false && d[i]<min_d) {
                min_d=d[i];
                min_idx=i;
            }
        }

        if (min_idx == -1) break;

        //update the successor of min_idx
        visited[min_idx]=true;
        for(auto& v:weight_map_[min_idx]) {
            d[v.first]=std::min(d[v.first],d[min_idx]+v.second);
        }
        cnt_visited++;
    }
    return d;
}

// Returns a vector of size n, which has the shortest distances from the
// source to all other nodes in the graph using Bellman-Ford algorithm.
//
// Hint for graphs with negative edges:
// In the relaxing step, we normally check:
//
// if (d[u] + w < d[v]) {
//       d[v] = d[u] + w;
// }
//
// However, if d[v]==INT_MAX, d[u]==INT_MAX, and w < 0, then the new value of
// d[v] becomes INT_MAX - |w|, which should still be considered as infinity.
// You should enhance the if statement to protect against this case..
std::vector<long> Graph::BellmanFord(int source) {
    std::vector<long> d(weight_map_.size(),INT_MAX);
    d[source]=0;
    for(auto& v:weight_map_[source]) {
        d[v.first]=v.second;
    }

    //u->v
    std::map<int, std::set<int>> pre=GetPredecessors();
    for(int i=1;i<weight_map_.size()-1;i++) {
        for(int p=0;p<weight_map_.size();p++) {
            for(auto& u:pre[p]) {
                if(d[p]==INT_MAX && d[u]==INT_MAX) continue;
                d[p]=std::min(d[p],d[u]+GetWeight(u,p));
            }
        }
    }

    return d;

}