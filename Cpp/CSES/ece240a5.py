s = 0
for i in range(1,10):
	s += 1/(i**2)
	if s >= 1.48:
		print(i)
		break

print("Done")
