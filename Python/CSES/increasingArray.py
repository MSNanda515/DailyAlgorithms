def increasing_array():
    n = int(input())
    arr = list(map(int, input().split()))
    move = 0
    if len(arr) == 0:
        print(0)
        return
    curr_max = arr[0]
    for no in arr:
        if no < curr_max:
             move = move + (curr_max - no)
        else:
            curr_max = no
    print(move)

increasing_array()
