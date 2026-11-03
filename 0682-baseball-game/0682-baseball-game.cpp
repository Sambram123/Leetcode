class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto ch:operations){
        if(ch=="C"){
            st.pop();
        }
        else if(ch=="D"){
            int n1=st.top()*2;
            st.push(n1);
        }
        else if(ch=="+"){
            int n1=st.top();
            st.pop();
            int n2=st.top()+n1;

            st.push(n1);
            st.push(n2);

        }
        else{
            st.push(stoi(ch));
        }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};