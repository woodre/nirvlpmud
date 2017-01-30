/*
 * /kernel/support/light.c
 * New light system
 */

#include "/sys/limits.h"

// Caution: This behaviour is buggy!
// #define UPDATE_LIGHT_BEHAVIOUR

#define INWARD          0
#define OUTWARD         1
#define ABSORPTION      2
#define CONNECTED       3
#define INCONSISTENT    4       
#define LAST_UPDATE     5
#define INNER           6
#define OUTER           7
#define LAST_INWARD     8
#define LAST_OUTWARD    9
#define DATA_WIDTH      10

private mapping light_data;
private mapping magic_cookie;

/*
   light_data is a mapping which maps for each light-involved object
   (that is, objects that emit or absorb light and objects for which
   the light-level is queried) to the following items:

   inward:       abstract light emitted to the inventory (from only the object)
   outward:      abstract light emitted to the environment
                 and siblings (from the object)
   absorption:   how much light is being absorbed (entering or leaving) by 
                 the object
   inner:        how much light comes from the objects in the inventory
   outer:        how much light comes from the environment and siblings
   inconsistent: flag for light-objects for which the light-level has to be
                 recomputed
   last_inward:  concrete inward light computed the last time
   last_outward: concrete outward light computed the last time
*/

#define LIGHT_DATA "/kernel/simul/light::light_data"
#define MAGIC_COOKIE "/kernel/simul/light::magic_cookie"

static mapping light_magic_cookie() {
  mixed h;

  if (!magic_cookie) {
    if (!(h = get_extra_wizinfo(0)))
      set_extra_wizinfo(0,h = ([]));
    if (!(light_data = h[LIGHT_DATA]))
      light_data = h[LIGHT_DATA] = m_allocate(100,DATA_WIDTH);
    // This mapping is stored in the move-hook-unbound-lambda of the master
    // which gives it as an argument to move_light()
    // This shall prevent others from unprivileged access to that function
    if (!(magic_cookie = h[MAGIC_COOKIE]))
      magic_cookie = h[MAGIC_COOKIE] = ([]);
  }
  return magic_cookie;
}

private /* status */ int is_light(object light) {
  return member(light_data,light);
}

/* filter the given array of objects for light objects */
private object *get_lights(object *lights) {
  return filter(lights,light_data);
}

private object *get_light_tree(object node) {
  mixed h;

  while (h = environment(node))
    node = h;
  return get_lights(deep_inventory(node) + ({ node }));
}

#define IF_INNER 1
#define IF_OUTER 2

private void mark_consistent(object ob, int flags) {
  light_data[ob,INCONSISTENT] &= ~flags;
}

static status is_inconsistent(object ob, int flags) {
  return !!(light_data[ob,INCONSISTENT] & flags);
}

private varargs void mark_inward_inconsistent(object ob, object exclude) {
  object h;

  if (!is_inconsistent(ob,IF_OUTER)) {
#ifdef DEBUG
    "kernel/simul_efun"->debug("rumplemintz",({"inward_inconsistent",ob}));
#endif
    if (is_light(ob)) 
      light_data[ob,INCONSISTENT] |= IF_OUTER;
    for (h = first_inventory(ob); h; h = next_inventory(h))
      if (h != exclude)
        mark_inward_inconsistent(h);
  }
}

private varargs void mark_outward_inconsistent(object ob) {
  object h;

  if (!is_inconsistent(ob,IF_INNER)) {
#ifdef DEBUG
    "kernel/simul_efun"->debug("rumplemintz",({"outward_inconsistent",ob}));
#endif
    if (is_light(ob))
      light_data[ob,INCONSISTENT] |= IF_INNER;
    if (h = environment(ob)) {
      mark_outward_inconsistent(h);
      mark_inward_inconsistent(h,ob);
    }
  }
}

private varargs void mark_inconsistent(object ob) {
  mark_inward_inconsistent(ob);
  mark_outward_inconsistent(ob);
}

