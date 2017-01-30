#include <ansi.h> /* 2007-11-24 added leading # -Rumplemintz */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="A dusty road";
  long_desc="    Endlessly, the path continues southward, its monotonous\n"+
            "curves winding back and forth. There are some more scuffs in\n"+
            "the dust here. The sun has yet to lessen its assault from on\n"+
            "high. The brush still frames the path to either side, yet more\n"+
            "in some places than others, perhaps.\n";
  items=({
    "path", "The dusty path winds far to the north and south",
    "dust", "Marks that may be footprints appear here, though they could be older",
    "scuffs", "Marks that may be footprints appear here, though they could be older",
    "footprints", "Definitely footprints, and heading in a southerly direction",
    "sun",  "Large and angry red, the sun beats down upon you fiercely",
    "brush", "There is a break here to the east you might be able to enter",
    "break", "It is a small break, but you might could enter it",
  });
  dest_dir=({
    FROOM+"path2", "north",
    FROOM+"path4", "south",
  });

}

init() {
   ::init();
     add_action ("enter_break", "enter");
   }
enter_break(str) {
     if(!str) return 0;
     if(str != "break") { write("enter what?\n"); return 1;}
     if (this_player()->query_level() > 8) {
     write("You cannot quite squeeze through the break.\n");
     return 1;}
     write("You squeeze through the break in the brush and move through "+
         "to the other side.\n");
   this_player()->move_player("break#"+FROOM+"off_path1");
     return 1;
}

