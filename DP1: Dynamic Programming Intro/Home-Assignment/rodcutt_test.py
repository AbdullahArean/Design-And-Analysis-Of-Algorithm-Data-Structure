import sys
import random
import os



# Print
file_path = 'inp.txt'
sys.stdout = open(file_path, "w")
lowb=100
upb=200
n=random.randint(lowb,upb)
print(n)
for i in range(n):
    m=random.randint(lowb,upb)
    print(m)
    for j in range(m):
        print(random.randint(10,50), end=" ")
    print()

#Test With Code
str1 = 'rodcutting_memo'
str= 'rodcutting_rec'
str2= 'rodcutting_bottomup'
#os.system(f"cd '../Home-Assignment/' && g++ {str}.cpp -o {str} && '../Home-Assignment/'{str}")
os.system(f"cd '../Home-Assignment/' && g++ {str1}.cpp -o {str1} && '../Home-Assignment/'{str1}")
os.system(f"cd '../Home-Assignment/' && g++ {str2}.cpp -o {str2} && '../Home-Assignment/'{str2}")



