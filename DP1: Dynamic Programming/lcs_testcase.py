import sys
import random
import os
import string

# Print
file_path = 'inp.txt'
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

