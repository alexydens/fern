/* Implements arena.h */
#include <arena.h>

/* Create an arena */
void arena_create(arena_t *arena, void *base, u32 size) {
  arena->base = base;
  arena->pos = base;
  arena->size = size;
}
/* Free an arena */
void arena_free(arena_t *arena) {
  memset(arena, 0, sizeof(arena_t));
}
/* Allocate size bytes on an arena */
void *arena_alloc(arena_t *arena, u32 size) {
  void *ptr = arena->pos;
  arena->pos = (u8 *)ptr + size;
  if ((u8 *)arena->pos > (u8 *)arena->base + arena->size)
    return NULL;
  return ptr;
}
