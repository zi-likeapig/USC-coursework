import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import find_peaks
from scipy.interpolate import splev, splrep

#read and deal raw data
raman=pd.read_table('raman.txt',header=None)
#print(raman.head())  # print first few rows
raman_array=raman.to_numpy()
dis=60  #hei=0
peaks,_=find_peaks(raman_array[:,1],distance=dis,height=2000)
print(peaks)
raman_peak_list=[]
for i in peaks:
    raman_peak_list.append(raman_array[i])
raman_peak_array=np.array(raman_peak_list)
#print(raman_peak_array)


#spline
spl=splrep(raman_peak_array[:,0],raman_peak_array[:,1])
#spl=splrep(raman_peak_array[:,0],raman_peak_array[:,1])
x=np.linspace(500,3500,30000)
y=splev(x,spl)
dy=splev(x,spl,der=1)


#find maximum
raman_max_wavenumber=[]
raman_max_intensity=[]
#threshold_max=1.5  #and abs(dy[i])<threshold_max 
threshold_min=0.07
prior_i=0
for i in range(1,len(dy)-1):
    if abs(dy[i])>threshold_min and dy[i-1]>0 and dy[i+1]<0:
        #print(i)
        #Take the smaller derivative of two adjacent points
        if i==prior_i+1:
            #print("next")
            if abs(dy[i])>abs(dy[prior_i]):
                continue
            else:
                raman_max_wavenumber.pop()
                raman_max_intensity.pop()
                raman_max_wavenumber.append(x[i])
                raman_max_intensity.append(y[i])
                continue
        raman_max_wavenumber.append(x[i])
        raman_max_intensity.append(y[i])
        prior_i=i

plt.plot(raman_array[:,0],raman_array[:,1])
plt.scatter(raman_peak_array[:,0],raman_peak_array[:,1],marker='x',color='orange')
plt.xlabel("Wavenumber (in cm-1)")
plt.ylabel("intensity")
plt.title("Raman data")
plt.legend(['interpolating intensity', 'top8 maximum intensity'])
plt.show()
""""""
"""
#Q1
raman_peak_sortU=np.argsort(raman_max_intensity)
raman_peak_sortD=raman_peak_sortU[::-1]
raman_top8max_wavenumber=[]
raman_top8max_intensity=[]
print("The eight largest spectral peak:")
for i in range(8): 
    raman_top8max_wavenumber.append(raman_max_wavenumber[raman_peak_sortD[i]])
    raman_top8max_intensity.append(raman_max_intensity[raman_peak_sortD[i]])
    print("No",i+1,": wavenumber:",raman_top8max_wavenumber[i],' intensity:',raman_top8max_intensity[i])
"""

"""
#Q2
plt.plot(x,y)
plt.scatter(raman_top8max_wavenumber,raman_top8max_intensity,marker='x',color='orange')
plt.xlabel("Wavenumber (in cm-1)")
plt.ylabel("intensity")
plt.title("Raman data")
plt.legend(['interpolating intensity', 'top8 maximum intensity'])
plt.show()
"""

"""
#Q3
def find_width(peak_index,peak_intensity):
    threshold=peak_intensity/2
    widths=np.arange(50, 0, -1)
    for w in widths:
        if raman_array[peak_index-1,1]-raman_array[peak_index-w-1,1]<threshold:
            print(w)
            #print(raman_array[peak_index-1,1])
            #print(raman_array[peak_index-w-1,1])
            return w

peak_sortU=np.argsort(raman_peak_array[:,1])
peak_sortD=peak_sortU[::-1]
peak_index=[]
peak_intensity=[]
for i in range(10):
    print(raman_peak_array[peak_sortD[i]])
    #peak_index.append(peak_sortD[i])
    #peak_intensity.append(raman_peak_array[peak_sortD[i]])
    width=find_width(peak_sortD[i],raman_peak_array[peak_sortD[i],1])
#for i in range(4):
    #width=find_width(peak_index[i],peak_intensity[i])
    #print(width)
"""

"""
    #spline
    l_range=peak_sortD[i]-1-width
    r_range=peak_sortD[i]-1+width
    spl_in=splrep(raman_array[l_range:r_range,0],raman_array[l_range:r_range,1])
    x_in=np.linspace(raman_array[l_range,0],raman_array[r_range,0],1000)
    y_in=splev(x_in,spl_in)
    dy_in=splev(x_in,spl_in,der=1)

    plt.figure()
    plt.plot(x_in,y_in)
    #plt.scatter(raman_top8max_wavenumber,raman_top8max_intensity,marker='x',color='orange')
    plt.xlabel("Wavenumber (in cm-1)")
    plt.ylabel("intensity")
    plt.title("Raman data")
    plt.legend(['interpolating intensity', 'top8 maximum intensity'])
    plt.show()

"""

"""
top_peaks=[]
for i in range(4):
    top_peaks.append(raman_peak_array[raman_peak_sortD[i]])
top_peaks_array=np.array(top_peaks)
print(top_peaks_array)

raman_peak_array[raman_peak_sortD[0]]
n0=100

"""