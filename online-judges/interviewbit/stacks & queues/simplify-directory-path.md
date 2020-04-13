```py
class Solution:
    # @param A : string
    # @return a strings
    def simplifyPath(self, A):
        path = A.split('/')[1:-1]
        stack = []
        for direc in path:
            if direc == "." or direc == "":
                continue
            elif direc == "..":
                if len(stack) > 0 :
                    stack.pop()
            else:
                stack.append(direc)
                
        res = ""
        
        if len(stack) == 0:
            res = "/"
            return res
        
        while len(stack) > 0:
            res = "/" + stack.pop() + res
            
        return res
```