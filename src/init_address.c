#include "ft_malloc.h"

void init_address(void)
{
  int pagesize;

  if (!g_malloc_data.pagesize)
  {
    pagesize = getpagesize();
    g_malloc_data.pagesize = pagesize;
  }
  printf("%d\n", g_malloc_data.pagesize);
}
