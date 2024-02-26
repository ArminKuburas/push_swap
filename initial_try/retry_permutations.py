import os
import subprocess

# Function to run push_swap and count moves
def run_push_swap(perm_str):
    push_swap_result = subprocess.run(['./push_swap', perm_str], capture_output=True, text=True)
    move_count = len(push_swap_result.stdout.strip().split('\n'))
    return move_count, push_swap_result.stdout

# Directory containing permutation files
permutations_dir = "permutations"

# Parameters
total_tests = 0
above_threshold_count = 0
below_threshold_count = 0

# Run each permutation in the directory
for filename in os.listdir(permutations_dir):
    if filename.endswith(".txt"):
        total_tests += 1
        with open(os.path.join(permutations_dir, filename), "r") as f:
            perm_str = f.read().strip()
            move_count, instructions = run_push_swap(perm_str)
            if move_count > 5500:
                above_threshold_count += 1
                print(f"\033[33mPermutation from {filename}: {move_count} moves\033[0m")  # Highlight text in yellow
            else:
                below_threshold_count += 1
                print(f"Permutation from {filename}: {move_count} moves")

# Calculate percentages
above_threshold_percentage = (above_threshold_count / total_tests) * 100
below_threshold_percentage = (below_threshold_count / total_tests) * 100

# Print results
print(f"Percentage of tests with moves above 5500:", above_threshold_percentage)
print(f"Percentage of tests with moves below 5500:", below_threshold_percentage)

