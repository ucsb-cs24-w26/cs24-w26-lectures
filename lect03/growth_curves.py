"""
Generate order of growth graphs for Lecture 03: Big-O Analysis
- Unlabeled version: for student discussion ("which matches recursive Fib?")
- Labeled version: reveals the function names
"""

import numpy as np
import matplotlib.pyplot as plt

def generate_growth_curves(labeled=True, output_file=None):
    """Generate growth curves graph, optionally labeled."""

    n = np.linspace(1, 100, 500)

    # Define functions
    constant = np.ones_like(n)
    log_n = np.log2(n)
    sqrt_n = np.sqrt(n)
    linear = n
    n_log_n = n * np.log2(n) / 4
    quadratic = (n ** 2) / 100   
    exponential = 2 ** (n / 8)    

    fig, ax = plt.subplots(figsize=(10, 8))

    # Plot curves with distinct colors and styles
    ax.plot(n, constant, 'purple', linewidth=2.5, linestyle='dotted')
    ax.plot(n, log_n, 'blue', linewidth=2.5)
    ax.plot(n, sqrt_n, 'cyan', linewidth=2.5)
    ax.plot(n, linear, 'green', linewidth=2.5)
    ax.plot(n, n_log_n, 'orange', linewidth=2.5)
    ax.plot(n, quadratic, 'red', linewidth=2.5, linestyle='dashed')
    ax.plot(n, np.clip(exponential, 0, 100), 'darkred', linewidth=2.5, linestyle='dashdot')

    ax.set_xlim(0, 100)
    ax.set_ylim(0, 100)
    ax.set_xlabel('n (input size)', fontsize=18)
    ax.set_ylabel('Growth', fontsize=18)
    ax.tick_params(axis='both', labelsize=14)
    ax.grid(True, alpha=0.3)

    if labeled:
        ax.set_title('Orders of Growth', fontsize=22)
        # Add function labels
        ax.text(97, linear[-2], 'n', fontsize=16, fontweight='bold',
                color='green', va='center')
        ax.text(60,  80, 'n log n', fontsize=16, fontweight='bold',
                color='orange', va='center')
        ax.text(82, 72, 'n²', fontsize=16, fontweight='bold',
                color='red', va='center')
        ax.text(42, 72, '2ⁿ', fontsize=16, fontweight='bold',
                color='darkred', va='center')
        ax.text(97, sqrt_n[-1], '√n', fontsize=16, fontweight='bold',
                color='cyan', va='center')
        ax.text(97, log_n[-1], 'log n', fontsize=16, fontweight='bold',
                color='blue', va='center')
        ax.text(97, constant[-1], '1', fontsize=16, fontweight='bold',
                color='purple', va='center')
    else:
        ax.set_title('', fontsize=22)  # No title - instructor provides context
        # Add letter labels instead
        ax.text(97, linear[-2], 'A', fontsize=18, fontweight='bold',
                color='green', va='center')
        ax.text(60, 80, 'B', fontsize=18, fontweight='bold',
                color='orange', va='center')
        ax.text(82, 72, 'C', fontsize=18, fontweight='bold',
                color='red', va='center')
        ax.text(42, 72, 'D', fontsize=18, fontweight='bold',
                color='darkred', va='center')
        ax.text(97, sqrt_n[-1], 'E', fontsize=18, fontweight='bold',
                color='cyan', va='center')
        ax.text(97, log_n[-1], 'F', fontsize=18, fontweight='bold',
                color='blue', va='center')
        ax.text(97, constant[-1], 'G', fontsize=18, fontweight='bold',
                color='purple', va='center')

    plt.tight_layout()

    if output_file:
        plt.savefig(output_file, dpi=150, bbox_inches='tight',
                    facecolor='white', edgecolor='none')
        print(f"Saved: {output_file}")

    return fig, ax


if __name__ == "__main__":
    # Generate unlabeled version (for Slide 8)
    generate_growth_curves(labeled=False, output_file='growth_curves_unlabeled.png')

    # Generate labeled version (for Slide 9)
    generate_growth_curves(labeled=True, output_file='growth_curves_labeled.png')

    print("\nGenerated files:")
    print("  - growth_curves_unlabeled.png ")
    print("  - growth_curves_labeled.png  ")
