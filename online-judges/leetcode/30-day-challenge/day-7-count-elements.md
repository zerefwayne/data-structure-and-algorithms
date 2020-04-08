```py
class Solution:
    def countElements(self, arr: List[int]) -> int:
        umap = defaultdict(int)
        count = 0
        for num in arr:
            umap[num] += 1
        for k, v in umap.items():
            if k+1 in umap:
                count += v
        return count        
```