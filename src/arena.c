/* Implements arena.h */
#include <arena.h>

/* Initialize an arena (if base is NULL, allocate on heap) */
void arena_init(arena_t *arena, void *base, size_t size) {
  arena->base = base;
  arena->own_alloc = false;
  if (!base) {
    arena->own_alloc = true;
    arena->base = malloc(size);
    ASSERT_ERRNO(arena->base);
  }
  arena->curr = arena->base;
  arena->size = size;
}
/* Free an arena */
void arena_free(arena_t *arena) {
  if (arena->own_alloc) {
    free(arena->base);
  }
  arena->base = NULL;
  arena->curr = NULL;
  arena->size = 0;
  arena->own_alloc = false;
}
/* Allocate size bytes on an arena */
void *arena_alloc(arena_t *arena, size_t size) {
  ASSERT_MSG(
      (u8*)(arena->curr) + size <= (u8*)(arena->base) + arena->size,
      "Arena allocator full"
  );
  void *res = arena->curr;
  arena->curr = (u8*)(arena->curr) + size;
  return res;
}
