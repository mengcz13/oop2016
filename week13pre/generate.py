import sys
import random

def main():
	if (len(sys.argv) != 3):
		print("Usage: python generate.py <filename> <size>")
		return
	rng = random
	randsize = int(sys.argv[2])
	array = range(1, randsize + 1)
	rng.shuffle(array)
	with open(sys.argv[1], 'w') as f:
		f.write("%d\n" % (randsize))
		for x in array:
			f.write("%d\n" % (x))

if __name__ == '__main__':
	main()
