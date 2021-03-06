#!/bin/bash
sed -n '/gvsu/p' input.txt
sed -n '1p' input.txt
gawk '/gvsu/ {printf "%s\n", $2}' input.txt

cp input.txt input2.txt
sed -i '/^$/d' input2.txt
sed -i '/Linux/d' input2.txt

sed -i 's/cis/CIS/g' input2.txt
echo "Enter a string to be replaced:"
read string1
if grep -q "$string1" input2.txt
then
    echo "Enter the new string:"
    read string2
    sed -i "s/$string1/$string2/g" input2.txt
else
    echo "The string does not exist"
    exit 1
fi
