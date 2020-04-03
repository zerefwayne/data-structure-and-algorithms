## Approach 1

```py
class Node:
    def __init__(review):
        self.review = review
        self.rank = 0
        self.index = 0

    def calculate_rank(self, good_words):
        review_words = self.review.split('_')
        for word in review_words:
            if word in good_words:
                self.rank += 1

    def __lt__(self, other):

        if self.rank != other.rank:
            return self.rank > other.rank
        else:
            return self.index < other.index


class Solution:
    # @param A : string
    # @param B : list of strings
    # @return a list of integers
    def solve(self, A, B):

        reviews = []

        good_words = set(A.split('_'))

        for review in B:
            newNode = Node(review)
            newNode.calculate_rank()
            reviews.append(newNode)

        sort(reviews)

        res = []

        for review in reviews:
            res.append(review.index)

        return res
```