from collections import Counter

def sherlockAndAnagrams(s):
    count = Counter()

    for i in range(len(s)):
        for j in range(i, len(s)):
            substring = ''.join(sorted(s[i:j+1]))
            count[substring] += 1

    result = 0
    for val in count.values():
        result += (val * (val - 1)) // 2

    return result
