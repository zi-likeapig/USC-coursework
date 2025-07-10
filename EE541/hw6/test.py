import cv2
import numpy as np
import matplotlib.pyplot as plt

# 读取灰度图像
img = cv2.imread("hw\hw6\hello.png", cv2.IMREAD_GRAYSCALE)
img = cv2.resize(img, (100, 100))  # 调整尺寸

# 奇异值分解
U, S, Vt = np.linalg.svd(img, full_matrices=False)

# 定义奇异值保留的数量
k_values = [5, 20, 50, 100]

# 创建图像的不同奇异值近似
fig, axs = plt.subplots(1, len(k_values) + 1, figsize=(15, 5))
axs[0].imshow(img, cmap="gray")
axs[0].set_title("Original")
axs[0].axis("off")

# 保留不同数量的奇异值来重建图像
for i, k in enumerate(k_values):
    # 仅保留前 k 个奇异值
    U_k = U[:, :k]
    S_k = np.diag(S[:k])
    Vt_k = Vt[:k, :]
    
    # 重建图像
    img_approx = U_k @ S_k @ Vt_k
    
    # 显示重建图像
    axs[i + 1].imshow(img_approx, cmap="gray")
    axs[i + 1].set_title(f"k = {k}")
    axs[i + 1].axis("off")

plt.show()
