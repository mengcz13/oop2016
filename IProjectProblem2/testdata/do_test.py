# -*- coding:utf-8 -*-
import random
import os


def do_test():
	datasize = range(5000, 15001, 1000)
	passnum = 0
	failnum = 0
	totalnum = len(datasize)
	maxpointsize = 10000
	for data in datasize:
		inputfile = 'data%d.txt' % (data)
		with open(inputfile, 'w') as f:
			f.write('%d\n' % (data))
			for x in xrange(data):
				px = random.uniform(0, maxpointsize)
				py = random.uniform(0, maxpointsize)
				f.write('%f %f\n' % (px, py))
		print('\n#############################')
		print('Testing %s ...' % (inputfile))
		print('#############################')
		os.system(r'../Problem2/main ../testdata/%s ../testdata/output%d_cgal.txt' % (inputfile, data))
		os.system(r'../Problem2_test/testmain ../testdata/%s ../testdata/output%d_naive.txt' % (inputfile, data))
		res1 = 0
		res2 = 0
		with open('output%d_cgal.txt' % (data)) as f:
			line = f.readline().split()
			res1 = float(line[2])
		with open('output%d_naive.txt' % (data)) as f:
			line = f.readline().split()
			res2 = float(line[2])
		print('#############################')
		print('Result test: %d; Result standard:%d' % (res1, res2))
		if (abs(res1 - res2) < 1e-6):
			print('Pass!')
			passnum = passnum + 1
		else:
			print('Fail!')
			failnum = failnum + 1
		print('#############################')
	print('%d test case in total, pass %d, fail %d.' % (totalnum, passnum, failnum))


if __name__ == '__main__':
	do_test()