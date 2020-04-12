```py
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res = set()
        
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                if words[j].find(words[i]) != -1:
                    res.add(words[i])
                elif words[i].find(words[j]) != -1:
                    res.add(words[j])
                    
        return list(res)
```