```py
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        indices = {}
        for string in strs:
            temp = ''.join(sorted(string))
            if temp in indices:
                res[indices[temp]].append(string)
            else:
                indices[temp] = len(indices)
                res.append([string])
        return res
```