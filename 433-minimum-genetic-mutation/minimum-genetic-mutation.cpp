class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> libeary;
        for(auto s : bank){
            libeary.insert(s);
        }
        queue<string> store;
        store.push(startGene);
        int num=0;
        while(!store.empty()){
            int size=store.size();
            for(int i=0;i<size;i++){
                string topGene=store.front();
                if(topGene==endGene) return num;
                vector<char> allPosChar={'A','C','G','T'};
                for(int j=0;j<8;j++){
                    for(auto c : allPosChar){
                        if(c!=topGene[j]){
                            char temp=topGene[j];
                            topGene[j]=c;
                            if(libeary.find(topGene)!=libeary.end()){
                                store.push(topGene);
                                libeary.erase(topGene);
                            }
                            topGene[j]=temp;
                        }
                    }
                }
                store.pop();
            }
            num++;
        }
        return -1;
    }
};