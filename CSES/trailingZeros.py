buffer = {1: 0}


def find5(no):
    no5 = 0
    if no % 5 == 0:
        no_prev = no / 5
        if no_prev in buffer:
            no5 = 1 + buffer[no_prev]
        else:
            no5 = 1
        buffer[no] = no5
    return no5


def trailing_zeros(n):
    # Count the number of trailing zeros
    no5 = 0
    i = 5
    last_5 = 1
    while i <= n:
        no5 = no5 + int(n / i)
        i = i * 5
    print(no5)


if __name__ == "__main__":
    n = int(input())
    trailing_zeros(n)