def solve(n, k, arr):
    moves = 0
    for i in range(k, n):
        if arr[i] <= k:
            moves += 1
    return moves

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        [n, k] = list(map(int, input().split()))
        arr = list(map(int, input().split()))
        print(solve(n, k, arr))