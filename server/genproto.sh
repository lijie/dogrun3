#!/bin/sh

export PATH=`pwd`/bin/:$PATH
make -C ../protocol -f server.mk
