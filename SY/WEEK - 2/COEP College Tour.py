"""
CONTRIBUTED BY - 
CSI COEP Tech Core Team
"""
T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    v = list(map(int, input().split()))
    ans = 2e9; 
    xx = 2
    for pp in range(2):
        lpoz = -1
        sw = 0
        prev = v[0]
        dir = True
        if prev == -1:
            prev = 1
        else:
            lpoz = 0
        for i in range(1, n):
            if v[i] != -1:
                j = lpoz
                if j != -1:
                    if (i - j) % 2 != abs(v[i] - v[j]) % 2 or abs(v[i] - v[j]) > abs(i - j):
                        ans = -1
                lpoz = i
            if dir and prev == m:
                sw += 1
                dir = 1 - dir
            elif not dir and prev == 1:
                sw += 1
                dir = 1 - dir
            if dir:
                prev = prev + 1
            else:
                prev = prev - 1
            if v[i] != -1 and not ((dir and prev <= v[i]) or (not dir and prev >= v[i])):
                sw += 1
                dir = 1 - dir
            if v[i] != -1:
                prev = v[i]
        if ans > sw:
            ans = sw
        for i in range(n):
            if 1 <= v[i] and v[i] <= m:
                v[i] = m + 1 - v[i] 
    print(ans)