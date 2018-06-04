import sys

variables = {}

for line in sys.stdin.readlines():
	if line == "0":
		break
	
	constant = 0
	result = []

	for expr in line.strip().split(" + "):
		if "=" in expr:
			variables[expr.split(" = ")[0]] = int(expr.split(" = ")[1])
		elif expr in variables:
			constant += variables[expr]
		elif expr.isdigit():
			constant += int(expr)
		else:
			result.append(expr)

	if constant != 0 or result :
		print("{const}{addition}{result}".format(
			const = constant if constant != 0 else "",
			addition = " + " if constant != 0 and result else "",
			result = " + ".join(result))
		) 
