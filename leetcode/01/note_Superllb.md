#描述
##解题思路
###一般来说，使用unordered_map，并将数组元素及元素对应的索引分别作为key，value，可以有效减小运行时间，但是存在两个疑问。
* 初始unordered_map为空，一边查询一边将不符合要求的数组元素和索引插入unordered_map中，因此，a=nums[i]时，b只能在num[0]~nums[i-1]中查找，这也导致
程序在第一次循环(i=1)时，永远不会输出结果，例如：

  ```
  input: nums=[1,3,5,7],target=4
  ```
* 假如数组中，存在相同的元素，怎么办？

#代码
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map<int, int> unmap;
    	vector<int> result;
    	for (int i = 0; i < nums.size(); ++i) {
    		int x = target - nums[i];
    		auto search = unmap.find(x);
    		if (search != unmap.end()) {
    			result.push_back(search->second);
          result.push_back(i);
    			return result;
    		}
    		unmap.insert({nums[i],i});
    	}
    	return result;
    }
};
```
