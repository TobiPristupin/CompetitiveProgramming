from collections import deque

for _ in range(int(input())):
	input()
	input()
	godzilla = deque(sorted([int(n) for n in input().split()]))
	mecha = deque(sorted([int(n) for n in input().split()]))

	while godzilla and mecha :
		mecha.popleft() if mecha[0] <= godzilla[0] else godzilla.popleft()

	print("{}".format("Godzilla" if not mecha else "MechaGodzilla")) 
	
