# Makefile to build LCC
# This is the LCC from ioquake3
# LCC is in etc/

# Dean Netherton 2025

FADE:="\033[2m"
NORMAL:="\033[0m"

.PHONY: default
default: all
	@echo > /dev/null

.PHONY: all
all: lcc
	@echo $(FADE)lcc: Compiled$(NORMAL)
lcc:
	@$(MAKE) -C cpp
	@$(MAKE) -C rcc
	@$(MAKE) -C etc

clean:
	@$(MAKE) -C cpp clean
	@$(MAKE) -C rcc clean
	@$(MAKE) -C etc clean

.FORCE:

.PHONY: all lcc .FORCE


