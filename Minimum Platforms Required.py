def findPlatform(arr, dep):
    arr.sort()
    dep.sort()

    i = j = 0
    platforms = result = 0

    while i < len(arr) and j < len(dep):
        if arr[i] <= dep[j]:
            platforms += 1
            i += 1
        else:
            platforms -= 1
            j += 1
        result = max(result, platforms)

    return result
