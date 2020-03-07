import sys

speeds = [(0, 0)]
for line in sys.stdin:
    line = line.replace("\n", "").split()
    h, m, s = map(int, line[0].split(":"))
    t = h + m / 60 + s / 3600
    
    if len(line) == 2:
        speeds.append((t, int(line[1])))
        continue
    
    distance = 0
    for i, speed in enumerate(speeds):
        if t > speed[0]:
            if i == len(speeds) - 1:
                distance += (t - speed[0]) * speed[1]
                continue
            if t > speeds[i + 1][0]:
                distance += (speeds[i + 1][0] - speed[0]) * speed[1]
            else:
                distance += (t - speed[0]) * speed[1]
    print("{} {:.2f} km".format(line[0], distance))
