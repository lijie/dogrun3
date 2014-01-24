all:
	mkdir -p ../../obj/protobuf
	if [ ! -e Makefile ]; then \
	  sh ./configure --prefix=`pwd`/../../obj/protobuf; \
	fi
	make; make install
