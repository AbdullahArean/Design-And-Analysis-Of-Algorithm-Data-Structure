import sys
import random
import os
import string

# Print
file_path = 'inp1.txt'
sys.stdout = open(file_path, "w")
lowb=10
upb=20
n=1
print(n)
for i in range(n):
    N=random.randint(lowb,upb)
    res = ''.join(random.choices(string.ascii_lowercase + string.digits, k=N))
    print( str(res), end=' ')
    NN=random.randint(lowb,upb)
    res = ''.join(random.choices(string.ascii_lowercase + string.digits, k=NN))
    print( str(res))

#Test With Code
str1 = 'lcs_memo'
str= 'lcs_rec'
str2= 'lcs_bottomup'
os.system(f"cd '../Home-Assignment/' && g++ {str}.cpp -o {str} && '../Home-Assignment/'{str}")
os.system(f"cd '../Home-Assignment/' && g++ {str1}.cpp -o {str1} && '../Home-Assignment/'{str1}")
os.system(f"cd '../Home-Assignment/' && g++ {str2}.cpp -o {str2} && '../Home-Assignment/'{str2}")



