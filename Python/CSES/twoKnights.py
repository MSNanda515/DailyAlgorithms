def find_comb(n):
    comb = (n*n * (n*n - 1) / 2) - (n-2)*(n-1)*4
    return comb


def two_knights(n):
    for i in range(1,n+1):
        print(int(find_comb(i)))


if __name__ == "__main__":
    n = int(input())
    two_knights(n)