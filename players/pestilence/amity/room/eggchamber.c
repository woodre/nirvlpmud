#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";
int SEARCH;

reset(arg) {
  if(arg) return;

if (!present("egg")) {
  move_object(clone_object("/players/pestilence/amity/obj/egg"+random(10)+".c"),
        this_object()); }

if (!present("egg 2")) {
  move_object(clone_object("/players/pestilence/amity/obj/egg"+random(10)+".c"),
        this_object()); }

long_desc =
  "    A chamber where the queen was hiding all the eggs.  The chamber\n"+
  "is entirely made of dirt.  There is no exit from here except for\n"+
  "jumping out.  The ground here seems to be very smooth and untouched.\n"+
  "It has been quite some time since an ant or human has set foot here.\n";
set_light(0);
add_property("NT");

items = ({
"wall","Is made of dirt",
"floor","Smooth untouched dirt",
"dirt","Normal brown dirt",
"ground","The ground is all dirt and is very smooth and untouched",
"tunnel","A dirt tunnel is up from here, you must jump out to get there",
"chamber","A large chamber where the queen was hiding the eggs",
});

dest_dir = ({
});
}

short() {
    return ""+YEL+"Egg Chamber"+NORM+"";
}


init() {
  ::init();
  add_action("jump_out","jump");  
}

jump_out(arg){
   if(!arg) { notify_fail("Jump where?\n");
       return 0;}
  if(arg == "out"){
    write("You jump out of the egg chamber.\n");
    say(TPN+" jumps out of the egg chamber!\n");
     TP->move_player("climb#/players/pestilence/amity/room/qchamber.c");
return 1; }
   else
{
       notify_fail("You may only jump out.\n");
       return 0;
}
}
