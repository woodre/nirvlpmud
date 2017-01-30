#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;


long_desc =
  "    This part of the tunnel leads to the chamber of the Queen Ant.\n"+
  "The tunnel has been constructed similiar to the rest of the tunnels.\n"+
  "There is a trail of blood in the dirt leading to the southwest.  To\n"+
  "the northeast is the way back to the mound entrance.\n";
set_light(0);
add_property("NT");

items = ({
"wall","Is made of dirt",
"floor","Is well packed dirt, very solid for walking on with a "+RED+"blood"+NORM+" trail",
"dirt","Brown normal dirt",
"path","A path leading to the northeast and southwest",
"blood trail","A "+RED+"blood"+NORM+" trail on the dirt floor, leading to the southwest",
"trail","A "+RED+"blood"+NORM+" trail on the dirt floor, leading to the southwest",
"tunnel","A dirt tunnel leading back to the northeast and to the southwest",
"blood","A "+RED+"blood"+NORM+" trail on the dirt floor, leading to the southwest",
});

dest_dir = ({
"/players/pestilence/amity/room/tun3.c","northeast",
"/players/pestilence/amity/room/tunsw2.c","southwest",
});
}

short() {
    return ""+YEL+"Dirt Tunnel"+NORM+"";
}
