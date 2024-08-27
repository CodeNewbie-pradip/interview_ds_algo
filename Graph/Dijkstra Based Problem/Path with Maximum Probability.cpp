/*
Leetcode Link               : https://leetcode.com/problems/path-with-maximum-probability/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array, Graph, Shortest Path, Heap(Priority Queue) 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Dijkstra's Algorithm (Modified for Maximum Probability)
//T.C       : O((V + E)log V) 
//S.C       : O(V + E) 
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>>graph(n);
        
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        
        //create maxHeap
        priority_queue<pair<double, int>>pq;
        vector<double>prob(n, 0.0);
        prob[start_node]=1.0;
        
        pq.emplace(1.0, start_node);
        
        while(!pq.empty()){
            auto [currProb, node]=pq.top();
            pq.pop();
            
            if(node==end_node) return currProb;
            
            for(auto [ngbr, edgeProb]: graph[node]){
                double newProb=currProb*edgeProb;
                if(newProb>prob[ngbr]){
                    prob[ngbr]=newProb;
                    pq.emplace(newProb, ngbr);
                }
            }
        }
        return 0.0;
    }
};

//---------------------------------------------------------------------------------------------------------------------
//Approach 2: Bellman-Ford Algorithm (Relaxation for Maximum Probability)
//T.C       : O(V * E) 
//S.C       : O(V) 
//---------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        
        for (int i = 0; i < n - 1; ++i) {
            bool updated = false;
            for (int j = 0; j < edges.size(); ++j) {
                int u = edges[j][0];
                int v = edges[j][1];
                double probUV = succProb[j];
                
                if (prob[u] * probUV > prob[v]) {
                    prob[v] = prob[u] * probUV;
                    updated = true;
                }
                if (prob[v] * probUV > prob[u]) {
                    prob[u] = prob[v] * probUV;
                    updated = true;
                }
            }
            if (!updated) break;
        }
        
        return prob[end_node];
    }
};

//---------------------------------------------------------------------------------------------------------------------