def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quicksort(left) + middle + quicksort(right)

def display_top_scores(arr, top_n=5):
    print(f"Top {top_n} scores:")
    for score in arr[-top_n:]:
        print(score)

percentages = []
while True:
    try:
        num_students = int(input("Enter the number of students: "))
        if num_students <= 0:
            raise ValueError("Number of students must be a positive integer.")
        break
    except ValueError as e:
        print(f"Invalid input: {e}. Please try again.")

for i in range(num_students):
    while True:
        try:
            score = float(input(f"Enter the percentage for student {i + 1}: "))
            percentages.append(score)
            break
        except ValueError:
            print("Invalid input. Please enter a valid number.")

sorted_percentages = quicksort(percentages)
print("\nSorted percentages:")
print(sorted_percentages)
display_top_scores(sorted_percentages)
