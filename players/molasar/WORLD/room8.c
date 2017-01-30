
#include "std.h"

reset(arg) {
   if(arg) return;
   set_light(1);
}

init() {
   add_action("enter","enter");
   add_action("enter","west");
   add_action("up","up");
}

short() { return "A small room"; }

long() { 
   write("The mist solidifies into a room with four black walls.\n");
   write("The only source of light is a portal on the west wall.\n");
   write("   There is one obvious exit:  up\n");
}

enter() {
 if(!call_other(this_player(),"query_ghost",0) && !present("scroll", this_player())) {
     write("You cannot pass through the death portal.\n");
     return 1;
   }
   this_player()->move_player("through the light#players/molasar/WORLD/room9");
  if (call_other(this_player(), "query_ghost",0))
         call_other (this_player(), "remove_ghost", 0);
   return 1;
}

up() {
   this_player()->move_player("up#players/molasar/WORLD/room7");
   return 1;
}

