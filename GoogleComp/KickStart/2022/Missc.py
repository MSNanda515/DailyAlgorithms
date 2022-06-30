class sol:
    def solve(self, n, m, candies):
        totCand = sum(candies)
        return totCand % m
    def main(self):
        tot = int(input())
        for t in range(tot):
            [n, m] = map(int, input().split())
            candies = map(int, input().split())
            ans = self.solve(n, m, candies)
            print("Case #%d: %d" %(t+1, ans))

if __name__ == "__main__":
    sol().main()