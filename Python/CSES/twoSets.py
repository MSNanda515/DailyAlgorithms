def print_list(li):
    print(len(li))
    print(' '.join(li))


def two_sets(n):
    sum_half = int(n*(n+1)/4)
    if 2 * sum_half != n*(n+1)/2:
        print("NO")
        return
    nos = list()
    list1 = []
    sum_list1 = 0
    list2 = []
    for i in range(1, n+1):
        nos.append(i)
    while sum_list1 != sum_half:
        temp_no = nos.pop()
        if temp_no > sum_half - sum_list1:
            list2.append(str(temp_no))
        else:
            list1.append(str(temp_no))
            sum_list1 = sum_list1 + temp_no
    for i in nos:
        list2.append(str(i))
    print("YES")
    print_list(list1)
    print_list(list2)


if __name__ == "__main__":
    n = int(input())
    two_sets(n)