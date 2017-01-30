/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Hallway"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You stand in a hallway with a door on each side.  The\n"+
"door on the west is marked '5A' and the door on the east is\n"+
"labeled '5B'.  There is also a large button on the wall\n"+
"directly in front of you.\n",

  items=
  ({
    "door","An ordinary wooden door. It is closed",
    "button","A large white button",
  });
}

init() {
  ::init() ;
  add_action("open","open");
  add_action("push","push");
  add_action("push","press");
}

open(arg) {
  if(!arg) {
    write("What would you like to open?\n"); return 1; }
  if(arg=="door") {
    write("Please specify 'open 5a' or 'open 5b'.\n");
    return 1; }
  if(arg=="5a") { 
    say(capitalize(tp)+" opens the door.\n");
    mp("into the room#/players/cosmo/apt/rooms/rjerry.c");
    return 1; }
  if(arg=="5b") {
    say(capitalize(tp)+" opens the door.\n");
    mp("into the room#/players/cosmo/apt/rooms/rkramer.c");
    return 1; }
  else { write("You can't open that.\n"); }
  return 1;
}

push(arg) {
  if(!arg) { write("Push what?\n"); return 1; }
  if(arg !="button") { write("You can't push that.\n"); return 1; }
  write("You push the button"+NORM+".\n");
  say(capitalize(tp)+" pushes the button."+NORM+"\n");
  mp("back to the elevator#/players/cosmo/apt/rooms/elevator.c");
  return 1;
}

