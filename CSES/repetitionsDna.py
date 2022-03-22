def find_max_repetitions():
    str_in = input()
    if len(str_in) == 0:
        print(0)
    else:
        last_char = str_in[0]
        max_len = 1
        len_temp = 1
        for i in range(1, len(str_in)):
            if str_in[i] == last_char:
                len_temp = len_temp + 1
            else:
                if len_temp > max_len:
                    max_len = len_temp
                len_temp = 1
                last_char = str_in[i]
        if len_temp > max_len:
            max_len = len_temp
        print(max_len)
    pass


if __name__ == "__main__":
    find_max_repetitions()