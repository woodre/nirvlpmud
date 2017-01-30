
#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("bird")) {
  move_object(clone_object("/players/pestilence/amity/mob/bird.c"),
        this_object()); }

if (!present("bird 2")) {
  move_object(clone_object("/players/pestilence/amity/mob/bird.c"),
        this_object()); }

long_desc =
  "    You are standing on a large branch, of a giant oak tree.  The\n"+
  "branch extends over the the street.  There are plenty of green leaves\n"+
  "protruding from the branches around you.  At the other end the branch\n"+
  "you see the backyard.  You could climb down the tree to return to the\n"+
  "yard.  Or you could jump off to get to the street.\n";
set_light(1);

items = ({
"tree","A large oak tree, maybe you could climb it",
"oak tree","A large oak tree, maybe you could climb it",
"branch","A large branch coming from a large oak tree",
"leaves","Green leaves protruding from the branches",
"backyard","A normal backyard enclosed by a wooden fence, with a large oak tree in the yard",
"street","This is a section of Madison Street",
});

dest_dir = ({

});
}


short() {
    return ""+YEL+"Tree"+NORM+"";
}

init () {
   ::init() ;
     add_action ("climb_down","climb");
     add_action ("jump_off","jump");
}

climb_down(arg) {
   if(!arg) { notify_fail("Climb where?\n");
       return 0;}
   if(arg == "down"){
     write("You climb down the tree.\n");
     TP->move_player("climb#/players/pestilence/amity/room/mad2yard.c");
  command("look",this_player());
     return 1; }
   else
{
       notify_fail("You may only climb down.\n");
       return 0;
}
}

jump_off(arg) {
   if(!arg) { notify_fail("Jump where?\n");
       return 0;}
   if(arg == "off"){
   write("You jump off the branch landing in the street.\n");
   TP->move_player("jump#/players/pestilence/amity/room/madison1.c");
     return 1; 
}
   else
{
       notify_fail("You may only jump off.\n");
       return 0;
}
}
