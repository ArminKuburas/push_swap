import random

unique_numbers = random.sample(range(1, 501), 500)

print(' '.join(map(str, unique_numbers)))