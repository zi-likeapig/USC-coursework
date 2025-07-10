import pandas as pd

# Load the CSV file
file_path = r"C:\Users\42097\Downloads\wine+quality\winequality-red.csv"  # Replace with your CSV file path
data = pd.read_csv(file_path, sep=";")
print(data.shape)

pH_array = data.iloc[:30, 8].to_numpy()  # 9th column (index 8)
sulphates_array = data.iloc[:30, 9].to_numpy()  # 10th column (index 9)

# Print the arrays
print("pH Array:", pH_array)
print("Sulphates Array:", sulphates_array)

# Optionally save the extracted data to a new CSV file
# selected_data.to_csv("selected_data.csv", index=False)
