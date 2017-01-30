
#include "/players/molasar/rowan/room/exit.h"
#define ROOM "/players/molasar/rowan/mtn/wunder4"

reset(arg) {
   if(!arg)
     set_light(0);
}

id(str) { return str == "door"; }

short() { return "A passage underneath the mountain"; }

long(str) {
   if(str == "door") {
     write("A small metal door. ");
     if(ROOM->query_closed())
       write("It is closed.\n");
     else
       write("It is open.\n");
     return 1;
   }
   write("You are in a passage underneath the mountain.\n");
   write("A small door is to the north.\n");
   write("     There are two obvious exits:  north and south\n");
}

init() {
   add_exit("south","/players/molasar/rowan/mtn/temple");
   add_exit("north","/players/molasar/rowan/mtn/wunder4");
   add_action("close","close");
   add_action("open","open");
}

move() {
  string verb;

  verb = query_verb();
  if(verb == "south") {
    this_player()->move_player("south#players/molasar/rowan/mtn/temple");
    return 1;
  }
  if(verb == "north") {
    if(ROOM->query_closed()) {
      write("The door is closed.\n");
      return 1;
    }
    this_player()->move_player("north#players/molasar/rowan/mtn/wunder4");
    return 1;
  }
}

open(str) {
   if(!str || str != "door") 
     return;
   if(!ROOM->query_closed()) {
     write("The door is already open.\n");
     return 1;
   }
   ROOM->set_closed(0);
   write("You open the door.\n");
   say(capitalize(this_player()->query_name())+" opens the door.\n");
   return 1;
}

close(str) {
   if(!str || str != "door") 
     return;
   if(ROOM->query_closed()) {
     write("The door is already closed.\n");
     return 1;
   }
   ROOM->set_closed(1);
   write("You close the door.\n");
   say(capitalize(this_player()->query_name())+" closes the door.\n");
   return 1;
}