private void set_last_update(object light, int t) {
  light_data[light,LAST_UPDATE] = t;
}

private int query_last_update(object light) {
  return light_data[light,LAST_UPDATE];
}

public int query_last_inward_light(object light) {
  return light_data[light,LAST_INWARD];
}

private varargs void notify_light_change_inward(object ob,object exclude) {
  object h;
  ob->notify_light_change();
  for (h = first_inventory(ob); h; h = next_inventory(h))
    if (h != exclude)
      notify_light_change_inward(h);
}

private void notify_light_change_outward(object ob) {
  object h;
  ob->notify_light_change();
  if (h = environment(ob)) {
    notify_light_change_outward(h);
    notify_light_change_inward(h,ob);
  }
}

// this will be called by simul_efun
public void notify_server_light_change(object ob) {
  limited((: (notify_light_change_inward($1),
              notify_light_change_outward($1)) :),
          ({ MAX_COST }), ob);
}

private void set_last_inward_light(object light, int level) {
  if (light_data[light,LAST_INWARD] != level)
    mark_inward_inconsistent(light);
  light_data[light,LAST_INWARD] = level;
#ifdef UPDATE_LIGHT_BEHAVIOUR
  set_last_update(light,time());
#endif
}

public mixed query_inward_light(object light) {
  return light_data[light,INWARD];
}

private void set_inward_light(object light, mixed level) {
  light_data[light,INWARD] = level;
  set_last_inward_light(light,funcall(level));
}

public int query_last_outward_light(object light) {
  return light_data[light,LAST_OUTWARD];
}

private void set_last_outward_light(object light, int level) {
  if (light_data[light,LAST_OUTWARD] != level)
    mark_outward_inconsistent(light);
  light_data[light,LAST_OUTWARD] = level;
#ifdef UPDATE_LIGHT_BEHAVIOUR
  set_last_update(light,time());
#endif
}

public mixed query_outward_light(object light) {
  return light_data[light,OUTWARD];
}

private void set_outward_light(object light, mixed level) {
  light_data[light,OUTWARD] = level;
  set_last_outward_light(light,funcall(level));
}

// This function is called by the master object when invoking the
// Move-Hook-Function (a la move_object())
// before the object is actually moved
void move_light(object ob, object to, mapping cookie) {
  if (magic_cookie != cookie)
    raise_error("Unauthorized call of move_light()\n");
#ifdef DEBUG
  "kernel/simul_efun"->debug("rumplemintz",({"move_light", ob, to}));
#endif
  mark_inconsistent(ob); 
  mark_outward_inconsistent(to);  // why not also inward?
}

// this function is alike, but called _after_ the move
void notify_move_light(object from, object ob /* , mapping cookie */) {
  object h;
#if 0  // as notify_server_light_change() is public, this test is
       // unnessessary.
  if (magic_cookie != cookie)
    raise_error("Unauthorized call of notify_move_light()\n");
#endif
  while (from && (h=environment(from)))
    from = h;
  while (ob && (h=environment(ob)))
    ob = h;
  //"kernel/simul_efun"->debug("rumplemintz",({"notify_move_light", from, ob}));
  if (from)
    notify_server_light_change(from);
  //"kernel/simul_efun"->debug("rumplemintz",({"notify_move_light", from, ob}));
  if (ob && ob != from)
    notify_server_light_change(ob);
}

public int query_absorption(object ob) {
  return light_data[ob,ABSORPTION];
}

private int absorb_light(int light, int absorption) {
  if (light >= 0) {
    if ((light -= absorption) < 0)
      return 0;
  } else {
    if ((light += absorption) > 0)
      return 0;
  }
  return light;
}

public int compute_outward_light(object light);
public int compute_inward_light(object light);
public object *get_light_connections(object light);

