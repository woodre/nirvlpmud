/*
 * marion@cs.tu-berlin.de
 *
 *  This module requires you to inherit /basic/namespace in your code.
 *
 *  Alias - a generalized naming functionality for fakeitems or exits
 *  or other table queries.
 */

#pragma strong_types

#include "/basic/namespace.h"

#define ALIAS_NAMES ({ "/basic/alias" })

private string *alias_names;

varargs int id_alias(string subject, string *space) {
  mixed desc;

  if (!space)
    space = alias_names ? alias_names : (alias_names = ALIAS_NAMES);
  if (desc = get_namespace(space + ({ lower_case(subject) }))) {
    if (closurep(desc)) {
#if 1
      return !!funcall(desc, 1);
#else
      return 1;
#endif
    }
    return 1;
  }
  return 0;  // Coogan, 28-Mar-2011
}

varargs string query_alias(string subject, string *space) {
  mixed desc;

  if (!space)
    space = alias_names ? alias_names : (alias_names = ALIAS_NAMES);
  if (desc = get_namespace(space + ({ lower_case(subject) })))
    return funcall(desc);
  return 0;  // Coogan, 28-Mar-2011
}

varargs void set_single_alias (string name, mixed description, string *space) {
  if (!space)
    space = alias_names ? alias_names : (alias_names = ALIAS_NAMES);
  if (!get_namespace(({ space[0] })))
    add_namespace(space[0]);
  set_namespace(space + ({ lower_case(name) }), description);
}

// changed function type from int to void, Coogan, 24-Mar-2011
void _set_aliasF(string name, mixed x) {
  set_namespace(x[1] + ({ lower_case(name) }), x[0]);
}

varargs void set_alias(mixed names, mixed description, string *space) {
  if (!space)
    space = alias_names ? alias_names : (alias_names = ALIAS_NAMES);
  if (!get_namespace(({ space[0] })))
    add_namespace(space[0]);

  if (!pointerp(names)) 
    set_single_alias(lower_case(names), description, space);
  else
    // filter() -> map(), Coogan, 24-Mar-2011
    map(names, "_set_aliasF", this_object(), ({ description, space }));
}

varargs void set_aliases (mixed *names, mixed *descriptions, string *space) {
  int i;

  for (i = 0; i < sizeof(names); i++)
    set_alias(names[i], descriptions[i], space);
}

varargs void remove_single_alias(string name, string *space) {
  mapping n;
  if (!space) 
    space = alias_names;
  n = get_namespace(space);
  if (n) 
    m_delete(n, lower_case(name));
}

void set_alias_names (string *str) {
  alias_names = map(str, #'lower_case);
}

