/* Include guard */
#if !defined(LA_H)
#define LA_H

/* Includes */
#include <base.h>
#include <logging.h>

/* Types */
/* 2D vector */
typedef struct { f32 x, y; } vec2_t;
/* 2D integer vector */
typedef struct { i32 x, y; } vec2i_t;
/* 3D vector */
typedef struct { f32 x, y, z; } vec3_t;
/* 3D integer vector */
typedef struct { i32 x, y, z; } vec3i_t;
/* 4D vector */
typedef struct { f32 x, y, z, w; } vec4_t;
/* 4D integer vector */
typedef struct { i32 x, y, z, w; } vec4i_t;
/* 2x2 matrix */
/*
 * 0 2
 * 1 3
 */
typedef struct { f32 m[4]; } mat2_t;
/* 3x3 matrix */
/*
 * 0 3 6
 * 1 4 7
 * 2 5 8
 */
typedef struct { f32 m[9]; } mat3_t;
/* 4x4 matrix */
/*
 * 0 4 8 12
 * 1 5 9 13
 * 2 6 10 14
 * 3 7 11 15
 */
typedef struct { f32 m[16]; } mat4_t;

/* Macros */
/* Dot product of two 2d vectors */
#define V2_DOT(v1, v2) ((v1).x * (v2).x + (v1).y * (v2).y)
/* Dot product of two 3d vectors */
#define V3_DOT(v1, v2) ((v1).x * (v2).x + (v1).y * (v2).y + (v1).z * (v2).z)
/* Dot product of two 4d vectors */
#define V4_DOT(v1, v2) ((v1).x * (v2).x + (v1).y * (v2).y + (v1).z * (v2).z\
    + (v1).w * (v2).w)
/* Cross product of two 3d vectors */
#define V3_CROSS(v1, v2) (vec3_t){\
    (v1).y * (v2).z - (v1).z * (v2).y,\
    (v1).z * (v2).x - (v1).x * (v2).z,\
    (v1).x * (v2).y - (v1).y * (v2).x\
}
/* Length of a 2d vector */
#define V2_LENGTH(v) sqrtf(V2_DOT(v, v))
/* Length of a 3d vector */
#define V3_LENGTH(v) sqrtf(V3_DOT(v, v))
/* Length of a 4d vector */
#define V4_LENGTH(v) sqrtf(V4_DOT(v, v))
/* Scale a 2d vector */
#define V2_SCALE(v, s) (vec2_t){(v).x * (s), (v).y * (s)}
/* Scale a 3d vector */
#define V3_SCALE(v, s) (vec3_t){(v).x * (s), (v).y * (s), (v).z * (s)}
/* Scale a 4d vector */
#define V4_SCALE(v, s) (vec4_t){(v).x * (s), (v).y * (s), (v).z * (s),\
    (v).w * (s)}
/* Normalize a 2d vector */
#define V2_NORMALIZE(v) V2_SCALE(v, 1.0f / V2_LENGTH(v))
/* Normalize a 3d vector */
#define V3_NORMALIZE(v) V3_SCALE(v, 1.0f / V3_LENGTH(v))
/* Normalize a 4d vector */
#define V4_NORMALIZE(v) V4_SCALE(v, 1.0f / V4_LENGTH(v))
/* Lerp between two 2d vectors */
#define V2_LERP(v1, v2, t) (vec2_t){\
    (v1).x + ((v2).x - (v1).x) * (t),\
    (v1).y + ((v2).y - (v1).y) * (t)\
}
/* Lerp between two 3d vectors */
#define V3_LERP(v1, v2, t) (vec3_t){\
    (v1).x + ((v2).x - (v1).x) * (t),\
    (v1).y + ((v2).y - (v1).y) * (t),\
    (v1).z + ((v2).z - (v1).z) * (t)\
}
/* Lerp between two 4d vectors */
#define V4_LERP(v1, v2, t) (vec4_t){\
    (v1).x + ((v2).x - (v1).x) * (t),\
    (v1).y + ((v2).y - (v1).y) * (t),\
    (v1).z + ((v2).z - (v1).z) * (t),\
    (v1).w + ((v2).w - (v1).w) * (t)\
}
/* Add two 2d vectors */
#define V2_ADD(v1, v2) (vec2_t){\
    (v1).x + (v2).x,\
    (v1).y + (v2).y\
}
/* Add two 3d vectors */
#define V3_ADD(v1, v2) (vec3_t){\
    (v1).x + (v2).x,\
    (v1).y + (v2).y,\
    (v1).z + (v2).z\
}
/* Add two 4d vectors */
#define V4_ADD(v1, v2) (vec4_t){\
    (v1).x + (v2).x,\
    (v1).y + (v2).y,\
    (v1).z + (v2).z,\
    (v1).w + (v2).w\
}
/* Subtract two 2d vectors */
#define V2_SUB(v1, v2) (V2_ADD(v1, V2_SCALE(v2, -1.0f)))
/* Subtract two 3d vectors */
#define V3_SUB(v1, v2) (V3_ADD(v1, V3_SCALE(v2, -1.0f)))
/* Subtract two 4d vectors */
#define V4_SUB(v1, v2) (V4_ADD(v1, V4_SCALE(v2, -1.0f)))

