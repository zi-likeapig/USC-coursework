import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import find_peaks
from scipy.interpolate import splev, splrep


#read raw data
raman=pd.read_table('raman.txt',header=None)
raman_array=raman.to_numpy()

#detect top peaks
dis=60  
hei=2000
peaks,_=find_peaks(raman_array[:,1],distance=dis,height=hei)
raman_peak_list=[]
raman_peak_index=[]
for i in peaks:
    raman_peak_list.append(raman_array[i])
    raman_peak_index.append(i)
raman_peak_array=np.array(raman_peak_list)
#print(raman_peak_array)

peak_sortU=np.argsort(raman_peak_array[:,1])
peak_sortD=peak_sortU[::-1]
top8peak_wavenumber=[]
top8peak_intensity=[]
#print("The eight largest spectral peak:")
for i in range(8): 
    #print(raman_array[raman_peak_index[peak_sortD[i]]])
    top8peak_wavenumber.append(raman_peak_array[peak_sortD[i],0])
    top8peak_intensity.append(raman_peak_array[peak_sortD[i],1])
    #print("No",i+1,": wavenumber:",top8peak_wavenumber[i],' intensity:',top8peak_intensity[i])


#interpolate intensity within each region of interest
for i in range(4):
    w=23
    l_range=raman_peak_index[peak_sortD[i]]-1-w
    r_range=raman_peak_index[peak_sortD[i]]-1+w
    #print(raman_peak_index[peak_sortD[i]],l_range,r_range)
    #spline
    spl=splrep(raman_array[l_range:r_range,0],raman_array[l_range:r_range,1])
    x=np.linspace(raman_array[l_range,0],raman_array[r_range,0],200*w)
    y=splev(x,spl)
    dy=splev(x,spl,der=1)

    #find maximum
    max_wavenumber=[]
    max_intensity=[]
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
                    max_wavenumber.pop()
                    max_intensity.pop()
                    max_wavenumber.append(x[i])
                    max_intensity.append(y[i])
                    continue
            max_wavenumber.append(x[i])
            max_intensity.append(y[i])
            prior_i=i
            
    top1max_index=np.argmax(max_intensity)
    top1max_x=max_wavenumber[top1max_index]
    top1max_y=max_intensity[top1max_index]
    
    plt.figure(figsize=(6,4))
    plt.plot(x,y,linewidth=1)
    plt.scatter(top1max_x,top1max_y,marker='x',color='red',s=40)
    plt.scatter(raman_array[l_range:r_range,0],raman_array[l_range:r_range,1],marker='o',color='black',s=6)
    plt.axhline(y=top1max_y,color='orange',linestyle='--',linewidth=0.7)
    plt.axvline(x=top1max_x,color='orange',linestyle='--',linewidth=0.7)
    plt.xlabel("Wavenumber (in cm-1)")
    plt.ylabel("intensity")
    plt.title("Raman data")
    plt.legend(['interpolating intensity', 'maximum intensity','raw data'],fontsize=7,loc='lower left')
    plt.show()