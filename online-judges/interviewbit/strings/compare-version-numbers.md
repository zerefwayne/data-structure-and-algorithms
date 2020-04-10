```py
def sortStrings(a, b):
    a_nums = a.split('.')
    b_nums = b.split('.')
    
    for i in range(min(len(a_nums), len(b_nums))):
        if a_nums[i] != b_nums[i]:
            if int(a_nums[i]) < int(b_nums[i]):
                return -1
            elif int(a_nums[i]) > int(b_nums[i]):
                return 1

    if len(a_nums) < len(b_nums):
        
        for i in range(len(a_nums), len(b_nums)):
            if int(b_nums[i]) != 0:
                return -1

    elif len(a_nums) > len(b_nums):
        
        for i in range(len(b_nums), len(a_nums)):
            if int(a_nums[i]) != 0:
                return 1
    
    return 0

    
class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
	def compareVersion(self, A, B):
	  
	    return sortStrings(A, B)
```

## Approach 2

```py
class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
	def compareVersion(self, A, B):
	  
	    a=list(map(int,A.split('.')))
        x=len(a)
        b=list(map(int,B.split('.')))
        y=len(b)
        
        while(x>y):
            b.append(0)
            y+=1
        while(y>x):
            a.append(0)
            x+=1
        if a>b:
            return 1
        if a<b:
            return -1
        return 0
```