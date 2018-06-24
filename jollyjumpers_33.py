import sys

for line in sys.stdin.readlines():
    numbers = list(map(int, line.split()))
    differences = set()
    for i in range(len(numbers) - 1):
        differences.update([abs(numbers[i] - numbers[i + 1])])
    for i in range(1, len(numbers) - 1):
        if i not in differences:
            print("Not jolly")
            break
    else:
        print("Jolly")