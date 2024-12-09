import random

def generate_dataset(file_name, num_elements, min_value=1, max_value=1000000):
    with open(file_name, 'w') as file:
        for _ in range(num_elements):
            number = random.randint(min_value, max_value)
            file.write(f"{number}\n")

generate_dataset("dataset.txt", 10**4)
print("Done...")

