#!/bin/bash

# Check if the script is run as root or with sudo
if [ "$EUID" -ne 0 ]; then
  echo "Please run this script as root or with sudo."
  exit 1
fi

set -e

rm -rf /opt/ez80-q3vm
mkdir -p /opt/ez80-q3vm/bin
mkdir -p /opt/ez80-q3vm/includes
cp -r bin/linux/lcc /opt/ez80-q3vm/bin/
cp -r bin/linux/q3asm /opt/ez80-q3vm/bin/
cp -r bin/linux/q3cpp /opt/ez80-q3vm/bin/
cp -r bin/linux/q3rcc /opt/ez80-q3vm/bin/
cp -r src/vm/vm.c /opt/ez80-q3vm/includes/
cp -r src/vm/vm.h /opt/ez80-q3vm/includes/
cp -r src/vm/opcodes.c.h /opt/ez80-q3vm/includes/
cp -r src/vm/opcodes.h /opt/ez80-q3vm/includes/
cp -r ./verification/verifications-byte-code.c /opt/ez80-q3vm/includes/
cp -r ./verification/verifications-byte-code.h /opt/ez80-q3vm/includes/


#move file ${EZ80_CLANG_DIR}/ez80-clang to SUDO_USER/.ez80-clang

USER_HOME=$(eval echo "~$SUDO_USER")
ENV_FILE="${USER_HOME}/.ez80-q3vm"

cp ez80-q3vm-env $ENV_FILE
chown "$SUDO_USER:$SUDO_USER" "$ENV_FILE"
chmod 644 "$ENV_FILE"

echo "Environment variables defined in: $ENV_FILE"
echo "Tools installed into: /opt/ez80-q3vm"

# Ensure ~/ez80-clang-aliases is sourced in the appropriate shell configuration files
ensure_aliases_sourced() {
    local file=$1
    if ! grep -q "source ${ENV_FILE}" "$file"; then
        echo -e "\nsource ${ENV_FILE}" >> "$file"
        echo "Added source ${ENV_FILE} to $file"
    fi
}

# Determine the OS and ensure ~/ez80-clang-aliases is sourced in the appropriate file
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    if [ -n "$ZSH_VERSION" ]; then
        ensure_aliases_sourced "$USER_HOME/.zshrc"
    else
        ensure_aliases_sourced "$USER_HOME/.bashrc"
    fi
elif [[ "$OSTYPE" == "darwin"* ]]; then
    ensure_aliases_sourced "$USER_HOME/.bash_profile"
    ensure_aliases_sourced "$USER_HOME/.zshrc"
else
    echo "Unsupported OS: $OSTYPE"
    exit 1
fi
