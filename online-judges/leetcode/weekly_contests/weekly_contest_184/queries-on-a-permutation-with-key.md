```py
class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        
        res = []
        
        P = [i+1 for i in range(m)]
        
        for query in queries:
            idx = P.index(query)
            res.append(idx)
            del P[idx]
            P.insert(0, query)
            
        return res
```