/* Fixed bugs with typing funktions without argument using if (!str) in
functions climb_ladder(), climb_back(), lean_ladder(). Fangorn, 12-Aug-1993 */
/*
 *  /complex/ladder
 *  03-Sep-1993, Foslay
 *  08-Sep-1996, Mllynwrlch: new function query_holder () to find the one
 *                        who holds the ladder
 *
 *  Inheritance Disclaimer:
 *  Don't rely on the internal implementation, there are some
 *  strange pieces of code which have been patched up to do more
 *  than they were intended to do. They will be cleaned up. 
 */

#pragma strong_types

#include <prop/ladder.h>
#include <persistence.h>     // Coogan, 28-Jan-1998
#include <global_actions.h>  // Coogan, 27-Aug-2002
#include <message.h>         // Coogan, 27-Aug-2002
#include <input_to.h>        // Coogan, 30-Oct-2002

#define DOWN -1
#define END_OF_LADDER ("\n-end-of-ladder-" + object_name (this_object ()))
#define DEST load_object (prop[LA_DEST])
#define SOURCE environment (prop)
#define DESTINATION ((length) ? DEST : SOURCE)
#define MOVE_MESSAGE ((down) ? "down the ladder" : "up the ladder")
#define LADDER load_name (this_object ())

#if 0
#define SKILLS
#endif

inherit "complex/item";

void set_length(int l);
void set_carry_allowance(int c);
varargs void place_ladder(mixed where, int no_move);
varargs void remove_end_of_ladder(mixed *prop, int silent);
void ladder_move();
void create_end_of_ladder();

private string short_backup, long_backup, leaning_at;
private int length = 1, down,
        carry_allowance; /* this should be encumbrance */
                         // it is now. Coogan, 07-Jan-1999
private object held_by;
private mixed prop;

void configure() {
  item::configure();
  // persistence added, Coogan, 28-Jan-1998
  set_persistence(__FILE__, PER_KEEP_VARS, ({ "carry_allowance", "length" }));
  set_id(({ "ladder" }));
  set_length(12); /* [Demos] well, yer average ladder is about 12 feet. */
  set_carry_allowance(60000);
  set_short("a ladder");
  set_long("A simple, wooden ladder.\n");
}

void set_length(int l) {
  if (!length)
    return; /* the upper end has always length 0 */
    
  if (length < 3 || length > LA_MAX_LENGTH)
    length = 12;

  set_value(l * 3 + carry_allowance / 1500);
  set_encumbrance(l * 600); /* not that heavy but quite bulky */
  length = l;
}

int query_carry_allowance() {
  return carry_allowance;
}

void set_carry_allowance(int c) {
  carry_allowance = c;  // Coogan, 07-Jan-1999
}

void set_weight_allowance(int w) {
  carry_allowance = 2500 * w;
  set_value (length * 3 + w * 2);
}

#ifdef SKILLS
int apply_action(string type, int level, mapping arg) {
  if (type == ACTION_CLIMB)
    if (length)
      return climb_ladder(arg[E_TARGET]);
    else
      return climb_back(arg[E_TARGET]);
  return ITEM::apply_action(type, level, arg); // Coogan, 27-Aug-2002
}
#endif

int query_length() { return length; }

int query_weight_allowance() { return carry_allowance / 2500; }
     
object query_holder() {
  return held_by;
}

/*  turn this into the original ladder
 *  and get rid of the other one ...
 */
static void propagate_ladder() {
  if (length)
    return;

  length = prop -> query_length();
  prop->selfdestruct_ladder();
  place_ladder(0);
  move_object(this_object(), environment(this_object()));
}

int get() {
  if (length)   /* the original ladder */
    place_ladder (0);
  else {
    SOURCE && send_message(({ M_ROOM, SOURCE, M_PL_THE, M_PL_VERB, "take",
                              M_ME_THE, " away.\n" }));
    propagate_ladder();
  }
  return 1;
}

void set_id(mixed id)      { item::set_id(({ "\ndummy" }) + id); } 
void set_long(string str)  { item::set_long(str); long_backup = str; }
void set_short(string str) { item::set_short(str); short_backup = str; }
     
varargs void place_ladder(mixed where, int no_move) {
  if (!length)
    return;

  if (!no_move)
    if (environment(this_object()) != environment(this_player()))
      move_object(this_object(), environment(this_player()));
    
  if (where) {
    if (where == DOWN) {
      item::set_short(short_backup + " (leading down)");
      item::set_long(long_backup + "It leads down.\n");
    }
    else {
      item::set_short(short_backup + " (leaning against the " + where + ")");
      item::set_long(long_backup + "It leans against the " + where + ".\n");
    }
  }
  else {
    if (prop)
      remove_end_of_ladder (prop);
    
    item::set_short (short_backup);
    item::set_long (long_backup);
    
    prop = held_by = down = 0;
  }
}

