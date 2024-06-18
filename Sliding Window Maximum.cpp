class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> maxi(k);

        for(int i=0; i<k; i++) {

            while(!maxi.empty() && nums[maxi.back()] <= nums[i])
                maxi.pop_back();

            maxi.push_back(i);
        }

        ans.push_back(nums[maxi.front()]);
        
        for(int i=k; i<n; i++) {

            //next window

            //removal
            if(!maxi.empty() && i - maxi.front() >=k) {
                maxi.pop_front();
            }

            //addition

            while(!maxi.empty() && nums[maxi.back()] <= nums[i])
                maxi.pop_back();

            maxi.push_back(i);    

            ans.push_back(nums[maxi.front()]);
        }
        return ans;
    }
};
