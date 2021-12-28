def palindrome(seq):
    # Prepare a dict with the freq of occ of each char
    chars = {}
    for c in seq:
        if c in chars:
            chars[c] += 1
        else:
            chars[c] = 1
    odd_freq = 0
    even_chars = []
    odd_chars = []
    for c in chars:
        if chars[c] % 2 != 0:
            odd_freq += 1
            if (odd_freq > 1):
                print("NO SOLUTION")
                return
            odd_chars.append(c)
        else:
            even_chars.append(c)
    tot_len = len(seq)
    pal_seq = [''] * tot_len
    i = 0
    for c in even_chars:
        for j in range(int(chars[c]/2)):
            pal_seq[i] = pal_seq[tot_len - i - 1] = c
            i += 1
    for c in odd_chars:
        for j in range(chars[c]):
            pal_seq[i] = c
            i += 1
    print(''.join(pal_seq))
    pass

palindrome(input())