/* Create a 2d identity matrix */
extern void m2_identity(mat2_t *res);
/* Create a 3d identity matrix */
extern void m3_identity(mat3_t *res);
/* Create a 4d identity matrix */
extern void m4_identity(mat4_t *res);

/* Create a 2d translation matrix */
extern void m2_translation(mat2_t *res, vec2_t v);
/* Create a 3d translation matrix */
extern void m3_translation(mat3_t *res, vec3_t v);
/* Create a 4d translation matrix (3d, but in a 4d matrix) */
extern void m4_translation(mat4_t *res, vec4_t v);

/* Create a 2d scale matrix */
extern void m2_scale(mat2_t *res, vec2_t v);
/* Create a 3d scale matrix */
extern void m3_scale(mat3_t *res, vec3_t v);
/* Create a 4d scale matrix */
extern void m4_scale(mat4_t *res, vec4_t v);

/* Create a 2d rotation matrix */
extern void m2_rotation(mat2_t *res, f32 angle);
/* Create a 3d rotation matrix about the x axis */
extern void m3_rotation_x(mat3_t *res, f32 angle);
/* Create a 3d rotation matrix about the y axis */
extern void m3_rotation_y(mat3_t *res, f32 angle);
/* Create a 3d rotation matrix about the z axis */
extern void m3_rotation_z(mat3_t *res, f32 angle);
/* Create a 3d rotation matrix using euler angles */
extern void m3_rotation(mat3_t *res, vec3_t angles);
/* Create a 4d rotation matrix about the x axis (3d, but in 3d matrix) */
extern void m4_rotation_x(mat4_t *res, f32 angle);
/* Create a 4d rotation matrix about the y axis (3d, but in 3d matrix) */
extern void m4_rotation_y(mat4_t *res, f32 angle);
/* Create a 4d rotation matrix about the z axis (3d, but in 3d matrix) */
extern void m4_rotation_z(mat4_t *res, f32 angle);
/* Create a 4d rotation matrix using euler angles (3d, but in 3d matrix) */
extern void m4_rotation(mat4_t *res, vec3_t angles);

/* Create a 4d perspective matrix (returns false on failure) */
extern bool m4_perspective(mat4_t *res, f32 fov, f32 aspect, f32 near, f32 far);
/* Create a 4d look at matrix */
extern void m4_look_at(mat4_t *res, vec3_t eye, vec3_t center, vec3_t up);

/* Get the determinant of a 2d matrix or 0 */
extern f32 m2_determinant(mat2_t m);
/* Get the determinant of a 3d matrix or 0 */
extern f32 m3_determinant(mat3_t m);
/* Get the determinant of a 4d matrix or 0 */
extern f32 m4_determinant(mat4_t m);

/* Invert a 2d matrix returns whether or not their is an inverse */
extern bool m2_invert(mat2_t *res, mat2_t m);
/* Invert a 3d matrix returns whether or not their is an inverse */
extern bool m3_invert(mat3_t *res, mat3_t m);
/* Invert a 4d matrix returns whether or not their is an inverse */
extern bool m4_invert(mat4_t *res, mat4_t m);

/* Transpose a 2d matrix */
extern void m2_transpose(mat2_t *res, mat2_t m);
/* Transpose a 3d matrix */
extern void m3_transpose(mat3_t *res, mat3_t m);
/* Transpose a 4d matrix */
extern void m4_transpose(mat4_t *res, mat4_t m);

/* Multiply two 2d matrices */
extern void m2_mul(mat2_t *res, mat2_t m1, mat2_t m2);
/* Multiply two 3d matrices */
extern void m3_mul(mat3_t *res, mat3_t m1, mat3_t m2);
/* Multiply two 4d matrices */
extern void m4_mul(mat4_t *res, mat4_t m1, mat4_t m2);

/* Multiply a 2d matrix with a 2d vector */
extern void m2v2_mul(vec2_t *res, mat2_t m, vec2_t v);
/* Multiply a 3d matrix with a 3d vector */
extern void m3v3_mul(vec3_t *res, mat3_t m, vec3_t v);
/* Multiply a 4d matrix with a 4d vector */
extern void m4v4_mul(vec4_t *res, mat4_t m, vec4_t v);

#endif /* LA_H */
