low = 0
high = 1001
guess = 500
print(guess)
inp = input()


while inp != "correct":
	if inp == "higher":
		low = guess
	else:
		high = guess
	guess = (low + high) // 2
	print(guess)
	inp = input()