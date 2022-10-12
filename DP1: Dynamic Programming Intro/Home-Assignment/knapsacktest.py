import sys
import random
import os
import string

# Print
file_path = 'inp.txt'
sys.stdout = open(file_path, "w")
lowb=10
upb=20
n=random.randint(lowb,upb)
print(n, end=' ')
print(n*2)
for i in range(n):
    N=random.randint(lowb,upb)
    print( N, end=' ')
    NN=random.randint(lowb,upb)
    print(NN)

#Test With Code
str= 'knapsack_rec'
str1 = 'knapsack_memo'
str2= 'knapsack_bottomup'
os.system(f"cd '../Home-Assignment/' && g++ {str}.cpp -o {str} && '../Home-Assignment/'{str}")
# os.system(f"cd '../Home-Assignment/' && g++ {str1}.cpp -o {str1} && '../Home-Assignment/'{str1}")
# os.system(f"cd '../Home-Assignment/' && g++ {str2}.cpp -o {str2} && '../Home-Assignment/'{str2}")



