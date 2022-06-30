class sol:
    def solve(self, l, r):
        req = min(l, r)
        return req*(req + 1) / 2
        pass
    def main(self):
        tot = int(input())
        for t in range(tot):
            [l, r] = map(int, input().split())
            ans = self.solve(l, r)
            print("Case #%d: %d" %(t+1, ans))

if __name__ == "__main__":
    sol().main()