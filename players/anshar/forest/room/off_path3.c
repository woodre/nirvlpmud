#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="Wilderness trail";
  long_desc="     Close ahead, the dark forest looms, and an eerie silence\n"+
            "presides over the entire area. A chill runs up your spine as you\n"+
            "contemplate entering into the dark woods.\n";
  items=({
    "forest", "The trees are directly ahead. They appear dark and twisted",
    "woods", "The trees are directly ahead. They appear dark and twisted",
    "path", "Winding into the darkness beneath the trees is a narrow path",
    "sun",  "Large and angry red, the sun beats down upon you fiercely",
    "trees", "The trees are directly ahead. They appear dark and twisted",
  });
  dest_dir=({
    FROOM+"off_path2", "west",
  });

}

init() {
   ::init();
     add_action ("enter_woods", "enter");
   }
enter_woods(str) {
     if(!str || str != "woods") { notify_fail("Enter what?\n");
     return 0; }
     if (this_player()->query_level() > 8) {
     write("You have no desire to enter.\n");
     return 1;}
     write("You enter the darkened woods, evil seems to"+
        " assail you from all sides.\n");
     this_player()->move_player("into the woods#"+FROOM+"newforest1");
     return 1;

}

realm() {return "NT"; }

