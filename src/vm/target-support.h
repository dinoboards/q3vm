#ifndef __TARGET_SUPPORT
#define __TARGET_SUPPORT

/* The target environment has 24 bit for standard int type
 *
 * To support typical PC environment of 32 bit, a type and associated conversion functions are needed
 *
 * On the target environment these can be 'nop-op' #defines
 *
 **/

#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
  uint8_t byt[3];
} uint24_t;

typedef struct {
  uint8_t byt[3];
} int24_t;

typedef int32_t  stdint_t;  /* can be a 32 or 24 bit number - depending on target CPU */
typedef uint32_t ustdint_t; /* can be a 32 or 24 bit number - depending on target CPU */

typedef uint32_t vm_size_t; /* type to represent size of a vm image (32bits or 24 bits) */

#define vm_sizeof(x) ((vm_size_t)(sizeof(x)))

extern ustdint_t to_ustdint(const uint24_t x);
extern stdint_t  to_stdint(int24_t x);

extern uint24_t to_uint24(const ustdint_t x);
extern int24_t  to_int24(ustdint_t x);

#define UINT   to_ustdint
#define INT    to_stdint
#define UINT24 to_uint24
#define INT24  to_int24

#endif
