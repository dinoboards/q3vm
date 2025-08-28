"Not Q3VM" Readme
=================

"Not Q3VM" is a fork of q3vm from https://github.com/jnz/q3vm by Jan Zwiener.

"Not Q3VM" is a Compiler(lcc) and Virtual Machine implementation customised for the [eZ80 CPU platform](https://github.com/dinoboards/ez80-for-rc).

At this stage, this is still an experiment to see how effective the use of a VM within the firmware of the eZ80 will be.

> Q3VM is a lightweight embeddable interpreter/Virtual Machine (VM) for compiled bytecode files `.qvm` based on good old C-language input `.c`. A complete C compiler to generate `.qvm` files is included (LCC). The interpreter is based on the Quake III Arena virtual machine (hence the name q3vm) but the interpreter is not tied to Quake III Arena.

Read the excellent introduction to the Q3VM by Fabien Sanglard:

 * http://fabiensanglard.net/quake3/qvm.php

## Bytecode generation proces:

1. Use `lcc` to compile C89 `.c` code files to IL text representation `.vmasm` files.
2. Use `q3asm` to translate and link a set of `.vmasm` files to a binary bytecode `.qvm` file.
3. Embed `vm.c` and `vm.h` into a host C application to interpret/execute the bytecode.

## Main changes from Jan Zwiener's q3vm

1. LCC C Compiler's default `int` type changed from 32 bits to 24 bits wide; aligning with eZ80's CPU 24 bit registers.
2. New/changed opcodes within the VM -- bytecodes are not compatible.
3. Optimisation of `vm.c` and `vm.h` for Zilog's ZDS eZ80 compiler.
4. 4 byte alignment removed and all code and data defaults to a single byte alignment.
5. 8 bit, 16 bit and 24 bits values no longer padded to 32 bits.
6. c pointer widths is 24 bits.
7. Adjusted bytecode memory mapping to place read only data first - avoiding need to copy full image to RAM.
8. Refinements to the trace output when `DEBUG_VM` is defined.
9. New conditional compile define `MEMORY_SAFE` to include memory access checks.
10. Removed "computed gotos" version as its not supported by Zilog's C89 compiler.
11. Memory allocation process changed from a requested process to a tell process. (Removed VM_alloc callback functions).
12. New command line option `q3asm -l` to produce a listing file.

## Memory Mapping changes

The upstream version of the Q3VM, applied a memory mapping model that copies all the bytecode image to RAM, including code and read only data (LIT Segment).

For the eZ80 this is an issue for embedding the Q3VM within the on-chips's ROM.  The CPU on-chip RAM is only 8K.

The LCC/Q3ASM places the code is in its own address space, separate to all data requests.  This means the q3vm interpreter starts retrieving code from virtual address 0x000000; and when that interpreted code attempts to read or write data - the addressing for data also starts from 0x000000.

Updating the Q3VM implementation to avoid copying the code segment to RAM is straightforward, but enabling the readonly data to stay within the ROM image, is a little more complicated.  The Q3VM implementation now test the address for all data access and redirect readonly (LIT) data to the host's ROM image.  All other data, including BSS and stack accessing are directed to the appropriate host RAM address.

## IL/VM Specification

* [docs/q3vm-spec.md](docs/q3vm-spec.md) for detail list of all LCC IL instructions.
* [docs/vm-spec.md](docs/vm-spec.md) for detail list of "Not Q3VM" opcodes.


## Porting Progress:

#### Identified Issues:

1. DONE. Converting vm.c to run on ZDS/ez80-clang requires adjusting all assumption that int is a 32 bit number
2. DONE. Avoid need to 'translate' CODE binary image into large RAM int arrays - run direct from ROM
3. DONE. Have the CODE and DATA sections stored in RAM - DATA and BSS copied to on-chip RAM
4. Support running as CP/M application.
5. DONE. All bytecode operands are 32 bits (for ints/bytes and floats) - be nice to convert this to 24 bits for int/bytes -support both 32 and 24 bit operands
6. NOT DO: ~~Maybe drop support for floats?~~
7. DONE: Change operand for CALL to just 24bit (no need to support large bytecode images)
8. DONE: Probably want to support the ZDS compiler (not ez80-clang) to enable it to be embedded in ROM
9. DONE: computed gotos not supported in ZDS - and in ez80-clang produces poorer code than a switch statement - REMOVED implementation of computed gotos.
10. Can lcc and q3asm be compiled by lcc, enabling compiling of bytecode on the ez80?
11. Compiling vm.c under lcc would be very weird!

#### TODOs

1. NOT DO: ~~change opstack from using fixed 4 byte wide values to variable values (1 byte for int, 3 for int24 etc)~~Minimal potential gain & increase code complexity
2. DONE: complete migration of assembly lookup from opstrings.h to assembly.h
3. DONE: complete refactor of all vm case statements to use pop/push pattern
4. NOT DO: ~~change programCounter and programStack to be pointers not array indexes~~ - is less efficient in ZDS
5. extend vm interface to include error callback function - maybe
6. DONE: optimise use of r0.. and r1.. variables - avoid need of many local vars
7. move VM_ArgPtr, VM_IntToFloat and VM_FloatToInt out of vm.c
8. DONE: optimise VM_CallInterpreted - splat out vm_t, optmise locals, ptrs
9. DONE: remove instructionCount - not needed now
10. removed ignored verification tests
11. add other verification tests


Original List of Features
--------

 * Small and lightweight (one .c file to include without dependencies)
 * Battle-tested (20 years of use in Quake III Arena)
 * VM and LCC forked from the well maintained ioquake3 code base
 * Tool tested (static code analysis, test coverage, Valgrind)
 * No need to learn a new scripting language (e.g. Lua)
 * Static type checking in the language (C)
 * Static memory allocation in C, no unpredictable garbage collector
 * Plan B: you can always go back to native code, as .c files are the input
 * Great tool landscape for C. Use the tools that are available for C

Original (upstream) Use Cases
---------

 * Sandbox for code you don't fully trust (e.g. download the bytecode from a web server)
 * Mods for hobby game engines
 * There are many virtual machines, but not many are so small, with static typing and no garbage collector
 * Learn about virtual machines in general, but directly have a C compiler available for the virtual machine
 * Sandbox for embedded applications, e.g. plug-ins for IoT applications on microcontrollers (bounded CPU time, bounded memory area, restrict access to peripheral devices)
 * There is also a historical value: learn about the Quake III engine



Folder structure
----------------

    ├─ bin/             LCC compiler and q3asm linker output binaries
    │  ├─ linux/        Linux target folder for LCC compiler and q3asm linker
    ├─ build/           Temp. directory for object files
    ├─ doxygen/         Doxygen config and API documentation output
    ├─ example/         Example "hello world" firmware project (bytecode.qvm)
    ├─ lcc/             The LCC compiler (compile .c files to .asm files)
    ├─ q3asm/           Linker: link the LCC .asm files to a .qvm bytecode file
    ├─ src/             q3vm standalone console application source code
    │  └─ vm/           The core VM source, copy that folder into your project
    ├─ test/            Test environment
    └─ verification     C compiler tests derived from https://github.com/nlsandler/writing-a-c-compiler-tests


Build VM/interpreter
--------------------

On **Linux**:

    > make clean            # remove all build artifacts
    > make test             # build and execute the q3vm tests
    > make verification     # build and execute the verification tests
    > make example          # build and run the example/g_main.c under the vm
    > make exportez80       # run the verifications tests and create `verifications-byte-code.c` for importing into ez80-for-rc project
    > sudo make install     # copies binaries and c/h files to /opt/ez80-q3vm/...


Original comments by John Carmack
---------------------------------

John Carmack's .plan for Nov 03, 1998:

*I had been working under the assumption that Java was the right way to go, but recently I reached a better conclusion.*

*The programming language for QuakeArena mods is interpreted ANSI C. (well, I am dropping the double data type, but otherwise it should be pretty conformant)*

*The game will have an interpreter for a virtual RISC-like CPU. This should have a minor speed benefit over a byte-coded, stack based java interpreter. Loads and stores are confined to a preset block of memory, and access to all external system facilities is done with system traps to the main game code, so it is completely secure.*

*The tools necessary for building mods will all be freely available: a modified version of LCC and a new program called q3asm. LCC is a wonderful project - a cross platform, cross compiling ANSI C compiler done in under 20K lines of code. Anyone interested in compilers should pick up a copy of "A retargetable C compiler: design and implementation" by Fraser and Hanson.*

*You can't link against any libraries, so every function must be resolved. Things like strcmp, memcpy, rand, etc. must all be implemented directly. I have code for all the ones I use, but some people may have to modify their coding styles or provide implementations for other functions.*

*It is a fair amount of work to restructure all the interfaces to not share pointers between the system and the games, but it is a whole lot easier than porting everything to a new language. The client game code is about 10k lines, and the server game code is about 20k lines.*

*The drawback is performance. It will probably perform somewhat like QC. Most of the heavy lifting is still done in the builtin functions for path tracing and world sampling, but you could still hurt yourself by looping over tons of objects every frame. Yes, this does mean more load on servers, but I am making some improvements in other parts that I hope will balance things to about the way Q2 was on previous generation hardware.*

*There is also the amusing avenue of writing hand tuned virtual assembly assembly language for critical functions.*

*I think this is The Right Thing.*


LICENSE
-------

See COPYING.txt for details on the license. Basically the Quake III Arena
GPL 2 source code license has been inherited.

Be aware that LCC has its own non-commercial license which is described in
lcc/COPYRIGHT.

Further information
-------------------

 * http://fabiensanglard.net/quake3/qvm.php
 * https://github.com/dinoboards/ez80-for-rc

Credits
=======

This project is based on the Quake 3 and ioquake3 source:

 * https://github.com/id-Software/Quake-III-Arena (id Software)
 * https://github.com/ioquake/ioq3
 * https://icculus.org/projects/triseism/triseism.html
 * https://github.com/jnz/q3vm
 * https://github.com/nlsandler/writing-a-c-compiler-tests
