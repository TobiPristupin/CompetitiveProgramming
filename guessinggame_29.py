import sys

lines = [l.strip() for l in sys.stdin.readlines()]
index = 0

while lines[index] != "0":
	low, maxx = 0, 11
	while True:
		guess, text = int(lines[index]), lines[index + 1]
		index += 2
		
		if "right on" in text:
			if guess >= maxx or guess <= low:
				print("Stan is dishonest")
			else :
				print("Stan may be honest")
			break
		
		elif "high" in text:
			maxx = guess if guess < maxx else maxx
		else :
			low = guess if guess > low else low
		
		if low >= maxx:
			print("Stan is dishonest")
			try:
				index = lines.index("right on", index) + 1
				break
			except IndexError:
				sys.exit()


