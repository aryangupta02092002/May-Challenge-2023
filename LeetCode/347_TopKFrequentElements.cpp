class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> u;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;
        for(auto i : nums){
            u[i]++;
        }
        for(auto &i : u){
            min_heap.push({i.second, i.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return ans;
    }
};
