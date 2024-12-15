

def LinearSearch(l, key):
    for i in range(len(l)):
        if l[i] == key:
            return i
    return -1

def SentinelSearch(l, key):
    l.append(key)
    i = 0
    while l[i] != key:
        i += 1
    return -1 if i == len(l) - 1 else i

def BinarySearch(l, key):
    left, right = 0, len(l) - 1
    while left <= right:
        mid = (left + right) // 2
        if key == l[mid]:
            return mid
        elif key < l[mid]:
            right = mid - 1
        else:
            left = mid + 1
    return -1

def FibonacciSearch(l, key):
    fib2, fib1, fib = 0, 1, 1
    while fib < len(l):
        fib2, fib1 = fib1, fib
        fib = fib2 + fib1
    offset = -1
    while fib > 1:
        i = min(offset + fib2, len(l) - 1)
        if l[i] < key:
            fib, fib1, fib2 = fib1, fib2, fib - fib1
            offset = i
        elif l[i] > key:
            fib, fib1, fib2 = fib2, fib1 - fib2, fib - fib1
        else:
            return i
    if fib1 and offset + 1 < len(l) and l[offset + 1] == key:
        return offset + 1
    return -1

digits = [int(input(f"Enter number {i}: ")) for i in range(int(input("Enter the length of list: ")))]
key = int(input("Key element to find: "))

print("Linear Search index:", LinearSearch(digits, key))
print("Sentinel Search index:", SentinelSearch(digits, key))
print("Binary Search index:", BinarySearch(sorted(digits), key))
print("Fibonacci Search index:", FibonacciSearch(sorted(digits), key))


