#include "std.h"

int found;

reset(arg) {
   if(!arg)
     set_light(1);
   found = 0;
}

object mimic;
int level, wc, ac;
string short, name, long;

init() {
   if(!present("qstob", this_player())) {
     write("You did not go by the right paths!\n");
     move_object(this_player(), "/room/church");
     return 1;
   }
   add_action("east","east");
   add_action("west","west");
}

east() {
   level = this_player()->query_level();
   short = this_player()->short();
   name = this_player()->query_real_name();

  if(found == 0) {
   mimic = clone_object("obj/monster");
   mimic->set_name(name);
   mimic->set_alias("mimic");
   mimic->set_level(level);
   mimic->set_short(short);
   mimic->set_ac(level/3);
   mimic->set_wc(level);
   mimic->set_long(short+"\nSomething doesn't seem right about this person.\n");
   call_other(mimic, "set_heal", 1, 15);
   move_object(clone_object("players/molasar/OBJ/qstob"), mimic);
   move_object(mimic, this_object());
   write("Someone steps out from behind the shadows.\n");
   say("Someone steps out from behind the shadows.\n");
   found = 1;
   return 1;
  }
  if(present("mimic")) {
    write("The mimic blocks your passage.\n");
    return 1;
  }
  this_player()->move_player("east#players/molasar/SEA/cave2");
  return 1;
}

short() { return "Entrance to a cave"; }

long() {
   write("An eerie light from an unknown source provides you with enough\n");
   write("illumination to see.  A small opening leads to the east.\n");
   write("   There are two obvious exits:  east and west\n");
}

west() {
   this_player()->move_player("west#players/molasar/SEA/isle_path3");
   return 1;
}
