#include <ansi.h>

#define NAME "Dragnar"
#define DEST "room/sunalley2"

id(str) { return str == "castle" || str == "portal"; }

short() {
return "A portal of "+HIBLK+"Mirrors"+NORM;
}

long() {
write("Light is distorted as it enters the portal and warps the images\n\
within. You can see glimpses of a land of "+HIR+"Death"+NORM+" and destruction.\n\
You also can catch images of a more peaceful forest area that seems\n\
wrong somehow. The Portal can be entered, but it also draws itself\n\
to be touched.\n");
}

init() {
  add_action("enter", "enter");
  add_action("touch", "touch");
}

enter(str) {
  if (!id(str))
	  return 0;
	
  write("You feel yourself flying through space and time.\n\n");
  this_player()->move_player("into the portal#players/dragnar/WasteLands/rooms/entrance.c");
  return 1;
}

touch(str) {
  if (!id(str))
	  return 0;
	
  write("You touch the portal and are sucked into it!\n\n");
  this_player()->move_player("into the portal#players/dragnar/WalkingDead/rooms/entrance.c");
  return 1;
}

reset(arg) {
  object qob;

  if (arg)
	  return;
  
  move_object(this_object(), DEST);
  
  /** Initialize Auto Load Objects **/
  call_other("/players/dragnar/closed/scar.c", "???");
  call_other("/players/dragnar/MKScar/scar.c", "???");
  /** Initalize Daemons **/
  
  if(!present("waste_lands", find_object("room/quest_room.c"))) {
    qob = clone_object("obj/quest_obj");
    call_other(qob, "set_name", "waste_lands");
    call_other(qob, "set_hint", "Stop the Cult from gaining power.\n"+
   "Go into the past and save the Wastelands.\n"+
   "Talk to Tyme for more information.\n");
    move_object(qob, "room/quest_room");
  }
}

is_castle(){ return 1; }

