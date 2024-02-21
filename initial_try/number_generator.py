import random

unique_numbers = random.sample(range(1, 1001), 100)

print(' '.join(map(str, unique_numbers)))