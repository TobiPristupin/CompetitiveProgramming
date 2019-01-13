students = [int(input()) for _ in range(int(input()))]

def can_shorten(m):
    shortened = set()
    for k in range(len(students)):
        short = students[k] % m
        if short in shortened:
            return False
        shortened.add(short)
    return True


for m in range(len(students), 10 ** 6):
    if can_shorten(m):
        print(m)
        break

