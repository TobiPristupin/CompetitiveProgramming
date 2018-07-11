import sys

for line in sys.stdin:
	nums = line.split(" ")
	print(abs(int(nums[0]) - int(nums[1])))