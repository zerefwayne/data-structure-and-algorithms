```py
import heapq

class MinStack:

    def __init__(self):
        
        self.stack = []
        self.min_stack = []
        self.size = 0
        

    def push(self, x: int) -> None:
        
        self.stack.append(x)
        heapq.heappush(self.min_stack, x)
        self.size += 1
        

    def pop(self) -> None:
        
        if self.size > 0:
            
            top = self.top()
            
            self.min_stack.remove(top)
            self.stack.pop()
            heapq.heapify(self.min_stack)
            
            self.size -= 1
        

    def top(self) -> int:
        
        if self.size > 0:
            return self.stack[self.size-1]
        else:
            return -1
        

    def getMin(self) -> int:
        
        min_el = heapq.heappop(self.min_stack)
        heapq.heappush(self.min_stack, min_el)
        return min_el
```