n = int(input())
a, b = input(), input()
for i, j in zip(a, b):
    if i == j and n % 2 == 1:
        print("Deletion failed")
        exit()
    elif i != j and n % 2 == 0:
        print("Deletion failed")
        exit()

print("Deletion succeeded")
