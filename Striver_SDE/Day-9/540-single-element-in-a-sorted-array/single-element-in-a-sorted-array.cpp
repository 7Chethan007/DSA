class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        // Base case only one element
        if( n == 1 ) return nums[0];
        // Base case for 0th and nth index
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        // low & high pointer after exclusing the first and last index's
        int low = 1;
        int high = n-2;
        
        // Binary Search
        while(low <= high) {
            int mid = (low + high) / 2;
            
            // Check if middle element is the single element
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            // Check if we are in left or right half of the arr (even,odd) or (odd,even)
            // In left side
            if((mid % 2 == 0 && nums[mid] == nums[mid+1] )||  // left even
              (mid % 2 == 1 && nums[mid] == nums[mid-1] ) ) // left odd 
                                {
                                    low = mid + 1;
                                }
            // In right side
            if((mid % 2 == 0 && nums[mid] == nums[mid-1] )||  // left even
              (mid % 2 == 1 && nums[mid] == nums[mid+1] ) ) // left odd 
                                {
                                    high = mid - 1;
                                }
                
        }
        return -1;

    }
};