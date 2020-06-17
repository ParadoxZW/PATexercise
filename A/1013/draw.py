from graphviz import Graph

nodes = set()
edges = []

with open('./g.txt', 'r') as f:
    for line in f.readlines():
        i, j = tuple(line.strip().split(' '))
        nodes.add(i)
        nodes.add(j)
        edges.append((i, j))
# 实例化一个Digraph对象(有向图)，name:生成的图片的图片名，format:生成的图片格式
dot = Graph(name="G", comment="the test", format="png")
for i in nodes:
    dot.node(name=i, label=i, color='gray')

for i, j in edges:
    dot.edge(i, j, color='red')

# 生成图片节点，name：这个节点对象的名称，label:节点名,color：画节点的线的颜色

# 在节点之间画线，label：线上显示的文本,color:线的颜色
# 一次性画多条线，c到b的线，a到c的线
# dot.edges(['cb', 'ac'])

# 打印生成的源代码
# print(dot.source)

# 画图，filename:图片的名称，若无filename，则使用Digraph对象的name，默认会有gv后缀
# directory:图片保存的路径，默认是在当前路径下保存
# dot.view(filename="mypicture", directory="D:\MyTest")

# 跟view一样的用法(render跟view选择一个即可)，一般用render生成图片，不使用view=True,view=True用在调试的时候
dot.render(directory="./", view=False)
