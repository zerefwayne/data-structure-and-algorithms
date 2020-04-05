```py
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:

        n = len(nums)
        z = n
        
        for i in range(n-1, -1, -1):
            
            if nums[i] != 0:
                continue
                
            j = i
            
            while j < z-1:
                nums[j] = nums[j+1]
                j += 1
                
            z -= 1
            nums[z] = 0
```