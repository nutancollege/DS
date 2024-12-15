
def quik_sort(percent):
    if len(percent) <= 1:
        return percent
    else:
        pivot = percent[0]
        left_element = [i for i in percent[1:] if i <= pivot]
        right_element = [i for i in percent[1:] if i > pivot]
        return quik_sort(left_element) + [pivot] + quik_sort(right_element)

percentages = []
students = int(input("Enter the no. of students: "))

for i in range(students):
    percentage = float(input(f"Enter percentage for student {i+1}: "))
    percentages.append(percentage)

sorted_percentages = quik_sort(percentages)

if len(sorted_percentages) < 5:
    top_five = sorted_percentages
else:
    top_five = sorted_percentages[-5:]

print("Top Scores:")
for score in top_five:
    print(score)
