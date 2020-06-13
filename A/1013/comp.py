from subprocess import Popen, PIPE, STDOUT
import random


def randgen():
    maxn = 10
    N = random.randint(2, maxn)
    M = random.randint(1, N * (N - 1) // 2)
    s = f"{N} {M} {N}\n"
    pairs = []
    # print(s)
    for _ in range(M):
        a = random.randint(1, N)
        b = random.randint(1, N)
        while a == b or (a, b) in pairs or (b, a) in pairs:
            a = random.randint(1, N)
            b = random.randint(1, N)
        pairs.append((a, b))
        s += f"{a} {b}\n"
    s += ' '.join(map(str, range(1, N+1))) + '\n'
    return s


def comp(data, exe1, exe2):
    p1 = Popen(exe1, stdout=PIPE, stdin=PIPE, stderr=STDOUT)
    out1 = p1.communicate(input=data.encode())[0]
    out1 = out1.decode()
    p2 = Popen(exe2, stdout=PIPE, stdin=PIPE, stderr=STDOUT)
    out2 = p2.communicate(input=data.encode())[0]
    out2 = out2.decode()
    if out1 == out2:
        # print("||")
        return 1
    else:
        # print("--")
        # err.append(data)
        with open('./log.txt', 'a') as f:
            f.write(data)
        return 0

E1 = './1.exe'
E2 = './2.exe'
cnt = 0
N = 200
# err = []
# print(randgen())
# print(randgen())
# print(randgen())
for i in range(N):
    data = randgen()
    r = comp(data, E1, E2)
    cnt += r
    print(i, r)

print(N - cnt, cnt / N)