void init() {
  item::init();
  if (length) /* the `real' ladder */
  {
#ifndef SKILLS      
    add_action ("climb_ladder", "climb");
#endif
    add_action ("lean_ladder", "lean"); 
    add_action ("lower_ladder", "lower");
    add_action ("hold_ladder", "hold");
    add_action ("kick_ladder", "kick");
  }
  else /* the upper end of the ladder */
  {
    add_action ("kick_ladder", "kick");
#ifndef SKILLS
    add_action ("climb_back", "climb");
#endif
  }
}

int climb_ladder(string str) {
  if (!str)
    return notify_fail("Climb what?\n");
  if (!id(str)) {
    if (down)
      sscanf (str, "down %s", str);
    else
      sscanf (str, "up %s", str);
    if (!id(str))
      return 0;
  }
  if (!prop) {
    if (this_player () == environment (this_object ()))
      write("But you're carrying it!\n");
    else /* notify_fail() can't be used because of the climb skill */
      write("The ladder is just lying around.\n");
    return 1;
  }
  if (held_by == this_player()) {
    write("You're no longer holding the ladder.\n");
    held_by = 0;
  }
  if (prop[LA_FLAG] &&
      (!held_by || !present(held_by, environment()))) {
    send_message(({ "as ", M_PL_THE, M_PL_VERB, "climb", " up the ladder "
                    "it slips and ", M_PL_PRONOUN, M_PL_VERB, "fall",
                    " down." }));
    place_ladder(0);
    return 1;
  }
  if (this_player()->query_carry() > carry_allowance) {
    send_message(({ "the ladder groans under ", M_PL_S, " weight." }));
    input_to("climb_callback", INPUT_PROMPT, "Do you want to proceed (y/n)? ");
    return 1;
  }
  ladder_move();
  return 1;
}

void selfdestruct_ladder() {
  down = -1;
  destruct(this_object());
}

void climb_callback(string str) {
  str = lower_case(str);
  if (str == "y" || str == "yes") {
    if (random(10)*2500 > this_player()->query_carry() - carry_allowance) {
      return ladder_move();
    }
    send_message(({ M_ROOM, ({ environment(), DESTINATION }),
                    "crack! The ladder breaks under ", M_PL_S, " weight." }));
    if (length) {
      remove_end_of_ladder(prop, 1);
      destruct(this_object());
    }
    else {
      prop->selfdestruct_ladder();
      selfdestruct_ladder(); /* silent destruct */
    }
  }
}

void ladder_move() {
  if (length) { /* this is weird, the callback is only called from one part  */
    if (stringp(prop[LA_LEN])) { /* this will be fixed with the next release */
      if (!prop[LA_LEN]->ladder_exit_hook(1, leaning_at))
        return;
    }
  }
  this_player()->move_living(MOVE_MESSAGE, DESTINATION);  
  return;
}

int lower_ladder(string str) {
  mixed old_prop;

  if (!id (str))
    return 0;

  if (down)
    return notify_fail("The ladder is already down.\n");

  old_prop = prop; 
  prop = environment(this_player())->query_property(P_LADDER_EXIT);
  if (prop) {
    if (mappingp (prop))
      prop = prop["down"];
    else if (member(prop[LA_ID], "down") == -1)
      prop = 0;
  }
  if (!prop) {
    prop = old_prop;
    return notify_fail("You can't lower the ladder.\n");
  }  
  prop += ({ 0, 0, 0 }); /* add defaults */

  if (stringp(prop[LA_LEN])) {
    if (!prop[LA_LEN]->ladder_exit_hook(0, "down")) {
      place_ladder(0);
      prop = 0;
      return 1;
    }
  }
  else if (prop[LA_LEN] > length) {
    write("This ladder is too short!\n");
    send_message(({ M_SAY, M_PL_THE, M_PL_VERB, "try", " to lower a ladder "
                    "but it is too short to reach the ground." }));
    place_ladder(0);
    prop = 0;
    return 1;
  }
  remove_end_of_ladder(old_prop);
  down = 1;
  place_ladder(DOWN);
  create_end_of_ladder();
  leaning_at = "down";

  write("Ok.\n");
  say(this_player () -> query_name () + " lowers the ladder.\n");
  send_message(({ M_ROOM, DEST, "A ladder is lowered from above." }));

  return 1;
}

