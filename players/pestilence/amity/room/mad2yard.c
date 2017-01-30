#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }

long_desc =
  "    This is a normal backyard with a fence all the way around it.\n"+
  "The back door to the house is boarded up and there is no gate in the\n"+
  "fence.  The grass is mostly dead, with a few blades that are green.\n"+
  "The fence is five feet tall and made of wood.  There is a tree in\n"+
  "northwest corner of the yard\n";
set_light(1);

items = ({
"tree","A large oak tree, maybe you could climb it",
"fence","A wooden fence painted white, extending from the house all the way around the yard and ending back at the house",
"door","The door to the house is boarded up",
"back door","The door to the house is boarded up",
"grass","Most of the grass is brown and dead with a few green spots scattered in the brown spots",
"yard","A brown yard, with a wooden fence around it",
"large oak tree","A large oak tree, maybe you could climb it",
"house","An abandoned house with the door and windows boarded up",
});

dest_dir = ({

});
}

short() {
    return ""+BLU+"Backyard"+NORM+"";
}

init() {
  ::init();
  add_action("climb_tree","climb");  
}

climb_tree(arg) {
   if(!arg) { notify_fail("Climb where?\n");
       return 0;}
   if(arg == "tree"){
     move_object(this_player(), "/players/pestilence/amity/room/tree.c"); 
     write("You grab onto a branch and pull yourself up the tree.\n"+
           "You have just climbed into the tree.\n");
  command("look",this_player());
     return 1;}
  else
{
       notify_fail("You may only climb the tree\n");
       return 0;
}
}
