/* Implements la.h */
#include <la.h>

/* Create a 2d identity matrix */
void m2_identity(mat2_t *res) {
  memset(res, 0, sizeof(mat2_t));
  res->m[0] = 1.0f;
  res->m[3] = 1.0f;
}
/* Create a 3d identity matrix */
void m3_identity(mat3_t *res) {
  memset(res, 0, sizeof(mat3_t));
  res->m[0] = 1.0f;
  res->m[4] = 1.0f;
  res->m[8] = 1.0f;
}
/* Create a 4d identity matrix */
void m4_identity(mat4_t *res) {
  memset(res, 0, sizeof(mat4_t));
  res->m[0] = 1.0f;
  res->m[5] = 1.0f;
  res->m[10] = 1.0f;
  res->m[15] = 1.0f;
}

/* Create a 2d translation matrix */
void m2_translation(mat2_t *res, vec2_t v) {
  m2_identity(res);
  res->m[2] = v.x;
  res->m[3] = v.y;
}
/* Create a 3d translation matrix */
void m3_translation(mat3_t *res, vec3_t v) {
  m3_identity(res);
  res->m[6] = v.x;
  res->m[7] = v.y;
  res->m[8] = v.z;
}
/* Create a 4d translation matrix */
void m4_translation(mat4_t *res, vec4_t v) {
  m4_identity(res);
  res->m[12] = v.x;
  res->m[13] = v.y;
  res->m[14] = v.z;
  res->m[15] = v.w;
}

/* Create a 2d scale matrix */
void m2_scale(mat2_t *res, vec2_t v) {
  memset(res, 0, sizeof(mat2_t));
  res->m[0] = v.x;
  res->m[3] = v.y;
}
/* Create a 3d scale matrix */
void m3_scale(mat3_t *res, vec3_t v) {
  memset(res, 0, sizeof(mat3_t));
  res->m[0] = v.x;
  res->m[4] = v.y;
  res->m[8] = v.z;
}
/* Create a 4d scale matrix */
void m4_scale(mat4_t *res, vec4_t v) {
  memset(res, 0, sizeof(mat4_t));
  res->m[0] = v.x;
  res->m[5] = v.y;
  res->m[10] = v.z;
  res->m[15] = v.w;
}

/* Create a 2d rotation matrix */
void m2_rotation(mat2_t *res, f32 angle) {
  memset(res, 0, sizeof(mat2_t));
  f32 c = cosf(angle);
  f32 s = sinf(angle);
  res->m[0] = c;
  res->m[1] = s;
  res->m[2] = -s;
  res->m[3] = c;
}
/* Create a 3d rotation matrix about the x axis */
void m3_rotation_x(mat3_t *res, f32 angle) {
  memset(res, 0, sizeof(mat3_t));
  f32 c = cosf(angle);
  f32 s = sinf(angle);
  res->m[0] = 1.0f;
  res->m[4] = c;
  res->m[5] = s;
  res->m[7] = -s;
  res->m[8] = c;
}
/* Create a 3d rotation matrix about the y axis */
void m3_rotation_y(mat3_t *res, f32 angle) {
  memset(res, 0, sizeof(mat3_t));
  f32 c = cosf(angle);
  f32 s = sinf(angle);
  res->m[0] = c;
  res->m[2] = -s;
  res->m[4] = 1.0f;
  res->m[6] = s;
  res->m[8] = c;
}
/* Create a 3d rotation matrix about the z axis */
void m3_rotation_z(mat3_t *res, f32 angle) {
  memset(res, 0, sizeof(mat3_t));
  f32 c = cosf(angle);
  f32 s = sinf(angle);
  res->m[0] = c;
  res->m[1] = s;
  res->m[3] = -s;
  res->m[4] = c;
}
/* Create a 3d rotation matrix using euler angles */
void m3_rotation(mat3_t *res, vec3_t angles) {
  mat3_t m;
  m3_rotation_x(&m, angles.x);
  m3_mul(res, m, m);
  m3_rotation_y(&m, angles.y);
  m3_mul(res, *res, m);
  m3_rotation_z(&m, angles.z);
  m3_mul(res, *res, m);
}
/* Create a 4d rotation matrix about the x axis (3d, but in 3d matrix) */
void m4_rotation_x(mat4_t *res, f32 angle) {
  memset(res, 0, sizeof(mat4_t));
  f32 c = cosf(angle);
  f32 s = sinf(angle);
  res->m[0] = 1.0f;
  res->m[5] = c;
  res->m[6] = s;
  res->m[9] = -s;
  res->m[10] = c;
}
/* Create a 4d rotation matrix about the y axis (3d, but in 3d matrix) */
void m4_rotation_y(mat4_t *res, f32 angle) {
  memset(res, 0, sizeof(mat4_t));
  f32 c = cosf(angle);
  f32 s = sinf(angle);
  res->m[0] = c;
  res->m[2] = -s;
  res->m[5] = 1.0f;
  res->m[8] = s;
  res->m[10] = c;
}
/* Create a 4d rotation matrix about the z axis (3d, but in 3d matrix) */
void m4_rotation_z(mat4_t *res, f32 angle) {
  memset(res, 0, sizeof(mat4_t));
  f32 c = cosf(angle);
  f32 s = sinf(angle);
  res->m[0] = c;
  res->m[1] = s;
  res->m[4] = -s;
  res->m[5] = c;
}
/* Create a 4d rotation matrix using euler angles (3d, but in 3d matrix) */
void m4_rotation(mat4_t *res, vec3_t angles) {
  mat4_t m;
  m4_rotation_x(&m, angles.x);
  m4_mul(res, m, m);
  m4_rotation_y(&m, angles.y);
  m4_mul(res, *res, m);
  m4_rotation_z(&m, angles.z);
  m4_mul(res, *res, m);
}

