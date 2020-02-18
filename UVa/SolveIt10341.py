import sys
from math import sin, cos, tan, e

def f(x):
    return p*(e**-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*(x**2) + u

for line in sys.stdin:
    p, q, r, s, t, u = map(int, line.split())
    lo, hi = 0, 1
    x = (lo + hi) / 2
    val = f(x)
    
    tries = 0
    while tries < 50 and abs(val) > 0.000001:
        if val > 0:
            lo = x
        else:
            hi = x
        x = (lo + hi) / 2
        val = f(x)
        tries += 1
        
    if tries == 50:
        print("No solution")
    else:
        print("{:.4f}".format(x))