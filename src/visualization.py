import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

with open("network.txt", "r") as file:
    for line in file:
        u, v, w = line.strip().split()
        G.add_edge(u, v, weight=int(w))

pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=3000, font_size=12)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
plt.title("Friend Network Visualization")
plt.show()
