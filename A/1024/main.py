s = input()
n, k = map(int, s.split(' '))

i = 0
for i in range(k):
    n_inv = int(str(n)[::-1])
    if n_inv == n:
        i -= 1
        break
    else:
        n += n_inv
print(n)
n_inv = int(str(n)[::-1])
if n_inv != n:
    print(k)
else:
    i += 1
    print(i)