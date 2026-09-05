#!/bin/bash
# expansion2.sh

passwd="root:x:0:0:root:/root:/bin/bash"

echo '$passwd             '   $passwd
echo '${passwd#*:}        '   ${passwd#*:} 
echo '${passwd##*:}       '   ${passwd##*:} 
echo '${passwd%:*}        '   ${passwd%:*} 
echo '${passwd%%:*}       '   ${passwd%%:*} 
echo '${passwd:5}         '   ${passwd:5} 
echo '${passwd:5:10}      '   ${passwd:5:10}
echo '${passwd/root/pepe} '   ${passwd/root/pepe} 
echo '${passwd//:/,}      '   ${passwd//:/,} 
echo '${passwd^r*}        '   ${passwd^r} 
echo '${passwd^^r*}       '   ${passwd^^r} 





