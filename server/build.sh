#!/bin/sh

export GOPATH=`pwd`

go install dogrun2d
go install code.google.com/p/goprotobuf/protoc-gen-go
go install code.google.com/p/goprotobuf/proto
