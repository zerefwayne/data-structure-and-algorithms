```py
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        S_new = []
        for c in S:
            if c == '#':
                if len(S_new) > 0:
                    S_new.pop()
            else:
                S_new.append(c)
        T_new = []
        for t in T:
            if t == '#':
                if len(T_new) > 0:
                    T_new.pop()
            else:
                T_new.append(t)
        return ''.join(S_new) == ''.join(T_new)
```