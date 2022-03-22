def beautiful_perm():
    n = int(input())
    if n == 1:
        print(1)
        return
    if n < 4:
        print("NO SOLUTION")
        return
    i = 2
    while i <= n:
        print(i, end=' ')
        i = i + 2
    i = 1
    while i <= n:
        print(i, end=' ')
        i = i + 2


beautiful_perm()
