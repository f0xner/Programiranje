#!/usr/bin/python3

from PIL import Image
import glob
def conversion(filename):
	img = Image.open(filename)
	filename = filename[0:len(filename)-3]+"png"
	img.save(filename,"png")
if __name__ == '__main__':
	slike = glob.glob("Fraktali/*.bmp")
	for slika in slike:
		print("Delam ",slika)
		conversion(slika)
