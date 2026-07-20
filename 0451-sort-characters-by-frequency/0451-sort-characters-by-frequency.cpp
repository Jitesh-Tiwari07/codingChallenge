class Solution {
public:
    static bool cmp(pair<char,int>a,pair<char,int>b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(auto it: s){
            m[it]++;
        }
        string ans="";
        vector<pair<char,int>>temp;
        for(auto it: m){
            temp.push_back({it.first,it.second});
        }
        sort(temp.begin(),temp.end(),cmp);
        for(int i=0;i<temp.size();i++){
            while(temp[i].second!=0){
                ans+=temp[i].first;
                temp[i].second--;
            }
        }
        return ans;
        
    }
};