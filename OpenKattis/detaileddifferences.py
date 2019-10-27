n = int(input())
for _ in range(n):
    a = input()
    b = input()
    print(a)
    print(b)
    for i in range(len(a)):
        if a[i] == b[i]:
            print(".", end="")
        else:
            print("*", end="")
    print()
    print()