import re

# rx = re.compile(r"\d+")
# a = rx.search("wsaf2ffxc2sad")
# print(a)
# print(a.group())

# a = rx.findall("wsaf2ffxc2sad")
# print(a)

# a = rx.finditer("wsaf212ffxc23sad")
# print(type(a))
# for i in a:
#     print(i)
#     print(i.end())
#     print(i.group())

# rx = re.compile(r"\d+(.)(.)")
# a = rx.finditer("wsaf212ffxc23sad")
# for i in a:
#     print(i)
#     # print(i.end())
#     print(i.group(2))
#     print(i.group(0))

rx = re.compile(r'<(.*?)>')
a = rx.sub(r'[\1]', "x<a1>=y<b1>c")
print(a)

rx = re.compile(r'<(.*?)>(?==)')
a = rx.sub(r'[\1]', "x<a1>=y<b1>c")
print(a)

rx = re.compile(r'(?<=y)<(.*?)>')
a = rx.sub(r'[\1]', "x<a1>=y<b1>c")
print(a)
