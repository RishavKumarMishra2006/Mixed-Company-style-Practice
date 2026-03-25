from collections import Counter

def topKFrequent(nums, k):
    freq = Counter(nums)
    return [x for x, _ in freq.most_common(k)]
