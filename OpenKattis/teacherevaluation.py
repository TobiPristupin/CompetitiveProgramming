import sys

students, goal = map(int, input().split())
score = sum(map(int, input().split()))
forged = 0

if goal == 100:
    print("impossible")
    sys.exit()

while goal != score:
    forged += 1
    x = goal * (students + 1) - score
    if x <= 100:
        print(forged)
        break
    else:
        students += 1
        score += 100
