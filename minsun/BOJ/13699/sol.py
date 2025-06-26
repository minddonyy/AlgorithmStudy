n = int(input())

dp = [0] * (n + 1)
dp[0] = 1

for i in range(1, n + 1):
    total = 0
    for j in range(i):
        total += dp[j] * dp[i - 1 - j]
    dp[i] = total

print(dp[n])