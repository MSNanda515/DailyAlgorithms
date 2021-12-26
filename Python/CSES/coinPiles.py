

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        [a, b] = list(map(int, input().split()))
        if a < b:
            [a, b] = [b, a]
        # a is greater or equal
        n = a - b
        if a == 2 * b:
            print("YES")
        elif n > b:
            print("NO")
        elif (b - n) % 3 == 0:
            print("YES")
        else:
            print("NO")