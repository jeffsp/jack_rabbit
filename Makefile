# Jack Rabbit Makefile
#
# Copyright (C) 2008 Jeffrey S. Perry
#
# This program is free software: you can redistribute it
# and/or modify it under the terms of the GNU General
# Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public
# License along with this program.  If not, see
# <http://www.gnu.org/licenses/>.
#
# contact: jeffsp@gmail.com

TARGET=jack_rabbit

.SUFFIXES:
.PHONY: all check clean doc release

QFLAGS="CONFIG+=debug"

all:
	$(MAKE) -C tests
	$(MAKE) -C examples
	$(MAKE) -C apps

check: all
	$(MAKE) -C tests check
	$(MAKE) -C examples check
	$(MAKE) -C apps check

clean:
	$(MAKE) -C tests clean
	$(MAKE) -C examples clean clean_images
	$(MAKE) -C apps clean
	rm -rf doc

doc: check
	$(MAKE) -C examples doc
	doxygen $(TARGET).doxygen

publish: doc
	rm -rf ~/public_html/jack_rabbit_doc
	cp -r doc/html ~/public_html/jack_rabbit_doc

release:
	$(MAKE) QFLAGS=\"CONFIG+=release\"
