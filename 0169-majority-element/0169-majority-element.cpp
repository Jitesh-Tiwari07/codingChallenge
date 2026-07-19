class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])){
                m[nums[i]]++;
            }
            else{
                m[nums[i]]=1;
            }
        }
        int ans=0;
        int real=0;
        for(auto it: m){
            if(ans<it.second){     //if(it.second>nums.size()/2){
                ans=it.second;          //return it.first
                real=it.first;      //}
            }
        }
        return real;
    }
};