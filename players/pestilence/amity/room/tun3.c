#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;


long_desc =
  "    Dirt surrounds you here.  The entire tunnel is made of dirt.  At\n"+
  "this spot the tunnel forks.  One path leads to the southwest and the\n"+
  "other leads to the southeast.  To the north leads back to the mound\n"+
  "entrance.  The noise of the ants is even louder here.  It seems to be\n"+
  "coming from the southeast direction.\n";
set_light(0);
add_listen("main", "The screams are very loud here.");
add_property("NT");

items = ({
"wall","Is made of dirt",
"floor","Is well packed dirt, very solid for walking on",
"mound","A large mound of dirt, you are located right beneath the hole into the mound",
"tunnel","A long dirt tunnel leading to the north and splits to the southwest and southeast",
"fork","A fork in the tunnel leading to the southeast and southwest",
"path","A path leading to the southeast and southwest, both entirely made of dirt",
});

dest_dir = ({
"/players/pestilence/amity/room/tun2.c","north",
"/players/pestilence/amity/room/tunse1.c","southeast",
"/players/pestilence/amity/room/tunsw1.c","southwest",
});
}

short() {
    return ""+YEL+"Dirt Tunnel"+NORM+"";
}
