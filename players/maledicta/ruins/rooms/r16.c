#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
    if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/fireangel6.c"), this_object()); }
  if(arg) return;
set_light(0);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   You enter into a black room, its walls deeply scorched and melted. The\n"+
"west wall seems to be especially blasted, some of its rock still smoldering\n"+
"with a faint glow.  The tunnel leads back to the east.\n";

items = ({
  "walls",
  "As with the other areas of the tunnels they are blasted\n"+
  "and shaped by way of intense heat",
  "west wall",
  "It appears upon closer inspection that it has been\n"+
  "recently shaped by fire. It glows with a cooling heat",
  "wall",
  "It appears upon closer inspection that it has been\n"+
  "recently shaped by fire. It glows with a cooling heat"
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r15.c","east",
});

}
