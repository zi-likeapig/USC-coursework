#from func import f
import sys
def f(x):
    return x**3 - x**2 - 1

def secant_method(a,b,X_values):
    if not X_values:    #list is empty
        X_values.append(a)
        X_values.append(b)
    if abs(b-a) <= 1e-10:
        #print("end")
        return
    else:
        b_=b
        #if (f(b)-f(a))==0:
            #print("Range error", file=sys.stderr)
            #sys.exit(1)
        b=b-f(b)*(b-a)/(f(b)-f(a))
        X_values.append(b)
        #print(b_,b)
        return secant_method(b_,b,X_values)

"""
a=float(sys.argv[1])
b=float(sys.argv[2])
if not isinstance(a,float) or not isinstance(b,float):
    print("Range error", file=sys.stderr)  #STDERR
    sys.exit(1)
if a>=b or f(a)*f(b)>=0:
    print("Range error", file=sys.stderr)  #STDERR
    sys.exit(1)
"""
a=1.0
b=2.0
X_values=[]
secant_method(a,b,X_values)
length=len(X_values)
print(X_values)
sys.stdout.write(str(length)+'\n')
#print(length)
for i in range (length-3,length):   #[)
    #print(X_values[i])
    sys.stdout.write(str(X_values[i])+'\n')