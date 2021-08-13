n, m = map(int, input().split())

dp = [[0 for col in range(101)] for row in range(101)]

for i in range(1, 101):
    for j in range(0, i+1):
        if (j == 0) or (i == j):
            dp[i][j] = 1
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

print(dp[n][m])