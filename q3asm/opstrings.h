/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

// clang-format off

    // {"BREAK", OP_BREAK},
    //{ "ARGB", OP_ARG },
    // {"CVFF4", OP_UNDEF},
    // {"CVPU4", OP_IGNORE},
    // {"CVUP4", OP_IGNORE},

    //{ "CALLB", OP_UNDEF },

    // {"ADDP4", OP_ADD4},
    // {"ADDP", OP_ADD4},
    // {"SUBP4", OP_SUB},


    {"LEF4", OP_LEF},
    {"LEI4", OP_LEI},
    {"LEU4", OP_LEU},

    {"LTF4", OP_LTF},
    {"LTI4", OP_LTI},
    {"LTU4", OP_LTU},

    {"NEF4", OP_NEF},
    {"NEI4", OP_NE},
    {"NEU4", OP_NE},

    {"JUMPV", OP_JUMP},

    {"LOADB4", OP_UNDEF},
    {"LOADF4", OP_UNDEF},
    {"LOADI4", OP_UNDEF},
    {"LOADP4", OP_UNDEF},
    {"LOADU4", OP_UNDEF},

    {"ADDI3", OP_ADD4},
    {"ADDU3", OP_ADD4},
    {"ASGNI3", OP_STORE3},
    {"ASGNU3", OP_STORE3},
    {"BANDI3", OP_BAND4},
    {"BANDU3", OP_BAND4},
    {"BCOMU3", OP_BCOM4},
    {"BCOMU3", OP_BCOM4},
    {"BORI3", OP_BOR4},
    {"BXORI3", OP_BXOR4},
    {"BXORU3", OP_BXOR4},
    {"CNSTI3", OP_CONSTI3},
    {"CVFI3", OP_CF4I4},
    {"CVIU3", OP_IGNORE},
    {"CVUI3", OP_IGNORE},
    {"DIVI3", OP_DIVI},
    {"DIVU3", OP_DIVU},
    {"EQI3", OP_EQ},
    {"GEI3", OP_GEI},
    {"GEU3",  OP_GEU},
    {"GTI3", OP_GTI},
    {"GTU3", OP_GTU},
    {"INDIRI3", OP_LOAD3},
    {"INDIRU3", OP_LOAD3},
    {"LEI3", OP_LEI},
    {"LEU3", OP_LEU},
    {"LSHI3", OP_LSH},
    {"LSHU3", OP_LSH},
    {"LSHU3", OP_LSH},
    {"LTI3", OP_LTI},
    {"LTU3",   OP_LTU},
    {"MODI3", OP_MODI},
    {"MODU3", OP_MODU},
    {"MULI3", OP_MULI},
    {"MULU3",  OP_MULU},
    {"NEGI3", OP_NEGI},
    {"NEI3", OP_NE},
    {"RSHI3", OP_RSHI},
    {"RSHU3", OP_RSHU},
    {"SUBI3", OP_SUB},
    {"SUBU3", OP_SUB},
    {"INDIRP3", OP_LOAD3},
    {"ASGNP3", OP_STORE3},
    {"ADDP3", OP_ADD3},
    // {"ADDRGP3", OP_CONSTGP3},
    {"CVPU3", OP_IGNORE},
    {"CVUP3", OP_IGNORE},
    {"NEU3", OP_NE},
    // {"CNSTP3", OP_CONSTP3},
    {"SUBP3", OP_SUB},
    {"CVUU3", OP_IGNORE},

    // clang-format on
