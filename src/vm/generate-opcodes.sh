#!/usr/bin/env bash

set -e

cat <<EOT > opcodes.h
#ifndef __OPCODES
#define __OPCODES

#include <stdint.h>

/** Enum for the virtual machine op codes */
typedef enum {
EOT

cat <<EOT > opcodes.c.h
#include "opcodes.h"

const char *const opnames[OPCODE_TABLE_SIZE] = {
EOT

count=0
while IFS= read -r line; do
  opcode_name="${line%% *}"
  name="${opcode_name:3}"
  description=$(echo "$line" | awk '{$1=""; print $0}')
  printf "${opcode_name}, /* %3s ${description} */\n" ${count} >> opcodes.h
  printf "\"${name}\", /* %3s ${description} */\n" ${count} >> opcodes.c.h
  count=$((count + 1))

done < opcodes.txt

cat <<EOT >> opcodes.h
OP_MAX, /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
EOT

echo  "};" >> opcodes.c.h

clang-format -i ./opcodes.h
clang-format -i ./opcodes.c.h
