import itertools
import subprocess

# Define the numbers
numbers = [1, 2, 3, 4, 5]

# Generate all permutations
permutations = itertools.permutations(numbers)

# Function to format a permutation as a string
def format_permutation(perm):
    return ' '.join(str(num) for num in perm)

# Call push_swap with each permutation
for perm in permutations:
    perm_str = format_permutation(perm)
    # Call push_swap with subprocess
    push_swap_result = subprocess.run(['./push_swap', perm_str], capture_output=True, text=True)
    instruction_count = subprocess.run(['echo', push_swap_result.stdout.strip()], stdout=subprocess.PIPE, text=True)
    wc_result = subprocess.run(['wc', '-l'], input=instruction_count.stdout, capture_output=True, text=True)
    
    print(f"Permutation: {perm_str}")
    print("Instructions:", push_swap_result.stdout)
    print("Number of instructions:", wc_result.stdout.strip())
    print("Exit code:", push_swap_result.returncode)