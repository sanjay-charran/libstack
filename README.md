#	A Static Library For A Simple Stack in C
	The library serves to save some time when using this common datastructure rather than writing a new one. A point of note, is that altough there is no restriction on the data being of the same type across different nodes in terms of storage, you would likely have to jump through some hoops to actually make use of said data if of different types which would be pointless.
	I personally wrote this mostly for my personal use but if you would also like to feel free. I'll likely update it to improve as time goes but no gurantees on timing.
##	Compiling the Library
	The requirements for compiling this library is the C standard library (libc), version 2.36 of libc and C18 was used for testing.
	The library is compiled using GNU Make (v4.3) and specifies GCC, however, this can be changed to your own choice of compiler by editing the Makefile.
	The Makefile contains options for making the library (libstack.a) via either:
	`make` or `make all`
	There also exists options for removing non-source files and dirs:
	`make clean` for all obj and lib directories and files inside them
	`make clean_obj` for just obj dir and files inside
	`make clean_lib` for just lib dir and files inside
	
