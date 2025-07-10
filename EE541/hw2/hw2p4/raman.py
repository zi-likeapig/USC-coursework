import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import find_peaks
from scipy.interpolate import splev, splrep


raman=pd.read_table('raman.txt',header=None)
#print(raman.head())  # print first few rows
raman_array=raman.to_numpy()
#print(raman_array)

#find peaks
dis=85  #hei=0  #height到底是什么??????????????
peaks,_=find_peaks(raman_array[:,1],distance=dis)
#peaks,_=find_peaks(raman_array[:,1],distance=dis, height=hei)
#print(peaks)
raman_peak_list=[]
for i in peaks:
    raman_peak_list.append(raman_array[i])
raman_peak_array=np.array(raman_peak_list)
#print(raman_peak_array)


#Q1 #这一问不用插值吗，结果会受find_peak影响??????????????
raman_peak_sortU=np.argsort(raman_peak_array[:,1])
raman_peak_sortD=raman_peak_sortU[::-1]
for i in range(9):
    print(1)
    print(raman_peak_array[raman_peak_sortD[i]])


#Q2 #需要标数据吗;maximum是指导数为0的点吗??????????????
spl=splrep(raman_peak_array[:,0],raman_peak_array[:,1],s=0.1)
#spl=splrep(raman_array[:,0],raman_array[:,1])
x=np.linspace(500,3500,30000)
y=splev(x,spl)
dy=splev(x,spl,der=1)

raman_spline_max_wavenumber=[]
raman_spline_max_intensity=[]
threshold_min=0.2
#threshold_max=20   #abs(dy[i])<threshold_max
for i in range(1,len(dy)-1):
    if abs(dy[i])>threshold_min and dy[i-1]>0 and dy[i+1]<0:
    #if abs(dy[i])<threshold:
        #print(dy[i])
        raman_spline_max_wavenumber.append(x[i])
        raman_spline_max_intensity.append(y[i])

plt.plot(x,y)
plt.scatter(raman_spline_max_wavenumber,raman_spline_max_intensity,marker='x',color='orange')
plt.xlabel("wavenumber")
plt.ylabel("intensity")
plt.title("Raman data and the maximum intensity values")
plt.show()

"""
plt.plot(x,y)
plt.scatter(raman_peak_array[:,0],raman_peak_array[:,1],color='orange',marker='x')
#plt.plot(raman_peak_array[:,0],raman_peak_array[:,1],marker='x',color='b')
plt.xlabel('wavenumber')
plt.ylabel('intensity')
plt.title('Raman spectrum')
plt.show()
"""

#Q3 #interest的范围是指？？（正好一个高峰？）
"""
top_peaks=[]
for i in range(4):
    top_peaks.append(raman_peak_array[raman_peak_sortD[i]])
top_peaks_array=np.array(top_peaks)
print(top_peaks_array)

raman_peak_array[raman_peak_sortD[0]]
n0=100
"""



"""
def find_width(peak_index,peak_intensity):
    threshold=peak_intensity/2
    widths=np.arange(6, 0, -1)
    for w in widths:
        if raman_array[peak_index-1,1]-raman_array[peak_index-w-1,1]<threshold:
            print(peak_index-w)
            print(raman_array[peak_index-1,1])
            print(raman_array[peak_index-w-1,1])
            return w

peak_index=[640,1915,1350,2356]
peak_intensity=[15300,5279,3374,1423]
for i in range(4):
    width=find_width(peak_index[i],peak_intensity[i])
    #print(width)

    #spline
    l_range=peak_index[i]-1-width
    r_range=peak_index[i]-1+width
    spl_in=splrep(raman_array[l_range:r_range,0],raman_array[l_range:r_range,1],s=3)
    x_in=np.linspace(raman_array[l_range,0],raman_array[r_range,0],1000)
    y_in=splev(x_in,spl_in)
    dy_in=splev(x_in,spl_in,der=1)

    plt.figure()
    plt.plot(x_in,y_in)
    plt.scatter(raman_array[l_range:r_range,0],raman_array[l_range:r_range,1],marker='o',color='orange')
    plt.xlabel("Wavenumber (in cm-1)")
    plt.ylabel("intensity")
    plt.title("Raman data")
    plt.legend(['interpolating intensity', 'raw data'])
    plt.show()
"""