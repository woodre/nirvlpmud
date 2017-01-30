#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;


long_desc =
  "    This is a tunnel made entirely of dirt.  It leads to the north\n"+
  "and south directions.  To the north there is a glimpse of light\n"+
  "coming down from a hole in the ceiling.  In the south direction you\n"+
  "can hear the sounds of ants.  The noise almost sounds like someone\n"+
  "screaming as they are being eaten alive.\n";
set_light(0);
add_listen("main", "From the south, you hear screams of pain.");
add_property("NT");

items = ({
"wall","Is made of dirt",
"floor","Is well packed dirt, very solid for walking on",
"mound","A large mound of dirt, you are located right beneath the hole into the mound",
"tunnel","A long dirt tunnel leading to the north and south",
"light","A small glimpse of light coming from the hole in the mound",
"ceiling","A ceiling made of all dirt",
"dirt","Brown normal dirt",
"hole","A small hole in the top of the mound",
});

dest_dir = ({
"/players/pestilence/amity/room/tun1.c","north",
"/players/pestilence/amity/room/tun3.c","south",
});
}

short() {
    return ""+YEL+"Dirt Tunnel"+NORM+"";
}
