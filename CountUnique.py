#!/usr/bin/python
import sys
def CountUnique(filename):
	words = {}
	count = 0
	with open(filename) as readFile:
		for line in readFile.readlines():
			texts = line.split(" ")
			for word in texts:
				if word in words:
					words[word] += 1
				else:
					words[word] = 1
	for word in words:
		count += 1
	return count 

def main():
	filename = sys.argv[1]
	count = CountUnique(filename)
	print count

if __name__=="__main__":
	main()
