/* Include guard */
#if !defined(ARENA_H)
#define ARENA_H

/* Includes */
#include <base.h>
#include <logging.h>

/* Types */
/* Arena allocator */
typedef struct {
  void *base;
  void *curr;
  size_t size;
  bool own_alloc;
} arena_t;

/* Initialize an arena (if base is NULL, allocate on heap) */
extern void arena_init(arena_t *arena, void *base, size_t size);
/* Free an arena */
extern void arena_free(arena_t *arena);
/* Allocate size bytes on an arena */
extern void *arena_alloc(arena_t *arena, size_t size);

#endif /* ARENA_H */
