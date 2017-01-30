/*
    $Id: timedepdesc.c,v 1.3 11-Jun-1992 16:21:09 tubmud Exp $
    marion@cs.tu-berlin.de

    This module requires you to inherit /basic/namespace in your code.
    This module requires you to inherit /basic/timedep in your code.
*/

#include <timedep.h>  // Coogan, 25-Oct-1997
#include "/basic/namespace.h"
#include "/basic/timedep.h"

#define TIMEDEPDESC_SPACE ({"/basic/timedepdesc"})

void set_description_long(mixed desc);

private string *timedepdesc_space;

varargs int set_timedepdesc(string *descriptions, string *depspace,
                            string *space) {
  string *keys;
  int i;

  // added next two checks, Coogan, 05-Nov-2001
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

  for (i = 0; i < sizeof (keys); i++) {
    if (!set_namespace(space + ({ keys[i] }), descriptions[i]))
      return 0;
  }
  return 1;
}

varargs int add_timedepdesc (mixed key, string description, string *space) {
  if (!space)
    space = timedepdesc_space;
  if (!timedepdesc_space)
    timedepdesc_space = space;
  return set_namespace (space + ({ "keys", key}), description);
}

varargs string query_timedepdesc (string *space, string *depspace) {
  // ({ "void" }) cases added by Coogan, 26-Oct-1997
  if (!space)
    space = timedepdesc_space || ({ "void" });
  if (!depspace)
    depspace = get_namespace(space + ({ "namespace" })) || ({ "void" });
  return (string)get_namespace(space + ({ "keys", query_timedep(depspace) }));
}

/* marion
 * Sorry, but this depends on the namespace organization
 */
varargs string* query_timedepdesc_table (string *space) {
  if (!space)
    space = timedepdesc_space;
  return m_indices(get_namespace(space + ({ "keys" })));
  /* changed by Ugh 23-Dec-1994 */
}

void set_timedepdesc_space(string *space) {
  timedepdesc_space = space;
}

/* set a time dependant long description, foslay Jan-24-1993 */
// made it varargs, Coogan, 25-Oct-1997
varargs void set_long(mixed desc, mixed *depspace) {
  if (!pointerp(desc))
    return set_description_long(desc);
  else
    set_description_long(0);  // added this branch, Coogan, 05-Nov-2001
  if (!depspace)
    depspace = DEFAULT_DEPSPACE[sizeof(desc)];
  if (depspace && !get_namespace(depspace))
    set_default_depspace(depspace);
  set_timedepdesc(desc, depspace);
}

// removed the arg 'string subject' as this has never been in use.
// // Coogan, 26-Sep-2010
string query_composite_long() {
  return query_timedepdesc();
}

