class Solution {
public:
    string findKey(string s,int& i){
        string key;
        while(i<s.size() && s[i]!=')'){
            key.push_back(s[i]);
            i++;
        }
        return key;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> KTVMap;//ket to value map
        for(auto pair : knowledge){
            string key=pair[0];
            string val=pair[1];
            KTVMap[key]=val;
        }
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                i++;
                string key=findKey(s,i);
                string val="?";
                if(KTVMap.find(key)!=KTVMap.end()){
                    val=KTVMap[key];
                }
                ans+=val;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};