class Solution {
public:
    double soluation(unordered_map<string,vector<pair<string,double>>> &mymap,string cur,string dis,unordered_set<string>& myset){
        if(cur==dis){
            return 1;
        }
        double temp = -1;
        for(auto vec : mymap[cur]){
            string next = vec.first;
            if(myset.find(next)!=myset.end()){
                continue;
            }
            double val = vec.second;
            myset.insert(next);
            temp = soluation(mymap,next,dis,myset);
            if(temp!=-1){
                temp*=val;
                break;
            }
           myset.erase(next);
        }
        return temp;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> mymap;
        int n=values.size();
        for(int i=0;i<n;i++){
            string first=equations[i][0];
            string second=equations[i][1];
            double value=values[i];
            mymap[first].push_back({second,value});
            mymap[second].push_back({first,1.0/value});
        }
       
        vector<double> ans;
        for(auto q : queries){
             unordered_set<string> myset;
             if(mymap.find(q[0])==mymap.end()){
                ans.push_back(-1);
                continue;
             }
            ans.push_back(soluation(mymap,q[0],q[1],myset));
        }
        return ans;
    }
};