/*
 * /basic/cloak.c
 * A generic inheritable cloak to filter a living's functions.
 * By Alfe for Tubmud.
 */

#include <filter.h>

private mapping cloak_values;
private object victim;

mixed query_cloak_value(mixed filter) { return cloak_values[filter]; }
status cloak_value_exists(mixed filter) { return member(cloak_values,filter); }
void set_cloak_value(mixed filter,mixed x) { cloak_values[filter] = x; }
void clear_cloak_value(mixed filter) { m_delete(cloak_values,filter); }

void clear_cloak() {
  cloak_values = ([]);
}

void set_victim(object v) {
  mixed h;
  if (victim && (h=symbol_function("remove_filter",victim)))
    map(F_ALL_FILTERS,h);
  victim = v;
  clear_cloak();
  if (victim && (h=symbol_function("add_filter",victim)))
    map(F_ALL_FILTERS,h,FPRIO_DISGUISE);
}

void init() {
  if (this_player() != environment())
    return;
  set_victim(this_player());
}

mixed do_filter(string func,mixed arg) {
  mixed h;
  if (member(cloak_values,func))
    return funcall(cloak_values[func],arg);
  else
    return arg;
}
