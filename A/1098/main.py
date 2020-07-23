n = int(input())
oa = list(map(int, input().split(' ')))
sa = list(map(int, input().split(' ')))

def print_line(a):
    s = ' '.join(map(str, a))
    print(s)

def insert_sort(oa, sa):
    print("Insertion Sort")
    # isa = sorted(oa)
    for i in range(n):
        if oa[i] == sa[i] and sa[i - 1] > sa[i] : ###
            if oa[i:] == sa[i:]: ###
            # print(i)
                break
    for j in range(i)[::-1]:
        if sa[j] > sa[j + 1]:
            sa[j], sa[j + 1] = sa[j + 1], sa[j]
        else:
            break
    print_line(sa)


def lchild(x):
    return (x + 1 ) * 2 - 1

def rchild(x):
    return (x + 1) * 2

def topdown_adjust(sa, low, high):
    i = low   
    j = lchild(low)
    while j < high:
        if j + 1 < high and sa[j+1] >sa[j]:
            j += 1
        if sa[j] > sa[i]:
            sa[j], sa[i] = sa[i], sa[j]
            i = j;
            j = lchild(i)
        else:
            break
#     rch = rchild(low)
#     if lch >= high:
#         return
#     if rch >= high:
#         if sa[lch] > sa[low]:
#             sa[lch], sa[low] = sa[low], sa[lch]
#         return
#     if sa[lch] > sa[low] and sa[lch] > sa[rch]:
#         sa[lch], sa[low] = sa[low], sa[lch]
#         topdown_adjust(sa, lch, high)
#     elif sa[rch] > sa[low] and sa[rch] > sa[lch]:
#         sa[rch], sa[low] = sa[low], sa[rch]
#         topdown_adjust(sa, rch, high)

def heap_sort(oa, sa):
    print("Heap Sort")
    x = sa[0]
    for i in range(n)[::-1]:
        if x > sa[i]:
            sa[0], sa[i] = sa[i], sa[0]
            break
    topdown_adjust(sa, 0, i)
    print_line(sa)


if sa[0] > sa[1]:
    heap_sort(oa, sa)
elif sa[0] < sa[1]:
    insert_sort(oa, sa)
else:
    if sa[0] > sa[2]:
        heap_sort(oa, sa)
    elif sa[0] < sa[2]:
        insert_sort(oa, sa) 
    else:
        if sa[0] > sa[3]:
            heap_sort(oa, sa)
        elif sa[0] < sa[3]:
            insert_sort(oa, sa) 