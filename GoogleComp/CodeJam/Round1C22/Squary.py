
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

def findDiffSquares(num):
    sumList = sum(num)
    sumSquare = sum(map(lambda i : i * i, num))
    return (sumList * sumList) - sumSquare

def sol(n, k, num):
    sumList = sum(num)
    diffSq = findDiffSquares(num)
    print("sumList %d, diff %d" % (sumList, diffSq))
    if sumList == 0 and diffSq != 0:
        return "IMPOSSIBLE"
    if diffSq == 0:
        return "0"
    if (diffSq % 2) != 0 or (diffSq % sumList) != 0:
        return "IMPOSSIBLE"
    reqNo = -1 * diffSq / 2 / sumList
    if abs(reqNo) <= 1e18:
        return str(reqNo)
    if reqNo / 1e18 > k:
        return "IMPOSSIBLE" 
    reqList = []
    tempNo = reqNo 
    while tempNo > 0:
        reqList.append(min(1e18, tempNo))
        tempNo -= 1e18
    return " ".join(reqList)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n, k = map(int, input().split())
        num = list(map(int, input().split()))
        ans = sol(n, k, num)
        print("Case #%d: %s" % (i+1, ans))
    pass