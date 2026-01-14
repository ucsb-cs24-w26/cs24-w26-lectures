import numpy as np
import matplotlib.pyplot as plt

# Data setup
n = np.logspace(1, 5, 100)  # Input sizes from 10^1 to 10^5

# Time complexities
unsorted_vector = n / 10                  # O(n) with initial advantage
sorted_vector = np.log2(n)                # O(log n)
set_structure = np.log2(n) * 1.2          # O(log n) with slight overhead

# Plotting
plt.figure(figsize=(10, 6))
plt.loglog(n, unsorted_vector, 'r-', linewidth=3, label='Unsorted Vector (O(n))')
plt.loglog(n, sorted_vector, 'b-', linewidth=3, label='Sorted Vector (O(log n))')
plt.loglog(n, set_structure, 'g--', linewidth=3, label='Set (Balanced BST, O(log n))')

# Labels and formatting
plt.xlabel('Number of Elements (n)', fontsize=16)
plt.ylabel('Operations (Time Units)', fontsize=16)
plt.title('Scaling of Worst-Case Find Operations', fontsize=18)
plt.legend(fontsize=14, loc='upper left')
plt.grid(True, which="both", linestyle='--', linewidth=0.5)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.tight_layout()

# Show plot
plt.show()

