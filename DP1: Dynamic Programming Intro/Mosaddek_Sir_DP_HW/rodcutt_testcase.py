import sys
import random
import os



# Print
file_path = 'inp.txt'
sys.stdout = open(file_path, "w")
lowb=10
upb=20
n=random.randint(lowb,upb)
print(n)
for i in range(n):
    m=random.randint(lowb,upb)
    print(m)
    for j in range(m):
        print(random.randint(10,50), end=" ")
    print()



