from subprocess import Popen, PIPE, STDOUT
import random, os, sys
import time

def randgen():
    maxn = 20
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
    t1 = time.time()
    out1 = p1.communicate(input=data.encode())[0]
    t1 = (time.time() - t1)
    out1 = out1.decode()
    p2 = Popen(exe2, stdout=PIPE, stdin=PIPE, stderr=STDOUT)
    t2 = time.time()
    out2 = p2.communicate(input=data.encode())[0]
    t2 = (time.time() - t2)
    out2 = out2.decode()
    if out1 == out2:
        # print("||")
        return 1, t2/t1
    else:
        # print("--")
        # err.append(data)
        with open('./log.txt', 'a') as f:
            f.write(data)
        return 0, t2/t1

E1 = './2.exe'
E2 = './4.exe'
cnt = 0
N = 500
log_file = "./log.txt"
if os.path.isfile(log_file):
    os.remove(log_file)
os.mknod(log_file) 
# err = []
# print(randgen())
# print(randgen())
# print(randgen())
max_rt = 0
sum_rt = 0
for i in range(N):
    data = randgen()
    n = int(data.split('\n')[0].split(' ')[0])
    r, rt = comp(data, E1, E2)
    sum_rt += rt
    max_rt = max(max_rt, rt)
    cnt += r
    if rt > 1.8:
        with open('./log.txt', 'a') as f:
            f.write(data)
    print(i, r, rt, n)

print(N - cnt, cnt / N)
print(max_rt, sum_rt / N)
