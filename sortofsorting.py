while (True):
	n = int(raw_input())
	# the program stops when input is 0
	if n == 0:
		break
	names = []
	for _ in range(n):
		names.append(raw_input())
	# use sorted function to sort through the names
	names = sorted(names, key = lambda x: (x[0], x[1]))
	# print out the result 
	for name in names:
		print name
	# print a new line 
	print ''