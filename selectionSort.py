import time

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(i + 1, n):
            if arr[j] < arr[i]:
                arr[i], arr[j] = arr[j], arr[i]

def import_numbers_from_file(file_path):
    with open(file_path, 'r') as file:
        numbers = list(map(int, file.read().split()))
    return numbers

def measure_time(file_path):
    numbers = import_numbers_from_file(file_path)
    
    start_time = time.time()
    selection_sort(numbers)
    end_time = time.time()

    print(f"Sorted list: {numbers[:5]}")
    print(f"processing time: {end_time - start_time:.3f} second")


measure_time("dataset.txt")