int lean_ladder(string str) {
  object room, ob;
  string item;
  mixed old_prop;
    
  if (!str)
    return notify_fail("Lean what against what?\n");
  if (sscanf(str, "%s against %s", str, item) < 2 &&
      sscanf(str, "%s at %s",      str, item) < 2 &&
      sscanf(str, "%s on %s",      str, item) < 2)
       // added case 'on' Alfe 2004-Jun-21
    return 0;
  if (!id(str))
    return 0;

  old_prop = prop; 
  
  if (ob = present(item, room = environment(this_player())))
    prop = ob->query_property(P_LADDER_EXIT);

  if (!ob || !prop)
    prop = room->query_property(P_LADDER_EXIT);

  if (prop) {
    if (mappingp(prop))
      prop = prop[item];
    else if (member(prop[LA_ID], item) == -1)
      prop = 0;
  }
  if (!prop) {
    if (!ob && !room->id(item))
      notify_fail("There is no " + item + " here.\n");
    else
      notify_fail("You can't lean the ladder against the " + item + ".\n");
    prop = old_prop;
    return 0;
  }
  prop += ({ 0, 0, 0 }); /* add defaults */

  if (stringp(prop[LA_LEN])) {
    if (!prop[LA_LEN]->ladder_exit_hook(0, item)) {
      place_ladder(0);
      prop = 0;
      return 1;
    }
  }
  else if (prop[LA_LEN] > length) {
    write("This ladder is too short!\n");
    send_message(({ M_SAY, M_PL_THE, M_PL_VERB, "try", " to lean a ladder "
                    "against " + item + " but the ladder is too short!" }));
    place_ladder(0);
    prop = 0;
    return 1;
  }
  remove_end_of_ladder(old_prop);
  down = 0;
  place_ladder(item);
  create_end_of_ladder();
  leaning_at = item;

  write ("Ok.\n");
  message(({({ M_SAY, M_PL_THE, M_PL_VERB, "lean", " the ladder against the " +
               item + "." }),
            ({ M_ROOM, DEST,
               "A ladder is leaned against the " + item + " from below." })}));
  return 1;
}

int hold_ladder(string str) {
  if (!id (str))
    return 0;

  if (held_by && present(held_by, environment()))
    return notify_fail(({({ M_WRITE, "But ", M_THE, held_by, M_VERB, "be",
                            held_by, " is already holding the ladder." })}));
  held_by = this_player();
  write("Ok.\n");
  send_message(({ M_PL_THE, M_PL_VERB, "hold", " the ladder." }));
  return 1;
}

varargs void remove_end_of_ladder(mixed *prop, int silent) {
  object ob;

  if (!pointerp(prop))
    return;

  if (ob = present(END_OF_LADDER, DEST)) {
    if (!silent)
      send_message(({ M_ROOM, DEST, "The ladder disappears." }));
    ob->selfdestruct_ladder();
  }
}

void create_end_of_ladder() {
  object ob;

  if (!(ob = present(END_OF_LADDER, DEST))) {
    ob = clone_object(LADDER);
    ob->set_end_of_ladder(END_OF_LADDER, query_id()[0..],
          down, this_object(), short_backup, long_backup, carry_allowance);
    move_object(ob, DEST);
  }
}

void notify_destruct() {
  if (!length) { /* Notify the original ladder */
    if (down != -1) { /* -1 = regular destruct */
      send_message(({ M_ROOM, SOURCE, "The ladder is illuminated by a strange "
                      "green light and falls down." }));
      prop->place_ladder(0);
    }
  }
  else if (down != -1)
    remove_end_of_ladder(prop); /* Remove the upper end of the ladder */
}

/* Functions used by the upper end of a ladder */

void set_end_of_ladder(string lid, string *id, int d, mixed other,
                       string short, string long, int carry) {
  length = 0; /* make this the upper end */

  id[0] = lid;
  item::set_id(id);
  down = 1 - d;
  prop = other;
  long_backup = long;
  short_backup = short;
  item::set_short(short + (down ? " (leading down)"  : " (leading up)"));
  item::set_long (long +  (down ? "It leads down.\n" : "It leads up.\n"));
  carry_allowance = carry;
}

int climb_back(string str) {
  if (!str)
    return notify_fail("Climb what?\n");
  if (!id(str)) {
    if (down)
      sscanf(str, "down %s", str);
    else
      sscanf(str, "up %s", str);
    if (!id(str))
      return 0;
  }
  if (this_player()->query_carry() > carry_allowance) {
    send_message(({ "the ladder groans under ", M_PL_S, " weight." }));
    input_to("climb_callback", INPUT_PROMPT, "Do you want to proceed (y/n)? ");
    return 1;
  }

  if (prop) {
    ladder_move();
    return 1;
  }
  else
    write("The lower end of the ladder has disappeared against the laws of "
          "physic. Please contact a wizard and tell Hermes to help you.\n");
  return 1;
}

int kick_ladder(string str) {
  if (!id(str))
    return 0;

  if (!prop)
    return notify_fail("Why should you do that?\n");
  send_message(({ M_SAY, M_PL_THE, M_PL_VERB, "kick", " the ladder down." }));
  if (length) {
    send_message(({ M_ROOM, DEST,
                    M_PL_THE, M_PL_VERB, "kick", " the ladder down." }));
    if (down) { /* let's fall down to the dest room */
      move_object(this_object(), DEST);
      remove_end_of_ladder(prop, 1); /* remove silently */
      prop = 0;
    }
    place_ladder(0, 1);
    write("Ok.\n");
  }
  else {
    send_message(({ M_ROOM, SOURCE,
                    M_PL_THE, M_PL_VERB, "kick", " the ladder down." }));
    if (down)
      prop->place_ladder(0, 1); /* let's vanish */
    else {
      propagate_ladder(); /* let's turn into the real ladder */
      write("Ok.\n");
    }
  }
  return 1;
}

