#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";
int WALL;

reset(arg) {
WALL = 0;
  if(arg) return;
if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }


long_desc =
  "    This is just inside the top of a large dirt mound.  Dirt is all\n"+
  "around.  The sounds of ants scattering around can be heard in the\n"+
  "distance.  The sounds are louder from the south direction, where the\n"+
  "tunnel extends to.  To get back out someone could possibly climb out.\n";
set_light(0);
add_listen("main", "You hear that sounds of ants scattering about.");

items = ({
"wall","Is made of dirt",
"floor","Is well packed dirt, very solid for walking on",
"mound","A large mound of dirt, you are located right beneath the hole into the mound",
"dirt","Brown normal dirt",
"tunnel","A long dirt tunnel leading to the south",
"hole","A small hole in the top of the mound",
});

dest_dir = ({
"/players/pestilence/amity/room/tun2.c","south",
});
}

short() {
    return ""+YEL+"Inside the Mound"+NORM+"";
}
init() {
  ::init();
  add_action("climb_out","climb");  
}


climb_out(arg){
   if(!arg) { notify_fail("Climb where?\n");
       return 0;}
  if(arg == "out"){
    write("You climb out of the mound.\n");
    say(TPN+" climbes out of the mound!\n");
     TP->move_player("climb#/players/pestilence/amity/room/mound.c");
return 1; }
    else
{
       notify_fail("You may only climb out.\n");
       return 0;
}
}
