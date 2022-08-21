import networkx as nx
import sys
import random
import os

#Generate
nvertex = random.randint(100,500)
G = nx.erdos_renyi_graph(nvertex, 0.5, seed=123, directed=False)
for (u,v,w) in G.edges(data=True):
    w['weight'] = random.randint(0,10000)

# Print
file_path = 'inp.txt'
sys.stdout = open(file_path, "w")

print(nx.number_of_nodes(G), end=" ")
print(nx.number_of_edges(G))
for line in nx.generate_edgelist(G, data=["weight"]):
    print(line)

#Test With Code
str = 'Kruskal_MST'
str2= 'Prim_MST'
os.system(f"cd '../Experiment_with_Prim_Kruskal/' && g++ {str}.cpp -o {str} && '../Experiment_with_Prim_Kruskal/'{str}")
os.system(f"cd '../Experiment_with_Prim_Kruskal/' && g++ {str2}.cpp -o {str2} && '../Experiment_with_Prim_Kruskal/'{str2}")




