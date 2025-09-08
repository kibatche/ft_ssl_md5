#!/bin/bash
make re
echo 'echo "42 is nice" | ./ft_ssl md5';echo "42 is nice" | ./ft_ssl md5
echo
echo '"42 is nice" | ./ft_ssl sha256';echo "42 is nice" | ./ft_ssl sha256
echo
echo 'echo "42 is nice" | ./ft_ssl md5 -p';echo "42 is nice" | ./ft_ssl md5 -p
echo
echo './ft_ssl sha256 -p';echo "42 is nice" | ./ft_ssl sha256 -p
echo

echo 'echo "Pity the living." | ./ft_ssl md5 -q -r';echo "Pity the living." | ./ft_ssl md5 -q -r
echo
echo './ft_ssl sha256 -q -r';echo "Pity the living." | ./ft_ssl sha256 -q -r
echo

echo "And above all," > file

echo './ft_ssl md5 file';./ft_ssl md5 file
echo
echo './ft_ssl sha256 file';./ft_ssl sha256 file
echo

echo './ft_ssl md5 -r file';./ft_ssl md5 -r file
echo
echo './ft_ssl sha256 -r file';./ft_ssl sha256 -r file
echo

echo './ft_ssl md5 -s "pity those that aren t following baerista on spotify."';
./ft_ssl md5 -s "pity those that aren't following baerista on spotify."
echo
echo './ft_ssl md5 -s "pity those that aren t following baerista on spotify."';
./ft_ssl sha256 -s "pity those that aren't following baerista on spotify."
echo

echo 'echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file';echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file
echo
echo 'echo "be sure to handle edge cases carefully" | ./ft_ssl sha256 -p file';echo "be sure to handle edge cases carefully" | ./ft_ssl sha256 -p file
echo

echo 'echo "some of this will not make sense at first" | ./ft_ssl md5 file';echo "some of this will not make sense at first" | ./ft_ssl md5 file
echo
echo 'echo "some of this will not make sense at first" | ./ft_ssl sha256 file';echo "some of this will not make sense at first" | ./ft_ssl sha256 file
echo

echo 'echo "but eventually you will understand" | ./ft_ssl md5 -p -r file';echo "but eventually you will understand" | ./ft_ssl md5 -p -r file
echo
echo 'echo "but eventually you will understand" | ./ft_ssl sha256 -p -r file';echo "but eventually you will understand" | ./ft_ssl sha256 -p -r file
echo

echo 'echo "GL HF let s go" | ./ft_ssl md5 -p -s "foo" file';echo "GL HF let's go" | ./ft_ssl md5 -p -s "foo" file
echo
echo 'echo "GL HF let s go" | ./ft_ssl sha256 -p -s "foo" file';echo "GL HF let's go" | ./ft_ssl sha256 -p -s "foo" file
echo

echo 'echo "one more thing" | ./ft_ssl md5 -r -p -s "foo" file -s "bar"';echo "one more thing" | ./ft_ssl md5 -r -p -s "foo" file -s "bar"
echo
echo 'echo "one more thing" | ./ft_ssl sha256 -r -p -s "foo" file -s "bar"';echo "one more thing" | ./ft_ssl sha256 -r -p -s "foo" file -s "bar"
echo

echo 'echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file';echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file
echo

echo 'echo "just to be extra clear" | ./ft_ssl sha256 -r -q -p -s "foo" file';echo "just to be extra clear" | ./ft_ssl sha256 -r -q -p -s "foo" file
echo

i=1
ERROR=0
echo -e "\ntesting md5 with random datas"
while [ $i -lt 1000 ];do
    to_hash=$(openssl rand -base64 $i)
    openssl_res=$(echo -n $to_hash | openssl md5)
    ft_ssl_res=$(echo -n $to_hash | ./ft_ssl md5)
    if [ "$ft_ssl_res" != "$openssl_res" ];then
        echo "ERROR with : $to_hash"
        exit
    fi
    i=$((i+1))
done

if [ $ERROR -eq 0 ];then
    echo "All tests passed successfully for md5"
fi
i=1
echo -e "\ntesting sha256 with random datas"
while [ $i -lt 1000 ];do
    to_hash=$(openssl rand -base64 $i)
    openssl_res=$(echo -n $to_hash | openssl sha256)
    ft_ssl_res=$(echo -n $to_hash | ./ft_ssl sha256)
    if [ "$ft_ssl_res" != "$openssl_res" ];then
        echo "ERROR with : $to_hash"
        exit
    fi
    i=$((i+1))
done

if [ $ERROR -eq 0 ];then
    echo "All tests passed successfully for sha256"
fi
