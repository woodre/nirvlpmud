/*
    basic/light.c - Wrapper for the set_light efun
    Feb 1992 by marion@cs.tu-berlin.de
    changed for new light system by Ugh Dec-22-1995
*/

#ifndef NEW_LIGHT /* old light-system behaviour */
private int light_value;

/*	query_light - query the light given by the current object */
int
query_light ()
{
    return light_value;
}

/*	light - get the current light in the environment */
int
light ()
{
    return efun::set_light (0);
}

/*	add_light - this has the old efun::set_light functionality */
int
add_light (mixed l)
{
    light_value += l;
    return efun::set_light (l);
}

/*	set_light - actually set the light, don't add to it */
int
set_light (mixed l)
{
    return add_light (l - light_value);
}

#else /* new light system behaviour */

private static int light_value;
private static closure light_closure;

// query_light - query the light given by the current object
int
query_light() {
  return light_value + funcall(light_closure);
}

// add_light - this has the old efun::set_light functionality
int
add_light(mixed l) {
  if (closurep(l)) {
    if (!light_closure) {
      light_closure = l;
      return simul_efun_call("set_light", #'query_light);
    }
    light_closure = l;
  }
  else
    light_value += l;
  return simul_efun_call("set_light", (!light_closure && l));
}

// light - get the current light in the environment
int
light() {
  return add_light(0);
}

// set_light - actually set the light, don't add to it
int
set_light(mixed l) {
  if (closurep(l)) {
    if (light_value)
      add_light(-light_value);
    return add_light(l);
  } else {
    light_closure = 0;
    return add_light(l - light_value);
  }
}

static closure  // Coogan, 01-Jun-1999; needed for complex/room
query_light_closure() {
  return light_closure;
}
#endif

