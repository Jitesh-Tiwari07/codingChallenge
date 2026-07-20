class Solution {
public:
    static bool cmp(pair<char,int>a,pair<char,int>b){
        if(a.second==b.second){
            return a.first>b.first;
            
        }
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int ,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int>ans;
        vector<pair<int,int>>temp;
        for(auto it: m){
            temp.push_back({it.first,it.second});
        }
        sort(temp.begin(),temp.end(),cmp);
        for(int i=0;i<temp.size();i++){
            while(temp[i].second!=0){
                ans.push_back(temp[i].first);
                temp[i].second--;
            }
        }
        return ans;
    }
};