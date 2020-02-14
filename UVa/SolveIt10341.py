import sys
from math import sin, cos, tan, e
for line in sys.stdin:
    p, q, r, s, t, u = map(int, line.split())
    for x in range(7000, 7500):
        x /= 10000
        val = p*(e**-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*(x**2) + u
        print(val, x)