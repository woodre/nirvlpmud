/*
 * obj/living.c
 *
 * New living obj
 * Rumplemintz@Nirvana
 */

#pragma strong_types

#include <filters.h>
#include <message.h>
#include <prop/item.h>

inherit "basic/vroom_object";
inherit "basic/living";
inherit "obj/living/combat";
inherit "complex/create";
inherit "basic/living/action_logic";


status can_put_and_get(string str, object inserted) {
  return !inserted;
}

void transfer_all_to(object dest) {
  object *inv;
  int i;

  for (i=sizeof(inv=all_inventory()); i-->0; ) {
    if (!inv[i])
      continue;
    if (inv[i]->query_property(P_DESTRUCT_ON_DEATH)) {
      destruct(inv[i]);
      continue;
    }
    if (!inv[i]->drop(1) && inv[i])
      move_object(inv[i], dest);
  }
}

varargs void frog_curse(status arg, int duration) {
  object frog_mark;

  if (arg) {
    if (query_frog())
      return;
    frog_mark = clone_object(FROG_MARK);
    if (duration > 0)
      frog_mark->set_curse_duration(duration);
    move_object(frog_mark, this_object());
    return;
  } else {
    while (frog_mark = present_clone(FROG_MARK, this_object()))
      destruct(frog_mark);
  }
}

varargs void run_away(status silently) {
  object here;
  string *actions;
  string *directions;
  int i, j;

  if (!here = environment())
    return;
  actions = order_alist(query_actions(this_object()));
  directions = (environment()->query_exit() || ({ ({ }) }))[0..];
  directions += ({ "north", "east", "south", "west",
                   "northwest", "northeast", "southwest",
                   "southeast", "up", "down", "out" });
  for (i=0; i<sizeof(directions); i++)
    if (assoc(directions[i], actions) < 0)
      directions[i] = 0;
  directions -= ({ 0 });
  directions = m_indices(mkmapping(directions));
  if (!sizeof(directions))
    return;
  j = random(sizeof(directions));
  for (i=0; i<sizeof(directions) && here == environment(); i++) {
    command(directions[j], this_object(), 1);
    if (++j >= sizeof(directions))
      j = 0;
  }
  if (!silently) {
    if (here == environment()) {
      send_message(({ M_SAY, M_ME_THE, M_ME_VERB, "try", " but ",
                      M_ME_VERB, "fail", " to run away." }));
      tell_object(this_object(),"Your legs tried to run away, but failed.\n");
    } else
      tell_object(this_object(),"Your legs run away with you!\n");
  }
}

void reset(status refresh) {
  "complex/create"::reset(refresh);
  "basic/living"::reset(refresh);
}

void create() {
  "obj/living/combat"::create();
  "basic/living"::create();
  "complex/create"::create();
  "basic/vroom_object"::create();
}

void configure() {
  "complex/create"::configure();
  "basic/living"::configure();
}

void heart_beat() {
  "basic/living"::heart_beat();
  "obj/living/combat"::heart_beat();
}

/////////////////////////////////////////////////////////////////////////
//
// compatibility section
//
/////////////////////////////////////////////////////////////////////////

//this is an applied lfun
void catch_msg(mixed msg, object who) {
  if (stringp(msg))
    tell_object(this_object(), msg);
  else
    map(msg, (: stringp($1)
                ? tell_object(this_object(), $1 + "\n")
                : tell_object(this_object(), "-/-\n") :));
}

void tell_others(string text) {
  object ob;

  ob = first_inventory(environment());
  while(ob) {
    if (living(ob) && ob != this_object())
      tell_object(ob, text);
    ob = next_inventory(ob);
  }
}

