/*
 * basic/timedepdesc.c
 * 
 * This module requires you to inherit /basic/namespace in you code
 * This module requires you to inherit /basic/timedep in your code
 */

#include <timedep.h>
#include "/basic/namespace.h"
#include "/basic/timedep.h"

#define TIMEDEPDESC_SPACE ({"/basic/timedepdes"})

void set_description_long(mixed desc);

private string *timedepdesc_space;

varargs int set_timedepdesc(string *descriptions, string *depspace,
                            string *space) {
  string *keys;
  int i;

  if (!depspace)
    depspace = DEFAULT_DEPSPACE[sizeof(descriptions)];

  if (depspace && !get_namespace(depspace))
    set_default_depspace(depspace);

  if (!space)
    space = timedepdesc_space ? timedepdesc_space : TIMEDEPDESC_SPACE;

  if (!get_namespace(({ space[0] })))
    add_namespace(space[0]);

  if (!timedepdesc_space)
    timedepdesc_space = space;

  if (depspace && !set_namespace(space + ({ "namespace" }), depspace))
    return 0;

  keys = query_timedep_table(depspace)[1];

  space += ({ "keys" });

  for (i=0; i<sizeof(keys); i++) {
    if (!set_namespace(space + ({ keys[i] }), descriptions[i]))
      return 0;
  }
  return 1;
}

varargs int add_timedepdesc(mixed key, string description, string *space) {
  if (!space)
    space = timedepdesc_space;
  if (!timedepdesc_space)
    timedepdesc_space = space;
  return set_namespace(space + ({ "keys", key}), description);
}

varargs string query_timedepdesc(string *space, string *depspace) {
  if (!space)
    space = timedepdesc_space || ({ "void" });
  if (!depspace)
    depspace = get_namespace(space + ({ "namespace" })) || ({ "void" });
  return (string)get_namespace(space + ({ "keys", query_timedep(depspace) }));
}

varargs string *query_timedepdesc_table(string *space) {
  if (!space)
    space = timedepdesc_space;
  return m_indices(get_namespace(space + ({ "keys" })));
}

void set_timedepdesc_space(string *space) {
  timedepdesc_space = space;
}

/* Set a time dependant long description */
varargs void set_long(mixed desc, mixed *depspace) {
  if (!pointerp(desc))
    return set_description_long(desc);
  else
    set_description_long(0);
  if (!depspace)
    depspace = DEFAULT_DEPSPACE[sizeof(desc)];
  if (depspace && !get_namespace(depspace))
    set_default_depspace(depspace);
  set_timedepdesc(desc, depspace);
}

string query_composite_long() {
  return query_timedepdesc();
}
