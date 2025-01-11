/* Include guard */
#if !defined(BASE_H)
#define BASE_H

/* Includes */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

/* Consts */
/* Pi */
#define PI              3.141592653589793238462643383279
/* 2 * Pi */
#define TAU             6.283185307179586476925286766559
/* Euler's number */
#define E               2.718281828459045235360287471352

/* Macros */
/* Convert from degress to radians */
#define RADIANS(x)      ((x) * (PI / 180.0))
/* Convert from radians to degrees */
#define DEGREES(x)      ((x) * (180.0 / PI))
/* Get the maximum of two number */
#define MAX(a, b)       ((a) > (b) ? (a) : (b))
/* Get the minimum of two number */
#define MIN(a, b)       ((a) < (b) ? (a) : (b))
/* Get the absolute value of a number */
#define ABS(x)          ((x) < 0 ? -(x) : (x))
/* Clamp a number between a range */
#define CLAMP(x, a, b)  (MAX(MIN(x, b), a))
/* Perform linear interpolation */
#define LERP(a, b, t)   ((a) + ((b) - (a)) * (t))
/* Get the length of an array */
#define ARRLEN(a)       (sizeof(a) / sizeof(a[0]))

/* Types */
/* - Unsigned integers */
/* 8-bit unsigned integer */
typedef uint8_t     u8;
/* 16-bit unsigned integer */
typedef uint16_t    u16;
/* 32-bit unsigned integer */
typedef uint32_t    u32;
/* 64-bit unsigned integer */
typedef uint64_t    u64;
/* - Signed integers */
/* 8-bit signed integer */
typedef int8_t      i8;
/* 16-bit signed integer */
typedef int16_t     i16;
/* 32-bit signed integer */
typedef int32_t     i32;
/* 64-bit signed integer */
typedef int64_t     i64;
/* - Floats */
/* 32-bit float */
typedef float       f32;
/* 64-bit float */
typedef double      f64;
/* - Check sizes */
#define _SIZE_CHECK(t, s)\
  _Static_assert(sizeof(t) == s, "failed size check for " #t)
_SIZE_CHECK(u8, 1);
_SIZE_CHECK(u16, 2);
_SIZE_CHECK(u32, 4);
_SIZE_CHECK(u64, 8);
_SIZE_CHECK(i8, 1);
_SIZE_CHECK(i16, 2);
_SIZE_CHECK(i32, 4);
_SIZE_CHECK(i64, 8);
_SIZE_CHECK(f32, 4);
_SIZE_CHECK(f64, 8);

#endif /* BASE_H */
