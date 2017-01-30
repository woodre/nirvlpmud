#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/rguard.c"),
        this_object()); }

if (!present("ant 2")) {
  move_object(clone_object("/players/pestilence/amity/mob/rguard.c"),
        this_object()); }

if (!present("ant 3")) {
  move_object(clone_object("/players/pestilence/amity/mob/rguard.c"),
        this_object()); }


long_desc =
  "    This is a large open area within the tunnel.  This is the place\n"+
  "where all the queen's guards are usually stationed.  To the south of\n"+
  "here the tunnel leads to the queen's chamber.  There is a blood streak\n"+
  "in the dirt leading to the south.\n";
set_light(0);
add_property("NT");

items = ({
"wall","Is made of dirt",
"floor","Is well packed dirt, very solid for walking on with a "+RED+"blood"+NORM+" trail",
"dirt","Brown normal dirt",
"path","A path leading to the northeast and south",
"tunnel","A dirt tunnel leading back to the northeast and to the south",
"blood","A "+RED+"blood"+NORM+" trail on the dirt floor, leading to the south",
"blood streak","A "+RED+"blood"+NORM+" trail on the dirt floor, leading to the south",
"streak","A "+RED+"blood"+NORM+" trail on the dirt floor, leading to the south",
"chamber","A large chamber where the Queen Ant resides.",
"area","A large open area where the guards for the queen are usually stationed",
});

dest_dir = ({
"/players/pestilence/amity/room/tunsw1.c","northeast",
"/players/pestilence/amity/room/qchamber.c","south",
});
}

short() {
    return ""+YEL+"Dirt Tunnel"+NORM+"";
}
