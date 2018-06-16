from collections import deque

while True:
    a, b = map(int, input().split())
    
    if a == 0 and b == 0:
        break

    dragons = deque(sorted([int(input()) for _ in range(a)]))
    knights = deque(sorted([int(input()) for _ in range(b)]))
    gold = 0
    
    if sum(dragons) > sum(knights) or len(dragons) > len(knights):
       print("Loowater is doomed!")
       continue

    while len(dragons) > 0 and len(knights) > 0:
        if knights[0] < dragons[0]:
            knights.popleft()
        else:
            gold += knights.popleft()
            dragons.popleft()

    print(gold) if len(dragons) == 0 else print("Loowater is doomed!")


