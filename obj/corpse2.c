#if 0 /* until include_dirs are fixed */
#include <mudlib.h>
inherit BASE;
#include <humanoid.h>
#else
#include "/include/mudlib.h"
inherit BASE;
#include "/include/fn/humanoid.h"
#endif


#define DECAY_TIME 120

int decay;
string killed_by;
string race;
string corpse_name;

/* prototypes */

void decay();
void remove();

void reset(status arg) {
  object corpse;
  string str;
  int i;

  if (arg) return;
  corpse = previous_object();
  corpse_name = capitalize((string)corpse->query_name(1));
  set_name("corpse");
  set_short("A corpse");
  set_long("This is the fresh corpse of " + corpse_name + ".\n");
  killed_by = (string)this_player()->query_name();
  race = (string)corpse->query_race();
  set_info("The wounding pattern indicates that " + str +
           " was killed by " + killed_by + ".\n");
  set_smell("It smells really bad!!\n");
  set_weight(((int)corpse->query_level()/3)+2); /* corpses are weighty */
  if (sscanf(file_name(this_object()), "%s#%d", str, i)) {
    call_out("decay", DECAY_TIME);
  }
}

void decay() {
  switch(++decay) {
    case 1:
      set_short("A skeleton");
      set_long("This is the skeleton of " + corpse_name + ".\n");
      set_alt_name("skeleton");
      call_out("decay", DECAY_TIME);
    break;
    case 2:
      set_short("A pile of bones");
      set_long("These bones are starched white with time.\n");
      set_name("bones");
      set_alt_name(0);
      call_out("decay", DECAY_TIME);
    break;
    case 3:
      remove();
      return;
    break;
  }
}

void remove() {
  object *inv;
  int i;

  remove_call_out("decay");
  set_weight(0);
  if (environment()) {
    inv = all_inventory();
    for (i = 0; i < sizeof(inv); i++) move_object(inv[i], environment());
    environment()->recalc_carry();  /* thus fix player */
  }
  destruct(this_object());
}

string query_killed_by()   { return killed_by; }

status can_put_and_get()   { return 1; }

status get()               { return 1; }

status prevent_insert() {
  write("The " + short(0)+ " is too big!\n");
  return 1;
}

string query_race()        { return race; }
string query_corpse_name() { return corpse_name; }

void set_race(string r)    { race = r; }
void set_corpse_name(string n) { corpse_name = n; }

void init() {
  add_action("component", "get");
}

string *components;

status component(string str) {
  object comp;

  if (!str || !race || !corpse_name) return 0;
  if (sscanf(str, "%s from corpse", str) != 1) return 0;
  if (!components) components = ({});
  if (member_array(str, components) != -1) {
    if (!present(str, this_object())) {
      write("The " + race + " has no " + str + " that is usable.\n");
      return 1;
    }
  }
  switch(str) {
    case "tooth": case "skin": case "head": case "leg": case "eye":
    break;
    case "claw":
      if (humanoid(this_object())) {
        if (!present(str, this_object())) {
          write("Humanoids don't have claws!\n");
          return 1;
        }  
      }
    break;
    case "arm": case "hair": case "finger nail": case "toe nail":
    case "hand": case "foot":
      if (!humanoid(this_object())) {
        if (!present(str, this_object())) {
          write("You can only get " + str + " from humanoids.\n");
          return 1;
        }
      }
    break;
    case "scale":
      if (!(race == "fish" || race == "dragon" || race == "snake"
         || race == "reptile")) {
        if (!present(str, this_object())) {
          write("Only fish, snakes, dragons, and reptiles have scales.\n");
          return 1;
        }
      }
    break;
    default:
      return 0;
    break;
  }
  comp = clone_object("inherit/treasure");
  comp->set_name(race + " " + str);
  comp->set_alt_name(str);
  comp->set_alias_name(lower_case(corpse_name) + " " + str);
  comp->set_weight(1);
  comp->set_value(5);
  comp->set_short(capitalize(corpse_name) + "'s " + capitalize(str));
  comp->set_long("This is a " +race+ " " +str+ " off " + corpse_name + ".\n");
  comp->set_domain_safe(1);
  if (!this_player()->add_weight(1)) {
    write("It's too heavy for you.\n");
    move_object(comp, environment());
  }
  else {
    move_object(comp, this_player());
  }
  components += ({ str, });
  write("You get the " + race + "'s " + str + ".\n");
  say(this_player()->query_name() + " gets the " + race + "'s " + str + ".\n");
  return 1;
}


