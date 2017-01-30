#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("egg sack");
  set_alias("egg");
  set_short("Egg Sack");
set_long(
"This is a large egg sack, filled with little ants.  Maybe someone could crack the egg.\n");
  set_value(500);
  set_weight(2);
}
get() { return 0; }


init () {
   ::init() ;
     add_action ("crack_egg","crack");
     }

crack_egg(str) {
if(!id(str)) { notify_fail("Crack what?\n");
 return 0; }

     write("You crack the egg open.\n"+
           "Two small ants come out of the broken egg.\n");
  move_object(clone_object("/players/pestilence/amity/obj/shell.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/amity/obj/shell.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/amity/obj/body.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/amity/mob/sant2.c"),
      environment(this_object()));
      destruct(this_object());
      return 1;
}
