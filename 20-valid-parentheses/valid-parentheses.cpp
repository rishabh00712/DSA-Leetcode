class Solution {
public:
    bool validParentheses(char s,char e){
        if(s=='('){
            return e==')';
        }
        if(s=='{'){
            return e=='}';
        }
        if(s=='['){
            return e==']';
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> store;
        for(auto c : s){
            if(c==')' || c=='}' || c==']'){
                if(store.empty()){
                    return false;
                }
                char start = store.top();
                
                store.pop();
                if(!validParentheses(start,c)){
                    return false;
                }
            }else{
                 store.push(c);
            }
           
        }
        return store.empty();
    }
};
//O(n)
//O(1)