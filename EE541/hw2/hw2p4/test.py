import math

n=14603983
#while abs(pow(1+2/n,n)-pow(math.e,2)) >= pow(10,-6):
#    n+=1
print(abs(pow(1+2/n,n)-pow(math.e,2)))