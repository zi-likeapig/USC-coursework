import numpy as np

b=np.array([[pow(2,1/3),2*pow(2,1/3),pow(2,1/3),pow(2,1/3)-2],
            [0,-1,0,0],
            [0,1,0,1],
            [0,1,0,1]])
c=np.dot(b,b)
d=np.dot(c,b)
print(d)