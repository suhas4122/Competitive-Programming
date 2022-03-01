# open a file, replace " with \" and write to another file
a="tmp.txt"
sed 's/"/\\"/g' $1 > $a
cat $a > $1
# add double quotes to the beginning and end of the line and write to another file
sed 's/^/"/' $1 > $a
cat $a > $1
# add a comma to the end of the line and write to another file
sed 's/$/",/' $1 > $a
cat $a > $1