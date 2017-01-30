/*
    basic/extralong.c - extra long descriptions (to livings or rooms)
    Feb 1992 by marion@cs.tu-berlin.de
*/


// Add extra_longs to rooms instead of putting items into them
// that define the function extra_long has been added by Carador,
// Feb-1996. 
// Of course putting items into the room still works. But you
// also can do a:
// room->add_extra_long(identifier, extra_long);
// E.g.:
// room->add_extra_long("carador#castle_entrance", 
//      "A nice path leads west to Carador's castle.\n");
//
// Of course you can remove that extra_long again with
// room->remove_extra_long("carador#castle_entrance");

private mapping extra_longs;

void add_extra_long(string which, mixed what) {
  if (!which || !what)
    return;

  if (!extra_longs)
    extra_longs = ([ which : what ]);
  else if (!member(extra_longs, which))
    extra_longs += ([ which : what ]);
  else
    extra_longs[which] = what;
}

void remove_extra_long(string which) {
  if (extra_longs && extra_longs[which])
    m_delete(extra_longs, which);
}

private string extra_long_map (object ob) {
  string str;

  if (str = funcall(ob->extra_long()))
    return str;
  return "";
}

string query_extralong_long () {
  int i;
  string res;
  string *keys;

  res = "";

  if (extra_longs) {
    keys = m_indices(extra_longs);
    for (i=sizeof(keys); i--;)
      res += funcall(extra_longs[keys[i]]) || "";
  }

  return res + implode(map(all_inventory(this_object()), #'extra_long_map), "");
}

mixed query_extra_long(string id) {
  return extra_longs && extra_longs[id];
}

varargs string query_long (string str) {
  return query_extralong_long ();
}

