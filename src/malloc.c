#include "ft_malloc.h"

void  *malloc(size_t size)
{
  if (size < 1)
    return (NULL);
  pthread_mutex_lock(&g_malloc_mutex);
  init_address();
  pthread_mutex_unlock(&g_malloc_mutex);
  return (NULL);
}
