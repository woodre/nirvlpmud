/*
 * basic/populate.c - an easy-to-populate interface for rooms, NPCs and items.
 *
 * This replaces the old basic/populate written by ??.
 * completely rewritten by Coogan, 09-Mar-1999
 * added handling of POP_COMBINE, Coogan, 07-Apr-1999
 * added handling of moving/wimpy monsters, Coogan, 30-Oct-1999
 *
 */

#pragma strong_types

#include <populate.h>
#include <message.h>
#include <prop/npc.h>  // Coogan, 09-Oct-2000
#include <termcol.h>   // Coogan, 26-Nov-2003

inherit "basic/path";  // Coogan, 31-Aug-1999

private nosave mixed *obj_list, *liv_list;
private nosave mapping all_liv_list;  // Coogan, 30-Oct-1999


// next lfun by Coogan, 06-Jul-2001, to distinguish monsters of the same
// filename but with different configuration closures
private string make_key_for_all_liv_list(string s, closure cl) {
  if (cl)
    return s + sprintf("%O", cl);  // "obj/monster#'this_room->init_monster"
  else
    return s;
}

private mixed* normalize_list(mixed *list) {  // Coogan, 31-Aug-1999
  int i;
  for (i = sizeof(list); i-->0; ) {
    if (stringp(list[i]))
      list[i] = load_name(list[i]);
    else
      list[i][0] = load_name(list[i][0]);
  }
  return list;
}

void add_populate_object(varargs mixed* list) {
  if (!obj_list)
    obj_list = ({ });
  list = normalize_list(list);  // Coogan, 31-Aug-1999
  obj_list += list;
}

void add_populate_living(varargs mixed* list) {
  if (!liv_list)
    liv_list = ({ });
  list = normalize_list(list);  // Coogan, 31-Aug-1999
  liv_list += list;
}

void set_populate_object(varargs mixed* list) {
  list = normalize_list(list);  // Coogan, 31-Aug-1999
  obj_list = list;
}

void set_populate_living(varargs mixed* list) {
  list = normalize_list(list);  // Coogan, 31-Aug-1999
  liv_list = list;
}

object* query_object_population() {     // Coogan, 26-Aug-2006
  object *all_inv, *all_obj, o;
  string *all_inv_str;
  int i, j;
  mixed m;
  
