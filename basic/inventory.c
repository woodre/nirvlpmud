/*
 * /basic/inventory.c
 *
 */
#include <regexps.h>

status id(string str);

object * get_inventory(string which, string preposition) {
  if (which && !id(which))
    return 0;
  return all_inventory();
}

varargs void remove_inventory(object ob, string which, string preposition) {
  if (!objectp(ob))
    raise_error("Bad argument 1 to remove_inventory()\n");
  if (which && !id(which))
    return;
  // FIXME: and? what here?
}

varargs status add_inventory(object ob, string which, string preposition) {
  if (!objectp(ob))
    raise_error("Bad argument 1 to add_inventory()\n");
  if (!(which || id(which)))
    return 0;
  return !(move_object(ob,this_object()));
}

varargs object contains_inventory(mixed ob, string which, string preposition) {
  int i, c;
  mixed h;
  object *inv;

  if (which && !id(which))
    return 0;
  inv = get_inventory(which,preposition);
  if (!inv)
    return 0;
  if (objectp(ob))
    return member(inv,ob) >= 0 && ob;
  if (stringp(ob)) {
    for (i = sizeof(inv); i; i--)
      if (inv[<i]->id(ob))
	return inv[<i];
    if (sizeof(h = explode(ob," ")) > 1 &&
        IS_REGEXP(h[<1],REGEXP_UNSIGNED_INT)) {
      ob = implode(h[0..<2]," ");
      h = to_int(h[<1]);
      for (i = sizeof(inv); i; i--)
        if (inv[<i]->id(ob))
          if (++c == h)
            return inv[<i];
    }
  }
  else
    raise_error("Bad argument 1 to contains_inventory()\n");
  return 0;
}

