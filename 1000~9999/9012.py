t = int(input())
for case in range(t):
    cnt = 0
    value = input()
    for i in value:
        if i == '(':
            cnt += 1
        else:
            cnt -= 1
        if cnt < 0:
            break
    if cnt == 0:
        print("YES")
    else:
        print("NO")
