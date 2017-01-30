/* Help provided by The Great Jaraxleio */
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

if (!present("ant 2")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }

if (!present("ant 3")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }


long_desc =
  "    This is a dark basement with a cement floor and block walls.\n"+
  "The hole you jumped down from is too high up to climb back out.\n"+
  "The floor has a small covering of water.  In the northeast corner\n"+
  "there is a work bench.\n";
set_light(0);

items = ({
"wall","A block wall that seems a bit loose, and could be pushed",
"walls","The walls are made of blocks, with some of the blocks on the south wall lose.  Maybe you could push it",
"floor","A moist cement floor",
"water","A thick layer of water laying on the floor",
"corner","In the northeast corner there is a work bench",
"covering","A thick layer of water laying on the floor",
"bench","A wooden work bench in the northeast corner",
"work bench","A wooden work bench in the northeast corner",
"hole","A small hole in the floor of the room above.  It is too high to get back out that way",
"cement","The floor is made of gray cement",
});

dest_dir = ({

});
}

short() {
    return ""+BLU+"Basement"+NORM+"";
}
init() {
  ::init();
  add_action("push_wall","push");
  add_action("climb_out","climb");  
}

push_wall(arg){          
  if(!arg) { notify_fail("Push what?\n");
     return 0;}
  if(arg == "wall"){
    if(WALL == 1) { write("The wall has already been pushed.\n"); return 1; }
    write("You walk up to the wall and push with all your might.\n"+
          "The wall appears to move and makes it possible for you to climb out.\n");
WALL +=1;return 1; }
  else
{
    notify_fail("You may only push the wall.\n");
     return 0;}
}

climb_out(arg){
  if(!arg) { notify_fail("Climb where?\n");
     return 0;}
  if(arg == "out"){
    if(WALL == 0) return 0;
    write("You climb out of the basement.\n");
    say(TPN+" climbs out of the basement!\n");
 move_object(this_player(), "/players/pestilence/amity/room/mad2yard.c");  
  command("look",this_player());
return 1; }
  else
{
    notify_fail("You may only climb out.\n");
     return 0;}
}
