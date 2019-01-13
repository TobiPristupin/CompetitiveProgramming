from collections import deque
import heapq

def main():
    queue = deque()
    stack = deque()
    priority = []
    valid = {"queue", "stack", "priority queue"}

    for _ in range(int(input())):
        operation, number = map(int, input().split())
        if operation == 1:
            queue.append(number) if "queue" in valid else None
            stack.appendleft(number) if "stack" in valid else None
            heapq.heappush(priority, -number) if "priority queue" in valid else None
            # priority.append(number) ; priority.sort(reverse=True) if "priority queue" in valid else None
        else:
            try :
                valid.discard("queue") if "queue" in valid and queue.popleft() != number else None
                valid.discard("stack") if "stack" in valid and stack.popleft() != number else None
                valid.discard("priority queue") if "priority queue" in valid and heapq.heappop(priority) != -number else None
            except IndexError:  # Getting more items than added, this data structure doesn't exist
                valid.clear()
                break

    if len(valid) == 0:
        print("impossible")
    elif len(valid) == 1:
        print(valid.pop())
    else:
        print("not sure")
    

while True:
    try:
        main()
    except EOFError:
        break