static int query_inner_light(object ob) {
  int result;
  object next;
  status lit;

  if (!(lit = is_light(ob)) || is_inconsistent(ob,IF_INNER)) {
#ifdef DEBUG
    "kernel/simul_efun"->debug("rumplemintz",({"query_inner_light",ob}));
#endif
    for (next = first_inventory(ob); next; next = next_inventory(next))
      result += compute_outward_light(next);
    if (lit) {
      light_data[ob,INNER] = result;
      mark_consistent(ob,IF_INNER);
    }
  } else {
    result = light_data[ob,INNER];
  }
  return result;
}

static int query_outer_light(object ob) {
  int result, h, i;
  object next, env, *connected;
  status lit;

  if (!(lit = is_light(ob)) || is_inconsistent(ob,IF_OUTER)) {
#ifdef DEBUG
    "kernel/simul_efun"->debug("rumplemintz",({"query_outer_light",ob}));
#endif
    if (env = environment(ob)) {
      result += compute_inward_light(env);
      for (next = first_inventory(env); next; next = next_inventory(next))
        if (ob != next)
          result += compute_outward_light(next);
    }
    if (connected = get_light_connections(ob)) {
      for (i = sizeof(connected); i--; )
        if (connected[i])
          result += compute_outward_light(connected[i]);
    }
    if (lit) {
      mark_consistent(ob,IF_OUTER);
      light_data[ob,OUTER] = result;
    }
  } else {
    result = light_data[ob,OUTER];
  }
  return result;
}

public int compute_inward_light(object ob) {
  return
    absorb_light(query_outer_light(ob),query_absorption(ob)) +
    query_last_inward_light(ob);
}

public int compute_outward_light(object ob) {
  return
    absorb_light(query_inner_light(ob),query_absorption(ob)) +
    query_last_outward_light(ob);
}

private int has_to_update(object ob) {
#ifdef UPDATE_LIGHT_BEHAVIOUR
  return
    query_last_update(ob) < time();
#else
  return 1;
#endif
}

private void update_light(object ob) {
  mixed inward, outward;

  if (has_to_update(ob)) {
    if (closurep(inward = query_inward_light(ob)))
      set_last_inward_light(ob,funcall(inward));
    if (closurep(outward = query_outward_light(ob)))
      set_last_outward_light(ob,funcall(outward));
  }
}

/* this function is only called with _new_ light objects */
private varargs void insert_light(object ob, mixed inward, mixed outward) {
  set_inward_light(ob,inward);
  set_outward_light(ob,outward);
  light_data[ob,INCONSISTENT] = IF_INNER|IF_OUTER;
}

/* this function is only called with _old_ light objects */
private void modify_light(object ob, mixed inward, mixed outward) {
  mixed h;

  if (inward) {
    if (closurep(h = query_inward_light(ob)) || closurep(inward))
      h = inward;
    else
      h += inward;
    set_inward_light(ob,h);
  }
  if (outward) {
    if (closurep(h = query_outward_light(ob)) || closurep(outward))
      h = outward;
    else
      h += outward;
    set_outward_light(ob,h);
  }
}

