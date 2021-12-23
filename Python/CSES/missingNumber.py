def find_missing_no():
    numbers = set()
    n = int(input())
    inNo = list(map(int, input().split()))
    numbers.update(inNo)
    for i in range(1, n+1):
        if i not in numbers:
            print(i)
    pass


if __name__ == "__main__":
    find_missing_no()