#描述
##解题思路
###为了保证第一次查找有效，采用先插再查。之前提到数组里可能会有重复元素，bajdcc提示使用multimap，运行结果显示，两者结果相同。只要这个重复元素符合条件，返回的始终是第一次出现时对应的索引。
###此外，例如```nums=[1,3,5,7,9],target=14```，如果不加判断，返回结果就会是```[3,3]```,而不是```[3,4]```。如果采用先查再插，这种情形不用考虑。
#代码
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map<int, int> unmap;
    	vector<int> result;
    	for (int i = 0; i < nums.size(); ++i) {
    		//int x = target - nums[i];
        unmap.insert({nums[i],i});
    		auto search = unmap.find(target - nums[i]);
		    if (search != unmap.end()) {
		        if (i != search->second){
		          result.push_back(i);
    			    result.push_back(search->second);
    			    return result;
		        }
		    }
		    //unmap.insert({nums[i],i});
    	}
    	return result;
    }
};
```
