import networkx as nx
import sys
import random
import os

# Generate
nvertex = random.randint(1000, 2000)
G = nx.erdos_renyi_graph(nvertex, 0.5, seed=123, directed=False)
for (u, v, w) in G.edges(data=True):
    w['weight'] = random.randint(1, 1000)

# Print
file_path = 'Single-Source-Shortest-Path/inputdj.txt'
sys.stdout = open(file_path, "w")

print(nx.number_of_nodes(G), end=" ")
print(nx.number_of_edges(G))
for line in nx.generate_edgelist(G, data=["weight"]):
    print(line)

# Test With Code
os.system("cd '/home/arean/Pictures/Prim-Kruskal-Graph-Implementation/Single-Source-Shortest-Path/' && g++ dijkastra.cpp -o dijkastra && '/home/arean/Pictures/Prim-Kruskal-Graph-Implementation/Single-Source-Shortest-Path/'dijkastra")