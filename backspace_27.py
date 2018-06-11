from collections import deque

text = input()
result = deque()
backspaces = 0

for item in reversed(text):
	if item == "<":
		backspaces += 1
	elif backspaces > 0:
		backspaces -= 1
	else :
		result.appendleft(item)

print("".join(result))




	

