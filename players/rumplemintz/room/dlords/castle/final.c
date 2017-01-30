inherit "room/room";
object corridor;
#include "ex.h"
reset (int arg){
  if(!present("lord"))
    move_object(clone_object(LORD),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "Final Battle Dwarf castle";
   long_desc = "You've made it to the last room of the castle.  Here before you\n"+
              "stands the Lord Dwarven Lord, the most powerful dwarf on Nirvana.\n"+
	      "If you dare take him on, you may receive some benefits...\n"+
	      "The only obvious exit is west.\n";
  }
}
init() {
  add_action("search_room", "search");
  add_action("out", "out");
  add_action("move_west", "west");
}
move_west() {
  this_player()->move_player("west#players/rumplemintz/room/dlords/castle/room25");
  return 1;
}
search_room() {
  if(present("lord")) {
    write("You can't search while he's here! What are you thinking!\n");
    return 1;
  }
  say(capitalize(this_player()->query_name())+" searches the room frantically.\n");
  write("After a great deal of searching, you find an exit, out.\n");
  corridor = this_player();
  return 1;
}
out() {
  if(present("lord")) {
    write("What?\n");
    return 1;
  }
  if(corridor==this_player()){
    write("Your quest in the Dwarven castle is over, and you leave the castle.\n");
    this_player()->move_player("out#players/rumplemintz/room/dlords/castle/outside");
    return(1);
  }
  write("What?\n");
  return 1;
}
