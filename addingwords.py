import sys

variables = {}
values = {}

for line in sys.stdin:
    line = line.replace("\n", "").lower().split()
    
    if line[0] == "def":
        if line[1] in variables:
            del values[variables[line[1]]]
        
        variables[line[1]] = int(line[2])
        values[int(line[2])] = line[1]
        continue

    if line[0] == "clear":
        variables = {}
        values = {}
        continue

    copy = " ".join(line[1:])
    line = line[1:len(line) - 1]

    for i in range(len(line)):
        if line[i] in variables:
            line[i] = variables[line[i]]
        elif line[i] not in "+-":
            print(copy, "unknown")
            break
    else:
        result = eval("".join(map(str, line)))
        if result in values:
            print(copy, values[result])
        else:
            print(copy, "unknown")

