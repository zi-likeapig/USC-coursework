#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <climits>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

//-----------------------------------------------------------------------------
// Performs DFS search from root and returns the visited nodes in DFS order.
// When there is a choice, the node with lower value should be visited first.
std::vector<int> Graph::DFS(int root) {
    std::vector<int> visited;
    std::map<int, bool> marks;
    DFS_helper(root,marks,visited);
    return visited;
}
   
// Performs DFS search on all nodes and returns the visited nodes in DFS
// order. When there is a choice, the node with lower value should be visited
// first. Note that this function does not take any inputs.
std::vector<int> Graph::DFSAll() {
    std::vector<int> visited;
    std::map<int, bool> marks;
    for(auto& pair:adjacency_list_) {
        DFS_helper(pair.first,marks,visited);
    }
    return visited;
}
   
// Performs BFS search from root and returns a result of type BFSReturnValue,
// which has the following:
// 1. result.visited (vector): visited nodes in BFS order.
// 2. result.path (map): a map of node i to a vector, where the vector is the
// shortest path from root to i.
// 3. result.distance (vector): element i represents the shortest distance
// from root to node i.
//
// Assume root is a valid node in the graph.
BFSReturnValue Graph::BFS(int root) {
    BFSReturnValue rst;
    std::vector<int> previous;
    BFS_helper(root, rst.distance, previous, rst.visited);

    //use previous to find path
    auto it=adjacency_list_.end();
    --it;
    int max_node=it->first;
    //std::cout<<"max_node="<<max_node<<std::endl;

    for(int i=0;i<max_node+1;i++) {
        //std::cout<<std::endl;
        //std::cout<<i<<std::endl;

        if(previous[i]==-1 && i!=root)  { //no path
            rst.path[i]={};
            continue;
        }

        std::vector<int> p;
        int now_node=i;
        while(previous[now_node]!=-1) {
            p.push_back(now_node);
            now_node=previous[now_node];
            //std::cout<<now_node<<"->";
        }
        if(now_node==root) p.push_back(root);
        else printf("find path something error!\n");

        std::reverse(p.begin(),p.end());
        rst.path[i]=p;
    }

    return rst;
}
   
// Returns true if there is at least one path between nodes i and j.
// Assume i, j are valid nodes in the graph.
bool Graph::IsPathBetweenNodes(int i, int j) {
    if(i==j) return true;

    std::unordered_set<int> marks;    //record whether one node has been visited
    marks.insert(i);

    std::queue<int> q;
    q.push(i);
    while(!q.empty()) {
        int now=q.front();
        q.pop();
        for(auto neighbor : adjacency_list_[now]) {
            if(neighbor==j) return true;    //find;
            if(!marks.count(neighbor)) {    // haven't visited
                q.push(neighbor);
                marks.insert(neighbor);
            }
        }
    }
    return false;
}
   
// Returns true if the graph is bidirectional. A bidirectional graph is a
// graph in which if edge (i,j) is in E, then the edge (j,i) is also in E.
// An empty graph is considered bidirectional.
// A graph of a single node is considered bidirectional.
bool Graph::IsBidirectional() {
    if(adjacency_list_.empty()) return true;

    for(auto& pair:adjacency_list_) {
        for(auto& neighbor:pair.second) {
            if(!adjacency_list_[neighbor].count(pair.first)) {   //doesn't find this node in it's neighbor's neighbor
                return false;
            }
        }
    }
    return true;
}
   
// Returns true if the graph is connected, i.e. if we start from each node, we
// can get to any other node.
bool Graph::IsConnected() {
    std::vector<int> visited;
    std::map<int, bool> marks;
    DFS_helper(adjacency_list_.begin()->first,marks,visited);
    return visited.size()==adjacency_list_.size();  //# of node visited == # of node
}
   
// Returns true if start_node can reach a cycle
bool Graph::ReachesACycle(int start_node) {
    //use BFS
    /*std::unordered_set<int> marks; 
    marks.insert(start_node);

    std::queue<int> q;
    q.push(start_node);
    while(!q.empty()) {
        int now_node=q.front();
        q.pop();
        for(auto& neighbor:adjacency_list_[now_node]) {
            if(marks.count(neighbor)) return false;     //neighbor has been visited -> has cycle
            else {
                marks.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    return false;*/

    //use DFS
    std::map<int, NodeStatus> status;
    for(auto& pair:adjacency_list_) {   //initialize
        status[pair.first]=NodeStatus::NotVisited;
    }

    //if(ReachesACycleHelper(start_node, status)) std::cout<<"yes!!!!!!"<<std::endl;
    //else std::cout<<"no!!!!!!!!!"<<std::endl;

    return ReachesACycleHelper(start_node, status);
}
   
// Returns true if the graph has any cycles
bool Graph::HasCycle() {
    for(auto& pair:adjacency_list_) {
        //std::cout<<pair.first;
        if(ReachesACycle(pair.first)) {
            //std::cout<<"has cycle"<<std::endl;
            return true;
        }

    }
    //std::cout<<"not has cycle"<<std::endl;;
    return false;
}
   
// Helper function for ReachesACycle
bool Graph::ReachesACycleHelper(int start_node, std::map<int, NodeStatus> &status) {
    //std::cout<<"---->"<<start_node<<std::endl;
    if(status[start_node]==NodeStatus::Visiting) return true;

    status[start_node]=NodeStatus::Visiting;
    bool has_cycle=false;
    for(auto& neighbor:adjacency_list_[start_node]) {
        if(status[neighbor]!=NodeStatus::Visited) {
            if(ReachesACycleHelper(neighbor, status)) return true;
        }
    }
    status[start_node]=NodeStatus::Visited;
    return false;
}
   
// Optionally you can implement and use these functions.
void Graph::DFS_helper(int root, std::map<int, bool> &marks,std::vector<int> &visited) {
    if(marks[root]) return;

    marks[root]=true;
    visited.push_back(root);

    for(auto& neighbor : adjacency_list_[root]) {
        if(!marks[neighbor]) DFS_helper(neighbor,marks,visited);
    }
}
   
void Graph::BFS_helper(int root, std::vector<int> &distance,std::vector<int> &previous, std::vector<int> &visited) {
    //get the max node in graph (last in map)
    auto it=adjacency_list_.end();
    --it;
    int max_node=it->first;
    //std::cout<<"max_node="<<max_node<<std::endl;

    distance.assign(max_node+1,INT_MAX);
    distance[root]=0;

    previous.assign(max_node+1,-1);

    visited.clear();
    visited.push_back(root);

    std::queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now=q.front();
        q.pop();
        for(auto neighbor : adjacency_list_[now]) {
            if(distance[neighbor]==INT_MAX) {
                visited.push_back(neighbor);
                q.push(neighbor);
                distance[neighbor]=distance[now]+1;
                previous[neighbor]=now;
            }
        }
    }
    //std::cout<<"end of BFShelper"<<std::endl;
}
