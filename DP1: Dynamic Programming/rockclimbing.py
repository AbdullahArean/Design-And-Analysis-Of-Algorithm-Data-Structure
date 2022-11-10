import sys
import random
import os



# Print
file_path = 'inp.txt'
sys.stdout = open(file_path, "w")
n=random.randint(100,500);
m=random.randint(100,500);

print(n, end=" ")
print(m)
for i in range(n):
    for j in range(m):
        print(random.randint(10,50), end=" ")
    print()

#Test With Code
str = 'rodcutting_memo'
    #str2= 'Prim_MST'
    #os.system(f"cd '../Home-Assignment/' && g++ {str}.cpp -o {str} && '../Prim-Kruskal-Graph-Implementation/'{str}")
    #os.system(f"cd '../Prim-Kruskal-Graph-Implementation/' && g++ {str2}.cpp -o {str2} && '../Prim-Kruskal-Graph-Implementation/'{str2}")




