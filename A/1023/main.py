s = input()
digit = int(s)
ddigit = digit * 2

chars = list(_ for _ in s)
chars = sorted(chars)
# print(chars)
dchars = list(_ for _ in str(ddigit))
dchars = sorted(dchars)

if chars == dchars:
    print('Yes')
else:
    print('No')
print(ddigit)
