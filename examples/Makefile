# Jack Rabbit Examples Makefile
# jsp Fri Feb  6 17:42:54 CST 2009

CCFILES=$(shell ls -1 *.cc)
TARGETS=$(basename $(CCFILES))
INCLUDEPATH=..
DEPENDPATH=..
EXTRA_SOURCES=
LIBS=

include ../../Makefile.examples

doc:
	./pyramid_example0
	./pyramid_example1
	# Convert for use in documentation
	./raster_example0
	./raster_example1
	./raster_example2
	convert pyramid_example1_grayscale.pgm pyramid_example1_grayscale.png
	convert pyramid_example1_color.ppm pyramid_example1_color.png
	convert raster_example1.pgm raster_example1.png
	convert raster_example2.ppm raster_example2.png
	-display pyramid_example1_grayscale.png
	-display pyramid_example1_color.png
	-display raster_example1.png
	-display raster_example2.png

clean_images:
	rm -f *_example*.png
	rm -f *_example*.p?m
