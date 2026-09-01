class Solution {
    struct cmp{
        bool operator()(pair<int,string> a, pair<int,string> b){
            if(a.first!=b.first)
                return a.first<b.first;

            return a.second>b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;

        unordered_map<string,int> m;
        for(auto word:words){
            m[word]++;
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto i:m){
            string word=i.first;
            int freq=i.second;
            pq.push({freq,word});
        }

        while(k--){
            pair<int,string> p=pq.top();
            pq.pop();

            string word=p.second;
            ans.push_back(word);
        }

        return ans;
    }
};