class Solution {
public:
    string reorganizeString(string s) {
        string res="";
        unordered_map<char,int> m;
        for(char c:s){
            m[c]++;
        }


        priority_queue<pair<int,char>> pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }

        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            if(res.size()==0 || res.back()!=p.second){
                res+=p.second;
                p.first--;
                if(p.first>0)
                    pq.push(p);

            }else{
                if(pq.empty()) return "";

                pair<int,char> p2=pq.top();
                pq.pop();

                res+=p2.second;
                p2.first--;
                if(p2.first>0)
                 pq.push(p2);

                  pq.push(p);
            }
        }
        
        return res;
    }
};