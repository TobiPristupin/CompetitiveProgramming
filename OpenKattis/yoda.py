from collections import deque

a, b = input(), input()
a = a.zfill(len(b))
b = b.zfill(len(a))

out_a = deque()
out_b = deque()

for i, j in zip(a, b):
    if int(i) > int(j):
        out_a.append(i)
    elif int(i) < int(j):
        out_b.append(j)
    else:
        out_a.append(i)
        out_b.append(i)

ans_a = "YODA" if len(out_a) == 0 else int("".join(out_a))
ans_b = "YODA" if len(out_b) == 0 else int("".join(out_b))
print(ans_a)
print(ans_b)
