/ Code




def addition(matrix1, matrix2, mat1row, mat2col, result):
    for i in range(0, mat1row):
        for j in range(0, mat2col):
            result[i][j] = matrix1[i][j] + matrix2[i][j]

    print("Addition of two matrix is ")
    for i in range(0, mat1row):
        for j in range(0, mat2col):
            print(result[i][j], end="")
        print()

def subtraction(matrix1, matrix2, mat1row, mat2col, result):
    for i in range(0, mat1row):
        for j in range(0, mat2col):
            result[i][j] = matrix1[i][j] - matrix2[i][j]

    print("Subtraction of two matrix is ")
    for i in range(0, mat1row):
        for j in range(0, mat2col):
            print(result[i][j], end="")
        print()

def multiplication(matrix1, matrix2):
    temp = [[0, 0], [0, 0]]
    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                temp[i][j] += matrix1[i][k] * matrix2[k][j]
    print("Multiplication of two matrix is ")
    for result in temp:
        print(result)
def transpose(matrix1, mat1row, mat1col):
    result = [[0 for x in range(mat1row)] for y in range(mat1col)]
    
    for i in range(0, mat1row):
        for j in range(0, mat1col):
            result[j][i] = matrix1[i][j]
    
    print("Transpose of Matrix 1 is ")
    for i in range(0, mat1col):
        for j in range(0, mat1row):
            print(result[i][j], end=" ")
        print()

if __name__ == "__main__":
    print("INPUT FOR MATRIX 1")
    mat1row = int(input("Enter the number of rows = "))
    mat1col = int(input("Enter the number of columns = "))
    matrix1 = []
    for i in range(0, mat1row):
        a = []
        for j in range(0, mat1col):
            a.append(int(input()))
        matrix1.append(a)

    print("Matrix 1")
    for i in range(0, mat1row):
        for j in range(0, mat1col):
            print(matrix1[i][j], end=" ")
        print()
    
    print("INPUT FOR MATRIX 2")
    mat2row=int(input("Enter the number of rows ="))
    mat2col=int(input("Enter the number of columns ="))
    
    matrix2=[]
    for i in range(0,mat2row):
        a=[]
        for j in range(0,mat2col):
            a.append(int(input()))
        matrix2.append(a)    
    
print("Matrix 2")
for i in range(0, mat2row):
    for j in range(0, mat2col):
        print(matrix2[i][j], end="")
    print()

result = [[0, 0], [0, 0]]

print("")

print("-----SELECT AN OPTION------")
print("Option 1 : Press 1 to get Addition of Matrix ")
print("Option 2 : Press 2 to get Subtraction of Matrix ")
print("Option 3 : Press 3 to get Multiplication of Matrix ")
print("Option 4 : Press 4 to get Transpose of Matrix ")
print("Option 5 : Press 0 for Exit")

while(True):
    cases = int(input("Enter Your Option Number Here --> "))

    match cases:
        case 0:
            print("Exit")
            break
        case 1:
            addition(matrix1, matrix2, mat1row, mat2col, result)
        case 2:
            subtraction(matrix1, matrix2, mat1row, mat2col, result)
        case 3:
            multiplication(matrix1, matrix2)
        case 4:
            transpose(matrix1, mat1row, mat1col)
        case _:
            print("OOPS!!! INVALID INPUT!!") 
