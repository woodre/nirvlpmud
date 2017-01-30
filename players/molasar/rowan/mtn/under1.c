
/*
 * First guard room under the mountain.
 * The lever must be in the 'up' position to prevent springing
 * the trap in (under3.c).
 */

#include "/players/molasar/rowan/room/exit.h"

int down;

reset(arg) {
   if(!arg)
     set_light(0);
   down = 1;
   extra_reset();
}

extra_reset() {
   object guard, mage;
   int i;
   
   if(!present("dragonman")) {
     i = 0;
     while(i < 2) {
       guard = clone_object("players/molasar/rowan/monsters/d_guard");
       move_object(guard, this_object());
       i += 1;
     }
     mage = clone_object("players/molasar/rowan/monsters/d_mage");
     move_object(mage, this_object());
   }
}

id(str) { return str == "lever" || str == "hole" || str == "bunk" ||
                 str == "bunks" || str == "ladder" || str == "cloth" ||
                 str == "trash" || str == "debris"; }

short() { return "A Guard Post Under the Mountain"; }
   
long(str) {
   if(str == "lever") {
     if(down)
       write("The lever is down.\n");
     else
       write("The lever is up.\n");
     return 1;
   }
   if(str == "cloth") {
     write("As you reach forward to touch the cloth you find\n"+
           "that the area behind it is hollow.  Moving it aside\n"+
           "you discover a lever.\n");
     return 1;
   }
   if(str == "bunk" || str == "bunks") {
     write("These could barely be called bunks.  Straw filled\n");
     write("matresses supported by rickety wood planks.\n");
     return 1;
   }
   if(str == "ladder" || str == "hole") {
     write("A sturdy wooden ladder leads down the hole into darkness.\n");
     return 1;
   }
   if(str == "debris" || str == "trash") {
     write("You search through the refuse but find nothing of interest.\n");
     return 1;
   }
   write("You are at a guard post near the entrance of the mountain.\n");
   write("Small rackety bunks serve as beds to each of the shifts.\n");
   write("A large amount of debris and trash lies in the corner,\n");
   write("while a dirty cloth hangs on the western wall.\n");
   write("The mountain entrance is to the northeast, while near the\n");
   write("southern wall you notice a hole with a ladder sticking out.\n");
   write("     There are two obvious exits:  northwest and down\n");
}


init() {
   add_exit("northwest","/players/molasar/rowan/mtn/alcove");
   add_exit("down","/players/molasar/rowan/mtn/under2");
   add_action("pull_lever","pull");
}

pull_lever(str) {
   if(!str)
     return;
   if(str == "lever") {
     if(down) {
       write("You pull the lever up.\n");
       say(capitalize(this_player()->query_name())+" pulls the lever up.\n");
       down = 0;
     } else {
       write("You pull the lever down.\n");
       say(capitalize(this_player()->query_name())+
                                          " pulls the lever down.\n");
       down = 1;
     }
     return 1;
   }
   return;
}

query_down() { return down; }

move() {
  string verb;

  verb = query_verb();
  if(verb == "down") {
    if(present("dragonman")) {
      write("The dragonman blocks your way.\n");
      return 1;
    }
    this_player()->move_player("down#players/molasar/rowan/mtn/under2");
    return 1;
  }
  if(verb == "northwest") {
    this_player()->move_player("northwest#players/molasar/rowan/mtn/alcove");
    return 1;
  }
}


