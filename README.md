# Design-and-Analysis-of-Algorithm
![large](https://user-images.githubusercontent.com/70502574/201451733-f35d96cf-2c54-4338-a3c3-a6679ea355eb.png)


## Data Type :
A data type is something that defines a domain of allowed values and the operations that can be performed on those values.
<br>
For example in C language, the int data type can take values in range and operations that can be performed are addition, subtraction, multiplication, division and all those stuff which can be done with numbers in mathematics.
<br>
Similarly, there are many other data types like float, double, String, char, boolean, etc.
<br>
These data types are built-in data types also known as primitive data types and the values and operations for them are pre-defined in the programming language.
<br>
If an application needs to use a data type other than the primitive data types of language, then it is the programmer’s responsibility to specify the values and operations for that data type and implement it. For example, there is no built-in type dates in c, and if we need to process dates, we have to define and implement a data type for a date.
<br>
## Abstract Data Types (ADT) :
An abstract data type is a mathematical model or concept that defines a data type logically. It specifies a set of data and collection of operations that can be performed on that data.
<br>
The definition of ADT only mentions what operations are to be performed but not how these operations will be implemented. It does not specify how data will be organized in memory and what algorithms will be used for implementing the operations.
<br>
These process of hiding details is also known as Abstraction.
<br>
For example, consider Stack ADT<br>
Stack: A stack contains elements of the same type arranged in sequential order and following operations can be performed on the stack.
<br>
Stack data structure<br>
1. Initialize() : Initialize the stack to be empty.<br>
2. Push(): Insert an element at one end of the stack called top.<br>
3. Pop(): Remove and return the element at the top of the stack, if it is not empty.<br>
4. Peek(): Return the element at the top of the stack without removing it, if the stack is not empty.<br>
5. Size(): Return the number of elements in the stack (i.e size of the stack).<br>
6. isEmpty(): Return true if the stack is empty, otherwise return false.<br>
7. isFull(): Return true if no more elements can be pushed or added, otherwise return false.<br>
## Data Structures :
Now, here comes the Data Structures. So what really it is?
<br>
Data Structure is a programming construct used to implement an ADT.
<br>
It is the physical implementation of ADT. All operations specified in ADT are implemented through functions in the physical implementation. A data structure that is implementing an ADT consists of a collection of variables for storing the data specified in the ADT and the algorithms for implementing the operations specified in ADT.
<br>
ADT is the logical view of data and the operations to manipulate the data while Data Structure is the actual representation of data and the algorithms to manipulate the data.
<br>
## What are the Advantages of Data Structures?
1. Efficiency: Proper choice of data structures make programs efficient in terms of time and space. For Example, suppose we have some data and we need to organize it properly and perform the search operation. If we organize our data in an array, then we will have to search sequentially element by element. If the item to be searched is present at last then we will have to visit all the elements before reaching that element. So the use of array is not very efficient here. There is a better data structure which makes the search process efficient like an ordered array, Binary Search Tree or Hash Table. Different data Structure gives different efficiency.<br>
2. Reusability: Data Structures are reusable, i.e, once we have implemented a particular data structure we can use it in any other place or requirement. Implementation of data structure can be compiled into libraries which can be used by different clients.<br>
3. Abstraction: Data Structure provides the level of abstraction and hides the detail of how things are working behind the screen. For example, In Stack push() insert the element at top and pop() removes an element from the top. How this insertion and removing is working is hidden from the user.
Now, in the next section, we will cover the types of data structure, it’s importance and some brief overview of different data structures.<br>
## Algorithm
Derived from the name of the mathematician Muhammed ibn-Musa Al-Khowarizmi, an algorithm is a solution to a problem that meets the following criteria.<br>
1. A list of instructions, procedures, or formula that solves a problem.<br>
2. Can be proven.<br>
3. Something that always finishes and works.<br>
## How algorithms are used
Today, algorithms are used billions of times every day for a variety of tasks. Below are a few of the different ways algorithms are used.<br>
1. There are many sort algorithms that sort data.<br>
2. Algorithms help control traffic lights.<br>
3. Computers use algorithms to convert data (e.g., converting decimal into binary).<br>
4. Google's search uses the PageRank algorithm to sort searched results.<br>
5. Encryption to encrypt and decrypt information and keep data safe is an algorithm.<br>
6. GPS uses graph search algorithms to find the best route to a destination.<br>
7. Smartphones, Wi-Fi, and wireless communication use algorithms to communicate.<br>
8. E-mail spam detection uses algorithms to filter out bad e-mails.<br>
9. Data compression for getting information faster (e.g., YouTube video) use algorithms.<br>
## When was the first algorithm?
Because a cooking recipe could be considered an algorithm, the first algorithm could go back as far as written language. However, many find Euclid's algorithm for finding the greatest common divisor to be the first algorithm. This algorithm was first described in 300 B.C.<br>
Ada Lovelace is credited as being the first computer programmer and the first person to develop an algorithm for a machine.<br>
## Code Contents of The Repository
.<br>
├── BS0: Binary Search<br>
│   ├── binarysearch.cpp<br>
│   ├── distancevitto.cpp<br>
│   ├── FindFloorOfAElementInSortedArray.cpp<br>
│   ├── inp.txt<br>
│   ├── kk.cpp<br>
│   ├── LeetCode30.cpp<br>
│   ├── MinimumDifferenceElementInASortedArray.cpp<br>
│   ├── n+nod.cpp<br>
│   ├── Notes.txt<br>
│   ├── peakelement.cpp<br>
│   ├── RotationNumberInSortedRotatedArrayAndIndexOfMinimumElement.cpp<br>
│   ├── SearchAnElementInSortedRotatedArray.cpp<br>
│   ├── SearchingInANearlySortedArray.cpp<br>
│   ├── set_stl_usasge.cpp<br>
│   ├── sqrt.cpp<br>
├── DP0 : Recursion & Backtracking<br>
│   ├── brackets.cpp<br>
│   ├── consecutiveone.cpp<br>
│   ├── friendpairing.cpp<br>
│   ├── hamiltonianpath.cpp<br>
│   ├── input.txt<br>
│   ├── nqueenscount.cpp<br>
│   ├── nqueens.cpp<br>
│   ├── output.txt<br>
│   ├── subsetprint.cpp<br>
│   ├── sudokosolver.cpp<br>
│   ├── tiling_problem.cpp<br>
│   └── towerofhanoi.cpp<br>
├── DP1: Dynamic Programming<br>
│   ├── knapsack_bottomup.cpp<br>
│   ├── knapsack_memo.cpp<br>
│   ├── knapsack_rec.cpp<br>
│   ├── knapsack_testcase.py<br>
│   ├── lcs_bottomup.cpp<br>
│   ├── lcs_memo.cpp<br>
│   ├── lcs_rec.cpp<br>
│   ├── lcs_testcase.py<br>
│   ├── lis_bottomup.cpp<br>
│   ├── lis_memo.cpp<br>
│   ├── lis_rec.cpp<br>
│   ├── lis_testcase.py<br>
│   ├── PrintSetBit.cpp<br>
│   ├── rockclimbing.cpp<br>
│   ├── rockclimbing.py<br>
│   ├── rockclimbing_rec.cpp<br>
│   ├── rodcutting_bottomup.cpp<br>
│   ├── rodcutting_memo.cpp<br>
│   ├── rodcutting_rec.cpp<br>
│   ├── rodcutt_testcase.py<br>
│   ├── test_knapsack.py<br>
│   ├── test_lcs.py<br>
│   ├── test_lis.py<br>
│   └── test_rod.py<br>
├── DP2: Matrix Chain Multiplication<br>
│   ├── MCMBottomUp.cpp<br>
│   ├── MCMmemoization.cpp<br>
│   └── MCMRecursion.cpp<br>
├── DS0: Stack Queue LinkedList<br>
│   ├── allfix_final.cpp<br>
│   ├── circularqueue.cpp<br>
│   ├── infixpostfixprefix.cpp<br>
│   ├── infixtoevaluation.cpp<br>
│   ├── LinkedList.cpp<br>
│   ├── ParanthesesRelated-1.cpp<br>
│   ├── ParanthesesRelated.cpp<br>
│   └── stackqueue.cpp<br>
├── DS1: Tree Binary Tree<br>
│   ├── avltree.cpp<br>
│   ├── BinaryTree.cpp<br>
│   └── BST.cpp<br>
├── DS2: Heap<br>
│   ├── binaryheap.cpp<br>
│   └── BinomialHeap.cpp<br>
├── G1: Basic Graph (BFS, DFS)<br>
│   ├── Bfs.java<br>
│   ├── BfsShortestPath.java<br>
│   ├── Bipartite.java<br>
│   ├── bipartitie.cpp<br>
│   ├── cycle_detection_directed.cpp<br>
│   ├── CycleDetectionDirected.java<br>
│   ├── cycle_detection_undirected.cpp<br>
│   ├── CycleDetectionUndirected.java<br>
│   ├── dfs.java<br>
│   ├── Graph.cpp<br>
│   ├── graphwithedges.cpp<br>
│   ├── topological_sort.cpp<br>
│   └── topologicalSort.java<br>
├── G2: Grid Recursion<br>
│   ├── floodfillalgo.cpp<br>
│   ├── labshortestpathgrid.cpp<br>
│   ├── minimumstepknightneedtoreachtarget.cpp<br>
│   └── ratinamze.cpp<br>
├── G4: Disjoint Set Union<br>
│   ├── dsu1.cpp<br>
│   ├── dsu2.cpp<br>
│   ├── DSUrankPathCompression.java<br>
│   └── inp.txt<br>
├── G5: Bridge Articulation Point<br>
│   ├── articulation point and bridges.cpp<br>
│   ├── ArticulationPointAndBridges.java<br>
│   ├── bestEulerTour.java<br>
│   ├── bridge_articulation.cpp<br>
│   ├── bridge.cpp<br>
│   ├── EulerTour.java<br>
│   ├── inp.txt<br>
│   ├── input1.txt<br>
│   ├── output1.txt<br>
│   └── output.txt<br>
├── G6: Euler Circuit<br>
│   ├── best euler tour.cpp<br>
│   ├── euler tours.cpp<br>
│   └── inp.txt<br>
├── G7: Strongly Connected Compound<br>
│   ├── inp.txt<br>
│   ├── kosaraju algorithm for SCC.cpp<br>
│   ├── KosarajuAlgorithm.java<br>
│   ├── scc.cpp<br>
│   ├── topological Order.cpp<br>
│   └── TopologicalOrder.java<br>
├── G8: Minimum Spanning Tree<br>
│   ├── input1.txt<br>
│   ├── input2.txt<br>
│   ├── input3.txt<br>
│   ├── input4.txt<br>
│   ├── Kruskal Algo Test Driver Code.py<br>
│   ├── Kruskal.java<br>
│   ├── Kruskal_MST.cpp<br>
│   ├── Prim Algo Test Driver Code.py<br>
│   ├── Prim_MST.cpp<br>
│   ├── Prim’s and Kruskal’s Algorithm for Minimum Spanning Tree Analysis.pdf<br>
│   ├── Prims.java<br>
│   ├── Random_Graph_Generation.py<br>
│   └── README.md<br>
├── G9: Shortest Path Algorithm<br>
│   ├── G9.1: Single Source Shortest Path<br>
│   │   ├── 743.network-delay-time.cpp<br>
│   │   ├── bellmanford.cpp<br>
│   │   ├── dijkastra.cpp<br>
│   │   ├── inputdj.txt<br>
│   │   └── Readme.md<br>
│   └── G9.2: All Pair Shortest Path<br>
│       ├── floydwarshallworking.cpp<br>
│       ├── inputdj.txt<br>
│       ├── jhonsonfinal.cpp<br>
│       ├── jhonsons2working.cpp<br>
│       ├── jhonsonsalgorithm.cpp<br>
│       ├── jhonsonscoded.cpp<br>
│       └── output.txt<br>
├── Greedy: Huffman Coding<br>
│   ├── hf1.cpp<br>
│   ├── hf2.cpp<br>
│   └── hftemplate.cpp<br>
├── NF0: Network Flow Basic<br>
│   ├── dinicsAlgo.java<br>
│   ├── dinic's algprithm.cpp<br>
│   ├── driver2.cpp<br>
│   ├── driver.cpp<br>
│   ├── edmond-karp-coded.cpp<br>
│   ├── edmond-karp.cpp<br>
│   ├── edmondkarp_fordfulkerson.cpp<br>
│   ├── inp.txt<br>
│   ├── mbm_maxflow.cpp<br>
│   ├── showsir2.sh<br>
│   ├── showsir.sh<br>
│   └── sirinput.txt<br>
├── NT1: Eucleadian Algorithm GCD<br>
│   ├── gcd_extended.cpp<br>
│   ├── Linear_diaphantine_eqn.png<br>
│   ├── Linear_Diophantine_Equations.cpp<br>
│   ├── multiplicative_modulo_inverse.cpp<br>
│   └── Multiplicative_Modulo_Inverse_using_extended_Eucledian.png<br>
├── Sort1: Sorting Algo<br>
│   ├── CountingInversionUsingMergeSort.cpp<br>
│   └── sorting.cpp<br>
└── T1: Segment Tree<br>
    ├── FLIPCOIN-codechef.cpp<br>
    ├── Readme.md<br>
    ├── segmenttree.cpp<br>
    └── segment+tree+with+lazy+propagation.cpp<br>
