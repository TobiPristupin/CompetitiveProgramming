def longest_increasing_subsequence(arr):
    dp = [1] * len(arr)

    for i in range(1, len(arr)):
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[j] + 1, dp[i])

    return max(dp)

s = input()
print(26 - longest_increasing_subsequence(s))
