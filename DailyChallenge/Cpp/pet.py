maxPos = -1
maxScore = 0
sumTerms = 0
for i in range(1,6):
    sumTerms = 0
    score = list(map(int, input().split()))
    for j in score:
        sumTerms += j
    if sumTerms > maxScore:
        maxPos = i
        maxScore = sumTerms
print("%d %d" %(maxPos, maxScore))