import itertools
import subprocess
import os
import random
import shutil

# Function to generate unique numbers using random.sample
def generate_unique_numbers(size):
    return random.sample(range(1, size + 1), size)

# Function to format a permutation as a string
def format_permutation(perm):
    return ' '.join(str(num) for num in perm)

# Function to run push_swap and count moves
def run_push_swap(perm_str):
    push_swap_result = subprocess.run(['./push_swap', perm_str], capture_output=True, text=True)
    move_count = len(push_swap_result.stdout.strip().split('\n'))
    return move_count, push_swap_result.stdout

# Directory to save permutations
output_dir = "permutations"
if os.path.exists(output_dir):
    shutil.rmtree(output_dir)
os.makedirs(output_dir)

# Parameters
total_tests = 1000
threshold_moves = 5500
above_threshold_count = 0
below_threshold_count = 0
worst_test = None
worst_moves = 0

# Run tests
for test_num in range(1, total_tests + 1):
    unique_numbers = generate_unique_numbers(500)
    perm_str = format_permutation(unique_numbers)
    move_count, instructions = run_push_swap(perm_str)
    
    if move_count > threshold_moves:
        above_threshold_count += 1
        # Save permutation to file
        with open(os.path.join(output_dir, f"test_{test_num}.txt"), "w") as f:
            f.write(perm_str)
        if move_count > worst_moves:
            worst_moves = move_count
            worst_test = f"test_{test_num}.txt"
        print(f"\033[33mTest {test_num}: {move_count} moves\033[0m")  # Highlight text in yellow
    else:
        below_threshold_count += 1
        print(f"Test {test_num}: {move_count} moves")

# Calculate percentages
above_threshold_percentage = (above_threshold_count / total_tests) * 100
below_threshold_percentage = (below_threshold_count / total_tests) * 100

# Print results
print(f"Percentage of tests with moves above {threshold_moves}:", above_threshold_percentage)
print(f"Percentage of tests with moves below {threshold_moves}:", below_threshold_percentage)
print("Number of tests done:", total_tests)
print("Worst test (most moves above 5500):", worst_test, "with", worst_moves, "moves")
