
import math


def findFacts(num):
    i = 1
    fact = []
    numSqrt = math.sqrt(num)
    while i <= numSqrt:
        if (num % i == 0):
            fact.append(i)
            if (num / i != i):
                fact.append(num / i)
        i += 1
    return fact


def isPalind(num):
    s = str(num)
    for i in range(0, len(s) // 2):
        if s[i] != s[len(s) - i - 1]:
            return False
    return True

def sol(num):
    facts = findFacts(num)
    palFacts = 0
    for n in facts:
        if isPalind(int(n)):
            palFacts += 1
    return palFacts


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        num = int(input())
        ans = sol(num)
        print("Case #%d: %d" % (i+1, ans))
    pass