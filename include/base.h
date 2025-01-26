/* Include guard */
#if !defined(BASE_H)
#define BASE_H

/* Types */
/* Unsigned integers */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
/* Signed integers */
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long i64;
/* Floats */
typedef float f32;
typedef double f64;
/* Booleans */
#undef bool
typedef u8 bool;

/* Size checks for types */
#define SIZE_CHECK(t, s) _Static_assert(\
    sizeof(t) == s,\
    "Size check failed for type " #t " with size " #s\
)
SIZE_CHECK(u8, 1);
SIZE_CHECK(u16, 2);
SIZE_CHECK(u32, 4);
SIZE_CHECK(u64, 8);
SIZE_CHECK(i8, 1);
SIZE_CHECK(i16, 2);
SIZE_CHECK(i32, 4);
SIZE_CHECK(i64, 8);
SIZE_CHECK(f32, 4);
SIZE_CHECK(f64, 8);
#undef SIZE_CHECK

/* Consts */
#define FALSE 0
#define TRUE 1
#if !defined(NULL)
#define NULL ((void*)0)
#endif
#define MAX_U8 255
#define MAX_U16 65535
#define MAX_U32 4294967295
#define MAX_U64 18446744073709551615u
#define MIN_I8 -128
#define MIN_I16 -32768
#define MIN_I32 -2147483648
#define MIN_I64 -9223372036854775808
#define MAX_I8 127
#define MAX_I16 32767
#define MAX_I32 2147483647
#define MAX_I64 9223372036854775807
#define PI 3.141592653589793238
#define E 2.718281828459045235

/* Macros */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX3(a, b, c) MAX(MAX(a, b), c)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MIN3(a, b, c) MIN(MIN(a, b), c)
#define CLAMP(x, min, max) MAX(MIN(x, max), min)
#define LERP(a, b, t) ((a) + ((b) - (a)) * (t))
#define SWAP(a, b) { __typeof__(a) temp = a; a = b; b = temp; }
#define ABS(x) (((x) < 0) ? -(x) : (x))
#define ARRLEN(arr) (sizeof(arr) / sizeof(arr[0]))
#define DEGREES(radians) (radians*(180/PI))
#define RADIANS(degrees) (degrees*(PI/180))

/* Functions */
extern void *memset(void *s, int c, u64 n);
extern void *memcpy(void *dest, const void *src, u64 n);
extern int memcmp(const void *s1, const void *s2, u64 n);
extern void *malloc(u64 size);
extern void *realloc(void *ptr, u64 size);
extern void free(void *ptr);
extern void abort(void);
extern f32 sqrtf(f32 x);
extern f32 powf(f32 x, f32 y);
extern f32 sinf(f32 x);
extern f32 cosf(f32 x);
extern f32 tanf(f32 x);
extern f32 asinf(f32 x);
extern f32 acosf(f32 x);
extern f32 atanf(f32 x);
extern f32 expf(f32 x);
extern f32 logf(f32 x);
extern f32 log10f(f32 x);

#endif /* BASE_H */
