import numpy as np
import matplotlib.pyplot as plt

def trapezoid_phi(u):
    u = np.abs(u)
    result = np.zeros_like(u)
    result[(u >= 0) & (u < 0.5)] = 1
    result[(u >= 0.5) & (u <= 1)] = -2 * u[(u >= 0.5) & (u <= 1)] + 2
    return result

x_vals = np.linspace(-1, 8, 1000)
h = 1

# ω1 = {0, 2, 5}
D1 = [0, 2, 5]
p1 = np.zeros_like(x_vals)
for xj in D1:
    p1 += trapezoid_phi((x_vals - xj) / h)
p1 /= len(D1)

# ω2 = {4, 7}
D2 = [4, 7]
p2 = np.zeros_like(x_vals)
for xj in D2:
    p2 += trapezoid_phi((x_vals - xj) / h)
p2 /= len(D2)

# Plot
plt.figure(figsize=(10, 5))
plt.plot(x_vals, p1, label=r'$p(x|\omega_1)$', color='blue')
plt.plot(x_vals, p2, label=r'$p(x|\omega_2)$', color='red')
plt.xlabel('x')
plt.ylabel('Estimated Density')
plt.title('Parzen Window Density Estimates using Trapezoidal Kernel')
plt.legend()
plt.grid(True)
plt.show()
