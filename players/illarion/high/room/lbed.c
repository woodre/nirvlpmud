inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Near a loft apartment bed";
  long_desc=
"You stand in the section of a loft apartment that serves as the bedroom.\n"+
"In the center of the south wall of the apartment a king-sized bed with no\n"+
"head- or footboard is flanked by two small tables.  Just west of the bed,\n"+
"a large closet with four sliding doors has been build out from the wall.\n"+
"To the north is the living area of the loft, and a darkened alcove is\n"+
"past the bed to the south.\n";
  items= ({
    "bedroom","It's not really a room, since it's not divided from the rest\n"+
              "of the apartment",
    "bed","Very large, with a number of pillows and a large comforter.  One\n"+
          "of the pillows, the only white one, attracts your attention",
    "pillow","You don't really notice anything remarkable about it, but\n"+
             "it seems to attract your "+BLD("focus")+" all the same",
    "tables","Simple bedside tables",
    "closet","Fairly attractive, with carvings in the paneled doors",
    "carvings","Fanciful depictions of carious creatures",
    "alcove","You can't be sure if it leads anywhere or not",
  });
  dest_dir= ({
    HROOM+"living","north",
    HROOM+"alcove","south",
  });
}
init() {
  ::init();
  add_action("cmd_focus","focus");
}
cmd_focus(string str) {
  if(!str || str != "on pillow") FAIL("Focus on what?\n");
  write("You stare at the pillow, focusing all your attention on it\n"+
        "for a moment.  As your attention becomes totally focused, you\n"+
        "feel a lurch, and get a sense of another time and place.\n");
  say(TPN+" stares intently at the bed for some reason.\n");
  say("Suddenly, a rift in reality opens around "+TP->query_objective()+".\n");
  TP->move_player("into the rift#"+HROOM+"abedroom");
  return 1;
}
