import matplotlib.pyplot as plt
import re

# Step 1: Read the timing data from the benchmark output file
# The file "timing_results.txt" contains the output of our C++ benchmark, with lines like:
# "Data size: 1000"
# "  Unsorted Vector Find Time Avg: 0.1 us, Min: 0.09 us, Max: 0.12 us"
# We read all lines into a list for parsing.
with open("timing_results.txt") as f:
    lines = f.readlines()

# Step 2: Initialize data structures to store the parsed data
# 'sizes' will store the input sizes (e.g., 1000, 10000, 100000, 1000000, 10000000)
# 'results' is a dictionary with keys "Unsorted", "Sorted", "Set" (corresponding to the three search methods)
# For each method, we store:
# - 'avg': Average time per find (in microseconds)
# - 'min': Best-case time (minimum over trials)
# - 'max': Worst-case time (maximum over trials)
sizes = []
results = {
    "Unsorted Vector": {"avg": [], "min": [], "max": []},
    "Sorted Vector": {"avg": [], "min": [], "max": []},
    "Set": {"avg": [], "min": [], "max": []},
}

# Step 3: Parse the benchmark output to extract sizes and times
# We loop through each line in the file:
# - If the line contains "Data size", extract the size (e.g., 1000) and add to 'sizes'
# - If the line contains "Unsorted Vector", "Sorted Vector", or "std::set", extract the avg, min, and max times
# The times are in microseconds with decimals (e.g., 0.1 us), so we use regex to match both integers and decimals
# Since the benchmark runs once per size, we can directly append the times without aggregating duplicates
for line in lines:
    if "Data size" in line:
        # Extract the input size using regex (e.g., "Data size: 1000" -> 1000)
        size = int(re.search(r"Data size: (\d+)", line).group(1))
        sizes.append(size)
    elif "Unsorted Vector" in line:
        # Extract avg, min, max times (e.g., "Avg: 0.1 us, Min: 0.09 us, Max: 0.12 us" -> [0.1, 0.09, 0.12])
        m = re.findall(r"(\d+\.\d+|\d+)", line)
        results["Unsorted Vector"]["avg"].append(float(m[0]))  # Average time per find
        results["Unsorted Vector"]["min"].append(float(m[1]))  # Best-case time
        results["Unsorted Vector"]["max"].append(float(m[2]))  # Worst-case time
    elif "Sorted Vector" in line:
        m = re.findall(r"(\d+\.\d+|\d+)", line)
        results["Sorted Vector"]["avg"].append(float(m[0]))
        results["Sorted Vector"]["min"].append(float(m[1]))
        results["Sorted Vector"]["max"].append(float(m[2]))
    elif "std::set" in line:
        m = re.findall(r"(\d+\.\d+|\d+)", line)
        results["Set"]["avg"].append(float(m[0]))
        results["Set"]["min"].append(float(m[1]))
        results["Set"]["max"].append(float(m[2]))

# Step 4: Compute error bars for the first plot
# We want to plot the average times with error bars showing the best (min) and worst (max) cases
# - 'lower' error bar: avg - min (distance from avg to best case)
# - 'upper' error bar: max - avg (distance from avg to worst case)
# This creates asymmetric error bars, which is important because best/worst cases may not be symmetric around the avg
error_bars = {
    "Unsorted Vector": {"lower": [], "upper": []},
    "Sorted Vector": {"lower": [], "upper": []},
    "Set": {"lower": [], "upper": []},
}

for label in results:
    error_bars[label]["lower"] = [avg - min_val for avg, min_val in zip(results[label]["avg"], results[label]["min"])]
    error_bars[label]["upper"] = [max_val - avg for avg, max_val in zip(results[label]["avg"], results[label]["max"])]

# Step 5: Create the first plot with error bars (average times with best/worst case bounds)
plt.figure(figsize=(12, 7))  # Set the figure size (12 inches wide, 7 inches tall)
for label, color in zip(["Unsorted Vector", "Sorted Vector", "Set"], ["red", "blue", "green"]):
    # Plot the average times with error bars
    # - sizes: Input sizes (e.g., 1000, 10000)
    # - results[label]["avg"]: Average times for this method
    # - yerr: Error bars (lower: avg - min, upper: max - avg)
    # - fmt='-o': Plot as a line with dots at each point
    # - capsize=5: Size of the error bar caps
    plt.errorbar(sizes, results[label]["avg"], yerr=[error_bars[label]["lower"], error_bars[label]["upper"]], 
                 label=label, fmt='-o', capsize=5, color=color)

# Configure the plot with log-log scaling
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Number of Elements (log scale)")  # Label for x-axis
plt.ylabel("Find Time (microseconds, log scale)")  # Label for y-axis
plt.title("Average Find Times with Error Bars (Best to Worst Cases)")  # Plot title
plt.legend()  # Show the legend (Unsorted, Sorted, Set)
plt.grid(True, which="both", linestyle="--", alpha=0.5)  # Add a grid for readability
plt.tight_layout()  # Adjust layout to prevent label clipping
plt.show()  # Display the plot

# Step 6: Create the second plot showing only max times (without error bars)
# - This shows the worst-case performance for each method
# - Useful for understanding the upper bound on execution time
plt.figure(figsize=(12, 7))  # Set the figure size (12 inches wide, 7 inches tall)
for label, color in zip(["Unsorted Vector", "Sorted Vector", "Set"], ["red", "blue", "green"]):
    # Plot only the max times as a simple line plot
    # - sizes: Input sizes (e.g., 1000, 10000)
    # - results[label]["max"]: Maximum times for this method
    plt.plot(sizes, results[label]["max"], label=label, color=color, marker='o')

# Configure the plot with log-log scaling
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Number of Elements (log scale)")  # Label for x-axis
plt.ylabel("Max Find Time (microseconds, log scale)")  # Label for y-axis
plt.title("Maximum (Worst-Case) Find Times Across Data Structures")  # Plot title
plt.legend()  # Show the legend (Unsorted, Sorted, Set)
plt.grid(True, which="both", linestyle="--", alpha=0.5)  # Add a grid for readability
plt.tight_layout()  # Adjust layout to prevent label clipping
plt.show()  # Display the plot

# Step 5: Print the data for verification
# This helps us check the times and error bars to ensure they make sense
# For each method, print the avg, best (min), worst (max) times, and the error bar ranges
for label in results:
    print(f"{label} Avg: {results[label]['avg']}")  # Average times
    print(f"{label} Best: {results[label]['min']}")  # Best-case times
    print(f"{label} Worst: {results[label]['max']}")  # Worst-case times
    print(f"{label} Error Bars (lower, upper): {list(zip(error_bars[label]['lower'], error_bars[label]['upper']))}")  # Error bar ranges