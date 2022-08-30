### Title:
### Prim’s and Kruskal’s Algorithm for Minimum Spanning Tree Analysis 
### Abstract:
Prim’s Algorithm and Kruskal’s Algorithm are two of the most common minimum spanning tree finder algorithms used in computer science. Both of these algorithms are tested on different implementations and different datasets to determine their effectiveness. Extensive research has been conducted to determine which of the two algorithms is best for a given problem. This has led to the development of other algorithms that are better suited for a specific type of data or a specific type of problem.
### Introduction:
The prim’s algorithm starts by choosing the root vertex and then moves through nearby vertex pairs. By starting with the shortest weighted edge, Krushal's approach, on the other hand, assists in creating the minimal spanning tree. 
Popularly known as a greedy method, Prim's approach aids in locating the lowest spanning tree for a weighted undirected graph. This means that the total weight of all the edges in the tree should be as low as possible because this method likes to explore the subgroup of edges that may create a tree.
In the field of computer science, the shortest spanning tree of a connected graph and the spanning forest of an undirected edge-weighted graph are both found using Kruskal's Algorithm. Essentially, it takes a graph as input and finds the subgroup of its edges.
### Methodology (Materials and
Methods)
Prim’s Algorithm implemented in four different ways, using
STL Priority Queue (C++ Standard Template Library)
Binary heap (Self Implemented)
Linked List (Self Implemented)
Array (Self Implemented)
Kruskal’s Algorithm implemented using twelve different ways, using
DSU (Disjoint Set Union) with Path Compression, Union by Rank, and STL
DSU (Disjoint Set Union) with Path Compression and STL
DSU (Disjoint Set Union) with Union by Rank and STL
DSU (Disjoint Set Union) and STL
DSU (Disjoint Set Union) with Path Compression, Union by Rank, and LinkedList
DSU (Disjoint Set Union) with Path Compression and LinkedList
DSU (Disjoint Set Union) with Union by Rank and LinkedList
DSU (Disjoint Set Union) and LinkedList
DSU (Disjoint Set Union) with Path Compression, Union by Rank, and Array
DSU (Disjoint Set Union) with Path Compression and Array
DSU (Disjoint Set Union) with Union by Rank and Array
DSU (Disjoint Set Union) and Array

Graph Generated using Networkx Python Library and Algorithms solely coded on C++. To Plot Result We Used 

### Results:
Prim Algorithm tested over 12 random graph(Time Stamp in Micro Second) and Kruskal’s Algorithm Implemented Using 12 Ways and Tested in 20 Random Graphs.<br>
[Prims Algorithm Result](https://docs.google.com/spreadsheets/d/1o7hJKIJXeZbm71hMhuzeFDwiU1wGHqNCqMy10bQznJA/) <br>
[Kruskal's Algorithm Result](https://docs.google.com/spreadsheets/d/e/2PACX-1vSBgGnrMR5f25MgNgBwxoUJcxA06cJ0cFOT9y0B8amgfgYKW8MNnKi5z6cOrcgmKfIhqCjTamydPXh7/pubchart?oid=33088508&format=interactive) <br>
[Full Result Data Sheet](https://docs.google.com/spreadsheets/d/1o7hJKIJXeZbm71hMhuzeFDwiU1wGHqNCqMy10bQznJA/)
### Discussion:
Kruskal time complexity worst case is O(E log E),this because we need to sort the edges. Prim time complexity worst case is O(E log V) with priority queue or even better, O(E+V log V) with Heap. We should use Kruskal when the graph is sparse, i.e.small number of edges,like E=O(V),when the edges are already sorted or if we can sort them in linear time. We should use Prim when the graph is dense, i.e number of edges is high , like E=O(V²).
Analzying the runtime of both the algorithm, we can notice heap implementations are way more faster than LinkedList implementation, array implementation is the slowest. We can also notice that, Standard Template Library implementation is not always best in term of time complexity.
