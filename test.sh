#!/usr/bin/env bash

for _ in $(seq 10)
do
  
  if ! ./a.out > /dev/null
  then
    echo "erro..."
  fi

done