/* Create a 4d perspective matrix (returns false on failure) */
bool m4_perspective(mat4_t *res, f32 fov, f32 aspect, f32 near, f32 far) {
  f32 s = sin(fov / 2.0f);
  f32 delta_z = far - near;
  if (delta_z == 0.0f || s == 0.0f || aspect == 0.0f)
    return false;
  f32 cot = cos(fov / 2.0f) / s;
  m4_identity(res);
  res->m[0] = cot / aspect;
  res->m[5] = cot;
  res->m[10] = (far + near) / delta_z;
  res->m[11] = -1.0f;
  res->m[14] = (2.0f * far * near) / delta_z;
  res->m[15] = 0.0f;
  return true;
}
/* Create a 4d look at matrix */
void m4_look_at(mat4_t *res, vec3_t eye, vec3_t center, vec3_t up) {
  vec3_t f, s, u;

  f = V3_SUB(center, eye);
  f = V3_NORMALIZE(f);

  s = V3_CROSS(f, up);
  s = V3_NORMALIZE(s);

  u = V3_CROSS(s, f);

  res->m[0] = s.x;
  res->m[1] = u.x;
  res->m[2] = -f.x;
  res->m[3] = 0.0f;

  res->m[4] = s.y;
  res->m[5] = u.y;
  res->m[6] = -f.y;
  res->m[7] = 0.0f;

  res->m[8] = s.z;
  res->m[9] = u.z;
  res->m[10] = -f.z;
  res->m[11] = 0.0f;

  res->m[12] = -V3_DOT(s, eye);
  res->m[13] = -V3_DOT(u, eye);
  res->m[14] = V3_DOT(f, eye);
  res->m[15] = 1.0f;
}

/* Get the determinant of a 2d matrix or 0 */
f32 m2_determinant(mat2_t m) {
  return m.m[0] * m.m[3] - m.m[1] * m.m[2];
}
/* Get the determinant of a 3d matrix or 0 */
f32 m3_determinant(mat3_t m) {
  return m.m[0] * m.m[4] * m.m[8]
    + m.m[1] * m.m[5] * m.m[6]
    + m.m[2] * m.m[3] * m.m[7]
    - m.m[2] * m.m[4] * m.m[6]
    - m.m[0] * m.m[5] * m.m[7]
    - m.m[1] * m.m[3] * m.m[8];
}
/* Get the determinant of a 4d matrix or 0 */
f32 m4_determinant(mat4_t m) {
  return m.m[0] * m.m[5] * m.m[10] * m.m[15]
    + m.m[1] * m.m[6] * m.m[11] * m.m[14]
    + m.m[2] * m.m[7] * m.m[9] * m.m[13]
    + m.m[3] * m.m[4] * m.m[8] * m.m[12]
    - m.m[3] * m.m[5] * m.m[10] * m.m[12]
    - m.m[1] * m.m[7] * m.m[8] * m.m[13]
    - m.m[2] * m.m[4] * m.m[11] * m.m[14]
    - m.m[0] * m.m[6] * m.m[9] * m.m[15];
}

