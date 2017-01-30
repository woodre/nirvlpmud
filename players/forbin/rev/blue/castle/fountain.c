#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;
  short_desc = "A courtyard";
  long_desc = 
    "The gravel pathway here cuts a wide track before splitting in two\n"+
    "and travelling around a large fountain before terminating at a\n"+
    "small bench near one of the castle's walls.  The fountain, built\n"+
    "from a breathtaking red-streaked marble, is a beautiful oval shape\n"+
    "that stretches twenty or more feet in one direction and twelve or\n"+
    "so in the other.  While time has somewhat lessened its luster, the\n"+
    "water within is still oddly sparkling clear.\n";
  set_light(1);
  add_item(,
    "");
  add_item(,
    "");
  add_item(,
    "");
  add_item(,
    "");
  add_item(,
    "");
  add_item(,
    "");
  add_item(,
    "");                        
  add_exit(ROOT+"castle/courtne","north");
  add_exit(ROOT+"castle/courtyard","west");  
}

void init() {
  ::init();
  add_action("cmd_search", "search");
}

status search(string str) {
  object room;
  object obj;
  if(!str || str != "fountain") return 0;
  ROOT+"castle/infount"->make_sure_loaded();
  room = (object)find_object(ROOT+"castle/infount");
  if(present("spirit", room)) {
    write(
      "You stick your hand into the fountain and begin searching.\n"+
      "     Suddenly the water froths and churns.\n"+
      "          Something grabs you and yanks you under!\n");
    say(
      capitalize((string)this_player()->query_name())+" sticks"+
      (string)this_player()->query_possessive()+"hand into the fountain.\n"+
      "     Suddenly the water froths and churns.\n"+
      "          "+capitalize((string)this_player()->query_name())+
      "is yanked under the water.\n");
    this_player()->move_player("into the fountain#"+ROOT+"castle/infount.c");
    return 1;
  }
  say(
    "You search the "+str+", but find nothing.\n");
  return 1;
}