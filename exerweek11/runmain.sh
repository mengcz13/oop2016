usage()
{
	echo "./runmain.sh <directory of source code of protobuf>"
}
DIR=$1
FIND_REGEX='.*\.(h|cpp|cc)'
FILES=`find "$DIR" ./protobufsrc -type f -regextype posix-egrep -iregex "$FIND_REGEX"`
./main pattern.txt $FILES result.txt
