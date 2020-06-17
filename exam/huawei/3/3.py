
def calc(ll):
    nel = []
    # print(ll)
    if isinstance(ll[0], int) and isinstance(ll[1], int):
        return ll
    if isinstance(ll[0], int) and isinstance(ll[1], list):
        for i in ll[1]:
            nel.append(ll[0]*10+i)
        return nel
    if isinstance(ll[1], int) and isinstance(ll[0], list):
        for i in ll[0]:
            nel.append(ll[1]+i*10)
        return nel
    for i in ll:
        y = calc(i)
        nel.append(y)
    # print(nel)
    nnl = set(nel[0])
    for i in nel[1:]:
        yy = set(i)
        nnl = nnl.union(yy)
    return list(nnl)


s = '[0, 1]2' #input()
s = "["+s.replace('[', ',[')[1:].replace(']','],') + ']'
# print(s)
ll = eval(s)
print(calc(ll))
# print(ll)
# print(list(set([1, 1])))


