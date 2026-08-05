class Solution {
public:
    void dfs(vector<vector<int>>& graph,int node,unordered_set<int>& susNodes){
        susNodes.insert(node);
        for(auto n : graph[node]){
            if(susNodes.find(n)==susNodes.end()){
                dfs(graph,n,susNodes);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> susNodes;
        vector<vector<int>> graph(n);
        for(auto vec : invocations){
            graph[vec[0]].push_back(vec[1]);
        }
        dfs(graph,k,susNodes);
        bool putAll=false;
        for(auto vec : invocations){
            int from = vec[0];
            int to = vec[1];
           
            if(susNodes.find(from)==susNodes.end() && susNodes.find(to)!=susNodes.end()){
                putAll=true;
                cout<<"hi";
                break;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(putAll){
                ans.push_back(i);
            }else{
                if(susNodes.find(i)==susNodes.end()){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};