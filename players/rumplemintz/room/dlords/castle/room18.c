inherit "room/room";
object corridor;
#include "ex.h"
reset (int arg){
  if(!present("lord"))
    move_object(clone_object(DDLORD),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the eighteenth room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: west.\n";
  }
}
init() {
  add_action("search_room", "search");
  add_action("east", "east");
  add_action("move_west", "west");
}
move_west() {
  this_player()->move_player("west#players/rumplemintz/room/dlords/castle/room17");
  return 1;
}
search_room() {
  if(present("lord")) {
    write("You can't search while he's here! What are you thinking!\n");
    return 1;
  }
  say(capitalize(this_player()->query_name())+" searches the room frantically.\n");
  write("After a great deal of searching, you find an exit, east.\n");
  corridor = this_player();
  return 1;
}
east(){
  if(present("lord")) {
    write("What?\n");
    return 1;
  }
  if(corridor==this_player()){
    write("You travel east through the secret exit.  Your searching paid off.\n");
    this_player()->move_player("east#players/rumplemintz/room/dlords/castle/room19");
    return(1);
  }
  write("What?\n");
  return 1;
}
