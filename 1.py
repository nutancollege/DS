// 01.
// Write a Python program to store marks scored in the subject “Fundamentals of Data Structure” by N students in the class. Write functions to compute the following:
// a) The average score of the class
// b) The highest score and the lowest score of the class
// c) The count of students who were absent for the test
// d) Display the mark with the highest frequency

// Code

def get_student_marks():
    N = int(input("Enter the number of students: "))
    marks = []
    for i in range(N):
        mark = int(input(f"Enter marks for Student {i + 1} (use -1 if absent): "))
        marks.append(mark)
    return marks

def compute_average(marks):
    total = 0
    count = 0
    for mark in marks:
        if mark != -1:
            total += mark
            count += 1
    if count == 0:
        return 0
    return total / count

def find_highest_lowest(marks):
    highest = -float('inf')
    lowest = float('inf')
    for mark in marks:
        if mark != -1:
            if mark > highest:
                highest = mark
            if mark < lowest:
                lowest = mark
    return highest, lowest

def count_absent_students(marks):
    count = 0
    for mark in marks:
        if mark == -1:
            count += 1
    return count

def mark_with_highest_frequency(marks):
    max_frequency = 0
    most_frequent_mark = None
    for i in range(len(marks)):
        if marks[i] == -1:
            continue

        frequency = 0
        for j in range(len(marks)):
            if marks[i] == marks[j]:
                frequency += 1

        if frequency > max_frequency:
            max_frequency = frequency
            most_frequent_mark = marks[i]

    return most_frequent_mark

def main():
    marks = get_student_marks()

    avg_score = compute_average(marks)
    highest_score, lowest_score = find_highest_lowest(marks)
    absent_count = count_absent_students(marks)
    most_frequent_mark = mark_with_highest_frequency(marks)

    print("\nClass Statistics:")
    print(f"Average Score: {avg_score:.2f}")
    print(f"Highest Score: {highest_score}")
    print(f"Lowest Score: {lowest_score}")
    print(f"Number of Absent Students: {absent_count}")
    print(f"Mark with Highest Frequency: {most_frequent_mark}")

if __name__ == "__main__":
    main()
