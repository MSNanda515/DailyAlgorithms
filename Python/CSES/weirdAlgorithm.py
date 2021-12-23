def weird_algoritm(n):
    print(n, end=" ")
    while n != 1:
        if n % 2 == 0:
            # n is even
            n = n / 2
            print(int(n), end=" ")
        else:
            n = 3 * n + 1
            print(int(n), end=" ")
    pass

if __name__ == "__main__":
    n = int(input())
    weird_algoritm(n)



