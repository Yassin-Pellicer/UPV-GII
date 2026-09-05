#!/bin/bash
# case.sh

echo "Estás seguro (s/n)? [n]"
read resp

case ${resp} in
   [sS]) echo "En fin, tú lo has querido..." ;;
    n|N) echo "Estupendo, menos trabajo!";;
      *) echo "Voy a considerar eso como un no!";;
esac
