
#include "/players/molasar/rowan/room/exit.h"

int closed;

reset(arg) {
   if(!arg)
     set_light(0);
   closed = 1;
   extra_reset();
}

extra_reset() {
   object guard;
   int i;
   if(!present("guard")) {
     i = 0;
     while(i < 5) {
       guard = clone_object("players/molasar/rowan/monsters/d_guard");
       move_object(guard, this_object());
       i += 1;
     }
   }
}

set_closed(c) { closed = c; }
query_closed() { return closed; }

id(str) { return str == "door"; }

short() { return "A passage underneath the mountain"; }

long(str) {
   if(str == "door") {
     write("A small metal door. ");
     if(closed)
       write("It is closed.\n");
     else
       write("It is open.\n");
     return 1;
   }
   write("You are in a passage underneath the mountain.\n");
   write("A small door is to the south.\n");
   write("     There are two obvious exits:  south and east\n");
}

init() {
   add_exit("south","/players/molasar/rowan/mtn/wunder5");
   add_exit("east","/players/molasar/rowan/mtn/wunder3");
   add_action("close","close");
   add_action("open","open");
}

move() {
  string verb;

  verb = query_verb();
  if(verb == "south") {
    if(closed) {
      write("The door is closed.\n");
      return 1;
    }
    if(present("dragonman")) {
      write("The dragonman blocks your way.\n");
      return 1;
    }
    this_player()->move_player("south#players/molasar/rowan/mtn/wunder5");
    return 1;
  }
  if(verb == "east") {
    this_player()->move_player("east#players/molasar/rowan/mtn/wunder3");
    return 1;
  }
}

open(str) {
   if(!str || str != "door") 
     return;
   if(!closed) {
     write("The door is already open.\n");
     return 1;
   }
   closed = 0;
   write("You open the door.\n");
   say(capitalize(this_player()->query_name())+" opens the door.\n");
   return 1;
}

close(str) {
   if(!str || str != "door") 
     return;
   if(closed) {
     write("The door is already closed.\n");
     return 1;
   }
   closed = 1;
   write("You close the door.\n");
   say(capitalize(this_player()->query_name())+" closes the door.\n");
   return 1;
}

