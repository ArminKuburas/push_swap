import itertools
import subprocess
import os

# Define the numbers
numbers = [1, 2, 3, 4, 5]

# Generate all permutations
permutations = itertools.permutations(numbers)

# Function to format a permutation as a string
def format_permutation(perm):
    return ' '.join(str(num) for num in perm)

# Counters for instructions
under_12_count = 0
over_12_count = 0
max_moves = 0
min_moves = float('inf')
max_perm = None
min_perm = None

# Directory to save permutations
output_dir = "permutations"
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

# Call push_swap with each permutation
for idx, perm in enumerate(permutations, start=1):
    perm_str = format_permutation(perm)
    # Call push_swap with subprocess
    push_swap_result = subprocess.run(['./push_swap', perm_str], capture_output=True, text=True)
    move_count = len(push_swap_result.stdout.strip().split('\n'))
    
    if move_count <= 12:
        under_12_count += 1
    else:
        over_12_count += 1
        # Save permutation to file
        with open(os.path.join(output_dir, f"test_{idx}.txt"), "w") as f:
            f.write(perm_str)
    
    # Update max and min moves
    if move_count > max_moves:
        max_moves = move_count
        max_perm = perm_str
    if move_count < min_moves:
        min_moves = move_count
        min_perm = perm_str

# Calculate percentages
total_tests = under_12_count + over_12_count
under_12_percent = (under_12_count / total_tests) * 100
over_12_percent = (over_12_count / total_tests) * 100

# Print results
print("Percentage of tests under 12 moves:", under_12_percent)
print("Percentage of tests over 12 moves:", over_12_percent)
print("Test with the most moves:", max_perm)
print("Test with the least moves:", min_perm)
