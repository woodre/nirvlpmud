/*
 * basic/cache.c -- stores once computed results for a given time.
 *
 * by Alfe for Tubmud 2001-Aug-1
 */

#include <time_units.h>

private mapping cache;

varargs mixed get_cache(mixed key,mixed computer,int time_to_live,
                        status force_update) {
  if (!cache)
    cache = m_allocate(0,2);
  if (!stringp(key) || strlen(key) > 32)  // Alfe 2002-Mar-27
    key = md5(sprintf("%O", key));
  if (force_update || cache[key,1] <= time())  // not in cache?
    cache += ([ key: funcall(computer); (time() +
                                         (time_to_live || 30 * ONE_MINUTE)) ]);
  return cache[key];
}

void reset(status refresh) {
  if (!cache)
    cache = m_allocate(0,2);
  else
    cache = filter(cache,(: $3 > time() :));  // remove all outdated ones
}

mapping query_cache() {
  return cache;
}

varargs void clear_cache(string key) {
  if (key)
    m_delete(cache,key);
  else
    cache = 0;
}
