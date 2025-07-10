import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

matplotlib.use('TkAGG')
# 提供的数据
data = {
    "Sweetness index (Y)": [5.20, 5.50, 6.00, 5.90, 5.80, 6.00, 5.80, 5.60, 5.60, 5.90, 5.40, 5.60,
                            5.80, 5.50, 5.30, 5.30, 5.70, 5.50, 5.70, 5.30, 5.90, 5.80, 5.80, 5.90],
    "Pectin content (X)": [220.00, 227.00, 259.00, 210.00, 224.00, 215.00, 231.00, 268.00, 239.00,
                           212.00, 410.00, 256.00, 306.00, 259.00, 284.00, 383.00, 271.00, 264.00,
                           227.00, 263.00, 232.00, 220.00, 246.00, 241.00]
}

df = pd.DataFrame(data)

# 计算统计量
x = df["Pectin content (X)"]
y = df["Sweetness index (Y)"]

x_mean = np.mean(x)
y_mean = np.mean(y)

sx = np.std(x, ddof=1)  # 样本标准差
sy = np.std(y, ddof=1)

sx2 = sx ** 2
sy2 = sy ** 2

sxy = np.cov(x, y, ddof=1)[0, 1]

rxy = sxy / (sx * sy)
rxy2 = rxy ** 2

# 回归方程
b = sxy / sx2
a = y_mean - b * x_mean

# 散点图
plt.figure(figsize=(8, 6))
plt.scatter(x, y, color='blue', label='Data points')
plt.plot(x, a + b * x, color='red', label=f'Regression line: Y = {a:.2f} + {b:.4f}X')
plt.title("Sweetness Index vs Pectin Content")
plt.xlabel("Pectin Content (ppm)")
plt.ylabel("Sweetness Index")
plt.legend()
plt.grid()
plt.savefig('linear_regression.jpg')
plt.show()

# 展示计算结果
statistics = {
    "x_mean": x_mean, "y_mean": y_mean, "sx": sx, "sy": sy,
    "sx2": sx2, "sy2": sy2, "sxy": sxy, "rxy": rxy, "rxy2": rxy2,
    "a (intercept)": a, "b (slope)": b
}
statistics_df = pd.DataFrame(statistics, index=["Value"]).T
# print("统计结果已保存为 'statistics_results.xlsx' 文件，请检查工作目录。")

statistics_df.to_excel('result.xlsx',index=False)