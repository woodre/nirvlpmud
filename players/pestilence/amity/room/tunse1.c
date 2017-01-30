#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/worker.c"),
        this_object()); }
if (!present("ant 2")) {
  move_object(clone_object("/players/pestilence/amity/mob/worker.c"),
        this_object()); }
if (!present("ant 3")) {
  move_object(clone_object("/players/pestilence/amity/mob/worker.c"),
        this_object()); }
if (!present("pile")) {
  move_object(clone_object("/players/pestilence/amity/obj/pile.c"),
        this_object()); }

long_desc =
  "    The tunnel comes to a dead end here.  It looks like this is where\n"+
  "some of the human bodies were taken to, and then devoured.  The dirt\n"+
  "on the floor is muddied in blood.  The wall has barely legible\n"+
  "scratches hacked into it.  The tunnel heads back to the northwest.\n";
set_light(0);
add_property("NT");

items = ({
"wall","Is made of dirt with some wierd scratches in it",
"floor","Is well packed dirt, very solid for walking on with some "+RED+"blood"+NORM+"stains",
"mound","A large mound of dirt, you are located right beneath the hole into the mound",
"dirt","Brown normal dirt",
"path","A path leading to the northwest",
"tunnel","A dirt tunnel leading back to the northwest",
"scratches",""+HIK+"!-! !_! /\\/\\ /-\\ |\\|   "+HIR+"|) | E"+NORM+"",
"blood",""+RED+"Blood"+NORM+" stains on the dirt floor",
});

dest_dir = ({
"/players/pestilence/amity/room/tun3.c","northwest",
});
}
short() {
    return ""+YEL+"Dirt Tunnel"+NORM+"";
}
