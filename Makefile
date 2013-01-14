# Jack Rabbit Makefile
#
# Copyright (C) 2008-2013 Jeffrey S. Perry
#
# contact: jeffsp@gmail.com

TARGET=jack_rabbit

.SUFFIXES:
.PHONY: all check clean doc release

QFLAGS="CONFIG+=debug"

all:
	$(MAKE) -C tests
	$(MAKE) -C examples

check: all
	$(MAKE) -C tests check
	$(MAKE) -C examples check

clean:
	$(MAKE) -C tests clean
	$(MAKE) -C examples clean clean_images
	rm -rf doc

doc: check
	$(MAKE) -C examples doc
	doxygen $(TARGET).doxygen

publish: doc
	rm -rf ~/public_html/jack_rabbit_doc
	cp -r doc/html ~/public_html/jack_rabbit_doc

release:
	$(MAKE) QFLAGS=\"CONFIG+=release\"