/* Invert a 2d matrix returns whether or not their is an inverse */
bool m2_invert(mat2_t *res, mat2_t m) {
  f32 det = m2_determinant(m);
  if (det == 0.0f)
    return false;
  res->m[0] = m.m[3] / det;
  res->m[1] = -m.m[1] / det;
  res->m[2] = -m.m[2] / det;
  res->m[3] = m.m[0] / det;
  return true;
}
/* Invert a 3d matrix returns whether or not their is an inverse */
bool m3_invert(mat3_t *res, mat3_t m) {
  f32 det = m3_determinant(m);
  if (det == 0.0f)
    return false;
  for (int i = 0; i < 9; i++)
    res->m[i] = m.m[i] / det;
  return true;
}
/* Invert a 4d matrix returns whether or not their is an inverse */
bool m4_invert(mat4_t *res, mat4_t m) {
  f32 det = m4_determinant(m);
  if (det == 0.0f)
    return false;
  for (int i = 0; i < 16; i++)
    res->m[i] = m.m[i] / det;
  return true;
}

/* Transpose a 2d matrix */
void m2_transpose(mat2_t *res, mat2_t m) {
  res->m[0] = m.m[0];
  res->m[1] = m.m[2];
  res->m[2] = m.m[1];
  res->m[3] = m.m[3];
}
/* Transpose a 3d matrix */
void m3_transpose(mat3_t *res, mat3_t m) {
  res->m[0] = m.m[0];
  res->m[1] = m.m[3];
  res->m[2] = m.m[6];
  res->m[3] = m.m[1];
  res->m[4] = m.m[4];
  res->m[5] = m.m[7];
  res->m[6] = m.m[2];
  res->m[7] = m.m[5];
  res->m[8] = m.m[8];
}
/* Transpose a 4d matrix */
void m4_transpose(mat4_t *res, mat4_t m) {
  res->m[0] = m.m[0];
  res->m[1] = m.m[4];
  res->m[2] = m.m[8];
  res->m[3] = m.m[12];
  res->m[4] = m.m[1];
  res->m[5] = m.m[5];
  res->m[6] = m.m[9];
  res->m[7] = m.m[13];
  res->m[8] = m.m[2];
  res->m[9] = m.m[6];
  res->m[10] = m.m[10];
  res->m[11] = m.m[14];
  res->m[12] = m.m[3];
  res->m[13] = m.m[7];
  res->m[14] = m.m[11];
  res->m[15] = m.m[15];
}

/* Multiply two 2d matrices */
void m2_mul(mat2_t *res, mat2_t m1, mat2_t m2) {
  res->m[0] = m1.m[0] * m2.m[0] + m1.m[1] * m2.m[2];
  res->m[1] = m1.m[0] * m2.m[1] + m1.m[1] * m2.m[3];
  res->m[2] = m1.m[2] * m2.m[0] + m1.m[3] * m2.m[2];
  res->m[3] = m1.m[2] * m2.m[1] + m1.m[3] * m2.m[3];
}
/* Multiply two 3d matrices */
void m3_mul(mat3_t *res, mat3_t m1, mat3_t m2) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      res->m[i * 3 + j] = m1.m[i * 3 + 0] * m2.m[0 * 3 + j] +
                          m1.m[i * 3 + 1] * m2.m[1 * 3 + j] +
                          m1.m[i * 3 + 2] * m2.m[2 * 3 + j];
    }
  }
}
/* Multiply two 4d matrices */
void m4_mul(mat4_t *res, mat4_t m1, mat4_t m2) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      res->m[i * 4 + j] = m1.m[i * 4 + 0] * m2.m[0 * 4 + j] +
                          m1.m[i * 4 + 1] * m2.m[1 * 4 + j] +
                          m1.m[i * 4 + 2] * m2.m[2 * 4 + j] +
                          m1.m[i * 4 + 3] * m2.m[3 * 4 + j];
    }
  }
}

/* Multiply a 2d matrix with a 2d vector */
void m2v2_mul(vec2_t *res, mat2_t m, vec2_t v) {
  res->x = m.m[0] * v.x + m.m[1] * v.y;
  res->y = m.m[2] * v.x + m.m[3] * v.y;
}
/* Multiply a 3d matrix with a 3d vector */
void m3v3_mul(vec3_t *res, mat3_t m, vec3_t v) {
  res->x = m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z;
  res->y = m.m[3] * v.x + m.m[4] * v.y + m.m[5] * v.z;
  res->z = m.m[6] * v.x + m.m[7] * v.y + m.m[8] * v.z;
}
/* Multiply a 4d matrix with a 4d vector */
void m4v4_mul(vec4_t *res, mat4_t m, vec4_t v) {
  res->x = m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z + m.m[3] * v.w;
  res->y = m.m[4] * v.x + m.m[5] * v.y + m.m[6] * v.z + m.m[7] * v.w;
  res->z = m.m[8] * v.x + m.m[9] * v.y + m.m[10] * v.z + m.m[11] * v.w;
  res->w = m.m[12] * v.x + m.m[13] * v.y + m.m[14] * v.z + m.m[15] * v.w;
}
