
def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def shellSort(arr):
    gap = len(arr) // 2
    while gap > 0:
        for i in range(gap, len(arr)):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# List of percentages
percentage = [85, 95, 35, 97, 70]

# Displaying results
print("Marks before sorting:", percentage)

# Using Shell Sort
shellSort(percentage)
print("\nMarks after Shell Sort:", percentage)

# Using Insertion Sort
insertionSort(percentage)
print("\nMarks after Insertion Sort:", percentage)

