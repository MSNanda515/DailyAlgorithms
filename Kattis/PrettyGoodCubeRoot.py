import sys
import decimal

def sol():
    decimal.getcontext().prec = 505
    while True:
        try:
            line = sys.stdin.readline()
            if not line:
                break
            num = decimal.Decimal(line)
            cr = round(num ** (decimal.Decimal(1) / decimal.Decimal(3)))
            print(cr)
        except:
            break
    pass


if __name__ == "__main__":
    sol()