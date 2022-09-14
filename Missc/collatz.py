def steps(n):
    s = 0
    while n > 1:
        if n % 2 == 0:
            n = n / 2
        else:
            n = 3 * n + 1
        s += 1
    return s
    pass

def main():
    seq = [25, 99, 199, 299, 399, 499, 599, 699, 799, 899, 999]
    for i in  seq:
        print(i, steps(i))
    pass


if __name__ == "__main__":
    main()