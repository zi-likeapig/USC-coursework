import numpy as np
from scipy.optimize import minimize

K = np.array([
    [1, 1, 1, 1],
    [1, 4, 1, 0],
    [1, 1, 4, 1],
    [1, 0, 1, 4]
], dtype='double')

z = np.array([-1, 1, 1, 1])
Q = np.outer(z, z) * K

def objective(l):
    return -np.sum(l) + 0.5 * np.dot(l, np.dot(Q, l))

constraints = {'type': 'eq', 'fun': lambda l: np.dot(l, z)}
bounds = [(0, None)] * 4
l0 = np.zeros(4)

res = minimize(objective, l0, bounds=bounds, constraints=constraints)
print(res.x)
