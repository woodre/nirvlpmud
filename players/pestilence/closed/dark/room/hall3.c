#include "/players/pestilence/define.h"
#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";
int OPEN;

reset(arg) {
  if(arg) return;

long_desc =
"    The large cave ends here.  On the north there is a wall of stone,\n"+
"just like there is to the east and west.  This is a room where many\n"+
"members of the Dark Order have left stuff behind, for the benefit\n"+
"of their guild mates.  If someone removes stuff from this room it\n"+
"would be most beneficial if they replaced it before they leave.\n";
set_light(0);

items = ({
"rock","Large rocks that surround everything",
"rocks","Large rocks that surround everything",
"cave","A large cave leading into the ground",
"tunnel","A dark tunnel leading to the north and south",
});

dest_dir = ({
  "/players/pestilence/closed/dark/room/hall2.c","south",
});
   no_castle_flag = 1;
} 
short() {
    return ""+HIK+"Dark Cave"+NORM+"";
}

realm() { return "NT"; }
init() {
  ::init();
     this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
