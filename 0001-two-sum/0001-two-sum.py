class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_to_index = {}  # Dictionary to store number -> index mapping
        
        for index, number in enumerate(nums):
            complement = target - number  # The number needed to reach the target
            if complement in num_to_index:
                return [num_to_index[complement], index]  # Found the pair
            num_to_index[number] = index  # Store current number with its index
        
        return []  # Should never be reached as per the problem statement