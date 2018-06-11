villagers = [set() for _ in range(int(input()) - 1)]
songs = 0

for _ in range(int(input())):
	present = list(map(int, input().split()[1:]))
	if 1 in present:
		songs += 1
		for i in present:
			if i is not 1:
				villagers[i - 2].add(songs)
	else:
		all_songs = set()
		for i in present:
			all_songs.update(villagers[i - 2])
		for i in present:
			villagers[i - 2].update(all_songs)

print(1)
for index, item in enumerate(villagers):
	if len(item) == songs:
		print(index + 2)






