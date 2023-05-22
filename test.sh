#!/usr/bin/env bash
MAX=10
if [[ $1 =~ ^[0-9]+$ ]]; 
then
   MAX=$1
fi

echo "testando $MAX vezes..."
ERRO=0

for _ in $(seq "$MAX")
do  
  if ! ./a.out > /dev/null
  then
    ((ERRO+=1))
    echo "erro..."
  fi
done

if [ $ERRO -gt 0 ]
then
  echo "$ERRO erros!"
else 
  echo "ok"
fi