  all_inv     = all_inventory(this_object());
  all_inv_str = map(all_inv, #'load_name);
  all_obj = ({ });
  if (obj_list && sizeof(obj_list)) {
    foreach (m : obj_list) {
      if (stringp(m)) {         // simple clone
        if ((i = member(all_inv_str, m)) > -1) {
          all_obj += ({ all_inv[i] });
          all_inv[i..i]     = ({ });
          all_inv_str[i..i] = ({ });
        }
        continue;
      }
      // else: pointerp(m).
      j = m[1];
      if (j == POP_BLUEPRINT) {
        if ((o = find_object(m[0]))) {
          // this we add in any case, but the object may not be present
          all_obj += ({ o });
          if ((i = member(all_inv_str, m[0])) > -1) {
            all_inv[i..i]     = ({ });
            all_inv_str[i..i] = ({ });
          }
          continue;
        }
      }
      do {
        if ((i = member(all_inv_str, m[0])) > -1) {
          all_obj += ({ all_inv[i] });
          all_inv[i..i]     = ({ });
          all_inv_str[i..i] = ({ });
          j--;
        }
        else
          j = 0;
      } while (j > 0);
    }
  }
  return all_obj;
}

object* query_living_population() {     // Coogan, 26-Aug-2006
  return 0; // copy(all_liv_list);
}

static status test_clean_up(int arg) {  // Coogan, 30-Oct-1999
  int i;
  object *l;
  if (arg > 1)
    return 0;
#if 0 // Coogan, 09-Oct-2000
  l = filter(all_liv_list  || ([ ]),
             lambda(({ 'x }),
                    ({ #'||,
                       ({ #'call_other, 'x, "query_wimpy" }),
                       ({ #'call_other, 'x, "query_move_at_reset" })
                    }))));
#else
  // don't care of the blueprint livings
  // added the - ({ 0 }), Coogan, 18-Jun-2001
  l = filter(flatten_array(m_values(all_liv_list || ([ ]))) - ({ 0 }),
             lambda(({ 'x }),
                    ({ #'!=,
                       ({ #'object_name, 'x }),
                       ({ #'load_name, 'x }),
                    })));
  l = filter(l, lambda(({ 'x }),
                       ({ #'!, ({ #'present, 'x, ({ #'this_object }) }) })));
#endif
  return !sizeof(l);
}

void populate() {
  int i, how_much;
  mixed kind;
  status blueprint, action;
  object o, *there, *liv, m, e;
  string what, key;
  closure init_cl;

  if (sizeof(obj_list)) {
    for (i = sizeof(obj_list); i-->0; ) {
      blueprint = action = 0;
      how_much = 1;
      if (stringp(obj_list[i]))
        what = obj_list[i];
      else if (pointerp(obj_list[i])) {
        if (!sizeof(obj_list[i]))
          raise_error("Wrong arguments to add_populate_object()!\n");
        what = obj_list[i][0];
        if (sizeof(obj_list[i]) > 1) {
          if (obj_list[i][1] == POP_BLUEPRINT)
            blueprint = 1;
          else
            how_much = obj_list[i][1];
        }
        if (!how_much)
          raise_error("Wrong arguments to add_populate_object()!\n");
      } else
        raise_error("Wrong arguments to add_populate_object()!\n");
      if (blueprint) {
        move_object(load_object(what), this_object());
      } else {
        there = filter(all_inventory(),
                       lambda(({ 'x }),
                              ({ #'==,
                                 ({ #'load_name, 'x }),
                                 what })));
        while (sizeof(there) < how_much) {
          how_much--;
          o = clone_object(what);
          if (!o)  // object could be destructed, e.g. due to a clone limit
            continue;
          move_object(o, this_object());
          if (pointerp(obj_list[i])) {
            if (sizeof(obj_list[i]) > 3)
              funcall(obj_list[i][3], o);
            if (sizeof(obj_list[i]) > 2) {
              action = obj_list[i][2];
              if (living(this_object())) {
                if (action & POP_WEAR)
                  message_command(({ "wear ", M_NONE, o }));
                if (action & POP_WIELD)
                  message_command(({ "wield ", M_NONE, o }));
              }
            }
          }
        }
      }
    }
  }

  if (!all_liv_list)  // Coogan, 30-Oct-1999
    all_liv_list = ([ ]);

  if (sizeof(liv_list)) {
    liv = ({ });
    for (i = sizeof(liv_list); i-->0; ) {
      kind = POP_COMBINE;
      blueprint = 0;
      how_much = 1;
      init_cl = 0;  // Coogan, 14-Jan-2001
      if (stringp(liv_list[i]))
        what = liv_list[i];
      else if (pointerp(liv_list[i])) {
        if (!sizeof(liv_list[i]))
          raise_error("Wrong arguments to add_populate_living()!\n");
        what = liv_list[i][0];
        if (sizeof(liv_list[i]) > 1) {
          if (liv_list[i][1] == POP_BLUEPRINT)
            blueprint = how_much = 1;
          else
            how_much = liv_list[i][1];
        }
        if (sizeof(liv_list[i]) > 2) {
          kind = liv_list[i][2];
        }
        if (sizeof(liv_list[i]) > 3) {  // added this part, Coogan, 14-Jan-2001
          init_cl = liv_list[i][3];
        }
        if (!how_much)
          raise_error("Wrong arguments to add_populate_living()!\n");
      } else
        raise_error("Wrong arguments to add_populate_living()!\n");
      if (blueprint) {
        o = load_object(what);
        if (environment(o) != this_object()) {
          if (!environment(o) ||  // added this if(), Coogan, 30-Oct-1999
              !o->query_wimpy() &&
              !o->query_move_at_reset() &&
              !o->query_property(P_MOVING_LIVING)) { // move it!
            if (kind == POP_COMBINE) {
              e = environment(o);  // added next if(), Coogan, 09-Nov-1999
              if (!(e && e->prevent_leave(o, this_object())) &&
                  !this_object()->prevent_enter(o, e) &&
                  !o->prevent_move(e, this_object()))
                liv += ({ o });
            } else
              o->move_living(kind, this_object());
          }
        }
#if 1  // Coogan, 09-Oct-2000
        if (all_liv_list[what]) {
          all_liv_list[what,0] = ({ });
        } else {
          all_liv_list += ([ what : ({ o }) ]);
        }
#else
        all_liv_list += ([ o ]);  // Coogan, 30-Oct-1999
#endif
      } else {  // no blueprint
#if 0  // Coogan, 09-Oct-2000
        there = filter(all_inventory(),
                       lambda(({ 'x }),
                              ({ #'==,
                                 ({ #'load_name, 'x }),
                                 what })));
#else
#if 1  // Coogan, 06-Jul-2001
        key = make_key_for_all_liv_list(what, init_cl);
        if (!member(all_liv_list, key))
          all_liv_list += ([ key : ({ }) ]);
        there = all_liv_list[key, 0] - ({ 0 });
#else
        if (!member(all_liv_list, what))
          all_liv_list += ([ what : ({ }) ]);
        there = all_liv_list[what, 0] - ({ 0 });
#endif
        foreach (o : there) {
          if (environment(o) != this_object()) {
            if (!environment(o) ||  // added this if(), Coogan, 30-Oct-1999
                !o->query_wimpy() &&
                !o->query_move_at_reset() &&
                !o->query_property(P_MOVING_LIVING)) { // move it!
              if (kind == POP_COMBINE) {
                e = environment(o);  // added next if(), Coogan, 09-Nov-1999
                if (!(e && e->prevent_leave(o, this_object())) &&
                    !this_object()->prevent_enter(o, e) &&
                    !o->prevent_move(e, this_object()))
                  liv += ({ o });
              } else
                o->move_living(kind, this_object());
            }
          }
        }
#endif
        while (sizeof(there) < how_much) {
          if (kind == POP_COMBINE) {
            o = clone_object(what);
            e = environment(o);  // added next if(), Coogan, 09-Nov-1999
            if (!(e && e->prevent_leave(o, this_object())) &&
                !this_object()->prevent_enter(o, e) &&
                !o->prevent_move(e, this_object())) {
              if (init_cl)
                funcall(init_cl, o);  // Coogan, 14-Jan-2001
              liv += ({ o });
            }
          } else {
            o = clone_object(what);
            if (init_cl)
              funcall(init_cl, o);  // Coogan, 14-Jan-2001
            o->move_living(kind, this_object());
          }
          how_much--;
#if 1
          all_liv_list[key, 0] += ({ o });
          all_liv_list[key, 0] -= ({ 0 });
#else
          all_liv_list[what, 0] += ({ o });  // Coogan, 30-Oct-1999
#endif
        }
      }
    }
  }
  if (sizeof(liv)) {
    send_message(({ M_ROOM, this_object(), M_CNTL_SEQ, TERMCOL_NPC,
                    describe_list(liv), M_VERB, "arrive", liv, ".",
                    M_CNTL_SEQ, TERMCOL_NORMAL }));
    for (i = sizeof(liv); i-->0; ) {
      liv[i]->move_living(0, this_object());
    }
  }
}

void destruct_object_population() {  
        // moved from notify_destruct(),Coogan,20-Nov-2003
        // renamed, Coogan, 26-Aug-2006
  object o;
  mixed m;
  int i;

  if (obj_list && sizeof(obj_list)) {
    foreach (m : obj_list) {
      if (stringp(m)) {
        if ((o = present_clone(m, this_object())))  // simple clone
          destruct(o);
        continue;
      }
      // else: pointerp(m).
      i = m[1];
      if (i == POP_BLUEPRINT) {
        if ((o = find_object(m[0])))
          destruct(o);
          continue;
      }
      do {
        if ((o = present_clone(m[0], this_object()))) {
          destruct(o);
          i--;
        }
        else
          i = 0;
      } while (i > 0);
    }
  }
}

void destruct_population() {
  destruct_object_population();
  // destruct_living_population();
}

void notify_destruct() {        // cleanup. Coogan, 25-Oct-2002
  destruct_population();
}

