/* Include guard */
#if !defined(ARENA_H)
#define ARENA_H

/* Includes */
#include <base.h>

/* Arena */
typedef struct {
  void *base;
  void *pos;
  u32 size;
} arena_t;

/* Create an arena */
extern void arena_create(arena_t *arena, void *base, u32 size);
/* Free an arena */
extern void arena_free(arena_t *arena);
/* Allocate size bytes on an arena */
extern void *arena_alloc(arena_t *arena, u32 size);

#endif /* ARENA_H */