/*
  There are three possible kinds of values for 'amount':
  - an integer
  - a closure returning an integer
  - a pair of inward and outward light-values of the first or second kind
  Closures override beforehand values completely.
  Integers override beforehand closures.
  Integers are added to integers.
  Only closures from the light-object itself can be added.
  Light-Objects that the object shines upon are marked inconsistent for
  recomputation. 
  The resulting new amount of light that comes _to_ the object
  (from within and without) is returned as result.
  Only non-negative light-values are returned.
  If the result would be negative, 0 is returned.
*/
public mixed add_light(mixed amount, object ob) {
  object next, n, p, env;
  mixed h, inward, outward;

  if (pointerp(amount)) {
    inward = amount[INWARD];
    outward = amount[OUTWARD];
  } else {
    inward = outward = amount;
  }
  if ((closurep(inward) && to_object(inward) != ob) ||
      (closurep(outward) && to_object(outward) != ob))
    raise_error("Bad argument 1 to set_light()\n");
  if (!is_light(ob)) {
    insert_light(ob,inward,outward);
  } else { // object was already a light
    modify_light(ob,inward,outward);
  }
  filter(get_light_tree(ob),#'update_light);
  h = compute_inward_light(ob) + query_inner_light(ob);
  return h > 0 && h;
}

static void remove_light(object ob) {
  mark_inconsistent(ob);
  m_delete(light_data,ob);
  //catch(
  notify_server_light_change(ob)
    //)
    ;
}

private void set_absorption(object light, int absorption) {
  light_data[light,ABSORPTION] = absorption;
}

public void add_absorption(int amount, object ob) {
  int absorption;
  object h, env;

  if (!is_light(ob))
    insert_light(ob);
  else
    absorption = query_absorption(ob);
  if (amount < 0 && -amount > absorption) // don't let absorption drop below 0
    amount = -absorption;
  if (amount) { // any change?
    set_absorption(ob,absorption+amount);
    mark_inconsistent(ob);
  }
}

public void add_light_connection(object ob, mixed to) {
  mixed h;

  if (!objectp(to) && !closurep(to))
    return;
  if (!is_light(ob))
    insert_light(ob);
  if ((h = light_data[ob,CONNECTED]) && member(h,to) >= 0)
    return;
  light_data[ob,CONNECTED] = (h||({})) + ({ to });
}

public object *get_light_connections(object ob) {
  mixed h;

  if (h = light_data[ob,CONNECTED])
    return get_lights(map(h,#'funcall));
}

/*
 * This returns the light sources that are in the inventory of the given
 * object 'ob', excluding the subtree with the root-node 'exclude'.
 */
public varargs mapping query_inner_light_sources(object ob, object exclude) {
  mixed h;
  int i, level, a;
  object n, *lights;
  mapping result;

  result = ([]);
  for (n = first_inventory(ob); n; n = next_inventory(n)) {
    if (n != exclude) {
      h = query_inner_light_sources(n);
      if (sizeof(h)) {
        a = query_absorption(n)/sizeof(h);
        for (i = sizeof(h), lights = m_indices(h); i--; )
          if ((level = h[lights[i]] - a) > 0)
            result[lights[i]] = level;
      }
      if ((level = query_inner_light(n)+query_last_outward_light(n)) > 0)
        result[n] = level;
    }
  }
  return result;
}

/*
 * This function returns all light sources that are not in the inventory
 * of the given object. If the object itself has an inward light, it is
 * comprised in the result.
 */
public mapping query_outer_light_sources(object ob) {
  mixed h;
  int i, a, level;
  object next, *lights;
  mapping result;

  result = ([]);
  if (next = environment(ob)) {
    h = query_outer_light_sources(next);
    if (sizeof(h)) {
      a = query_absorption(next)/sizeof(h);
      for (i = sizeof(h), lights = m_indices(h); i--; )
        if ((level = h[lights[i]] - a) > 0)
          result[lights[i]] = level;
    }
    if ((level = query_outer_light(next)) > 0)
      result[next] = level;
    h = result + query_inner_light_sources(next,ob);
    if (sizeof(h)) {
      a = query_absorption(ob)/sizeof(h);
      for (i = sizeof(h), lights = m_indices(h); i--; )
        if ((level = h[lights[i]] - a) > 0)
          result[lights[i]] = level;
    }
  }
  if ((level = query_outer_light(ob)+query_last_inward_light(ob)) > 0)
    result[ob] = level;
  return result;
}

/*
 * This computes all light sources that give light to the inventory of
 * the object ob. Actually, a mapping (object -> brightness) is returned.
 */
public mapping query_light_sources(object ob) {
  // do not add 'ob' to the light-tree
  // if (!is_light(ob))
  //   insert_light(ob);
  return query_inner_light_sources(ob) + query_outer_light_sources(ob);
}

// #define LIGHT_DEBUG
#ifdef LIGHT_DEBUG
public mapping query_light_data()
{
  return light_data;
}
#endif

