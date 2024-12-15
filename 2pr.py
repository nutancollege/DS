# Function to input student roll numbers for each sport group..........
def get_student_list(group_name):
    n = int(input(f"Enter the number of students who play {group_name}: "))
    group = []
    for i in range(n):
        roll_no = int(input(f"Enter roll number {i + 1}: "))
        if roll_no not in group:  # avoid duplicate entries.......
            group.append(roll_no)
    return group

# Function to find students who play both cricket and badminton..........
def cric_and_bad(cricket, badminton):
    cAb = []
    for student in cricket:
        if student in badminton and student not in cAb:
            cAb.append(student)
    return cAb

# Function to find students who play either cricket or badminton but not both.........
def cric_or_bad(cricket, badminton):
    cOb = []
    for student in cricket:
        if student not in badminton:
            cOb.append(student)
    for student in badminton:
        if student not in cricket:
            cOb.append(student)
    return cOb

# Function to count students who play neither cricket nor badminton..........
def neither_cric_nor_bad(total_students, cricket, badminton):
    cNb = []
    for student in range(1, total_students + 1):
        if student not in cricket and student not in badminton:
            cNb.append(student)
    return len(cNb)

# Function to find students who play cricket and football but not badminton.........
def cric_and_foot_not_bad(cricket, football, badminton):
    result = []
    for student in cricket:
        if student in football and student not in badminton:
            result.append(student)
    return result

def main():
    total_students = int(input("Enter the total number of students in the class: "))
    cricket = get_student_list("cricket")
    badminton = get_student_list("badminton")
    football = get_student_list("football")
    
    # a) Students who play both cricket and badminton.............
    both_cricket_badminton = cric_and_bad(cricket, badminton)
    print("Students who play both cricket and badminton:", both_cricket_badminton)

    # b) Students who play either cricket or badminton but not both............
    either_cricket_badminton = cric_or_bad(cricket, badminton)
    print("Students who play either cricket or badminton but not both:", either_cricket_badminton)

    # c) Number of students who play neither cricket nor badminton.............
    neither_cricket_badminton_count = neither_cric_nor_bad(total_students, cricket, badminton)
    print("Number of students who play neither cricket nor badminton:", neither_cricket_badminton_count)

    # d) Students who play cricket and football but not badminton...........
    cricket_football_not_badminton = cric_and_foot_not_bad(cricket, football, badminton)
    print("Students who play cricket and football but not badminton:", cricket_football_not_badminton)

if __name__ == "__main__":
    main()
