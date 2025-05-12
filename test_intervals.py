import matplotlib.pyplot as plt
import numpy as np
from typing import List, Tuple, Set, Optional
import random
import seaborn as sns

class IntervalVisualizer:
    def __init__(self):
        sns.set_style('whitegrid')
        self.colors = {
            'red': '#ff6b6b',
            'selected_red': '#d63031',
            'blue': '#74b9ff',
            'grid': '#dfe6e9'
        }
    
    def plot_intervals(
        self,
        red_intervals: List[Tuple[int, int]],
        blue_intervals: List[Tuple[int, int]],
        selected_red: Optional[Set[Tuple[int, int]]] = None,
        filename: str = 'interval_coverage.pdf'
    ):
        plt.figure(figsize=(15, 8))
        
        # Calculate plot boundaries
        all_points = [point for interval in red_intervals + blue_intervals 
                     for point in interval]
        x_min, x_max = min(all_points) - 1, max(all_points) + 1
        
        # Plot blue intervals
        for i, (start, end) in enumerate(blue_intervals):
            plt.hlines(y=1, xmin=start, xmax=end, 
                      color=self.colors['blue'], 
                      alpha=0.7, linewidth=6, 
                      label='Blue Intervals' if i == 0 else "")
            # Add interval labels
            plt.text((start + end) / 2, 0.9, f'[{start}, {end}]', 
                    horizontalalignment='center')
        
        # Plot red intervals
        for i, (start, end) in enumerate(red_intervals):
            if selected_red and (start, end) in selected_red:
                plt.hlines(y=2, xmin=start, xmax=end, 
                          color=self.colors['selected_red'], 
                          linewidth=6, 
                          label='Selected Red' if i == 0 else "")
            else:
                plt.hlines(y=2, xmin=start, xmax=end, 
                          color=self.colors['red'], 
                          alpha=0.3, linewidth=6, 
                          label='Red Intervals' if i == 0 else "")
            # Add interval labels
            plt.text((start + end) / 2, 2.1, f'[{start}, {end}]', 
                    horizontalalignment='center')
        
        plt.ylim(0.5, 2.5)
        plt.xlim(x_min, x_max)
        plt.yticks([1, 2], ['Blue Intervals', 'Red Intervals'])
        plt.grid(True, alpha=0.2, color=self.colors['grid'])
        plt.legend(loc='upper right')
        plt.title('Interval Coverage Visualization', pad=20, fontsize=14)
        plt.xlabel('Time', fontsize=12)
        
        # Save with high DPI for better quality
        plt.savefig(filename, dpi=300, bbox_inches='tight')
        plt.close()

def generate_test_cases():
    test_cases = [
        # Original test case
        {
            'name': 'Original Example',
            'red': [(0, 4), (2, 5), (4, 8), (9, 10), (10, 12), (11, 12)],
            'blue': [(0, 2), (5, 5), (7, 10), (11, 13)],
            'selected': [(2, 5), (4, 8), (11, 12)],
            'expected_count': 3
        },
        # Edge case: No overlap
        {
            'name': 'No Overlap',
            'red': [(0, 1), (2, 3), (4, 5)],
            'blue': [(6, 7), (8, 9), (10, 11)],
            'selected': set(),
            'expected_count': 0
        },
        # Edge case: Perfect coverage
        {
            'name': 'Perfect Coverage',
            'red': [(0, 5), (5, 10), (10, 15)],
            'blue': [(1, 4), (6, 9), (11, 14)],
            'selected': [(0, 5), (5, 10), (10, 15)],
            'expected_count': 3
        },
        # Edge case: Single point intervals
        {
            'name': 'Single Point Intervals',
            'red': [(1, 1), (2, 2), (3, 3), (4, 4)],
            'blue': [(1, 1), (3, 3)],
            'selected': [(1, 1), (3, 3)],
            'expected_count': 2
        },
        # Complex case: Nested intervals
        {
            'name': 'Nested Intervals',
            'red': [(0, 10), (2, 8), (4, 6)],
            'blue': [(1, 9), (3, 7), (5, 5)],
            'selected': [(0, 10)],
            'expected_count': 1
        },
        # Stress test: Many intervals
        {
            'name': 'Many Intervals',
            'red': [(i, i+2) for i in range(0, 20, 2)],
            'blue': [(i, i+1) for i in range(1, 19, 2)],
            'selected': [(i, i+2) for i in range(0, 20, 2)],
            'expected_count': 10
        }
    ]
    return test_cases

def run_tests():
    visualizer = IntervalVisualizer()
    test_cases = generate_test_cases()
    
    for i, test in enumerate(test_cases, 1):
        print(f"\n=== Test Case {i}: {test['name']} ===")
        print(f"Red intervals: {test['red']}")
        print(f"Blue intervals: {test['blue']}")
        print(f"Expected selected intervals: {test['selected']}")
        print(f"Expected count: {test['expected_count']}")
        
        # Generate visualization
        filename = f'interval_coverage_test_{i}.pdf'
        visualizer.plot_intervals(
            test['red'],
            test['blue'],
            set(test['selected']),
            filename
        )
        print(f"Visualization saved as {filename}")

if __name__ == "__main__":
    run_tests()