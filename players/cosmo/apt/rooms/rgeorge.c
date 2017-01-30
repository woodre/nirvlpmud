/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"George's Room"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You attempt to regain your senses after that wild elevator\n"+
"ride.  At least it seems to smell nice in here.  You look at\n"+
"your surroundings and find yourself in a fairly quaint home.\n"+
"You sniff curiously and are somehow reminded of George\n"+
"Castanza.  But you know that George doesn't have his own\n"+
"place so that could only mean one thing....  You are in\n"+
"his parent's house!!!  (The door is behind you.)\n",

  items=
  ({
    "door","It is closed behind you",
  });

  if(!present("frank", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/frank.c"), this_object());
  }
  if(!present("estelle", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/estelle.c"), this_object());
  }
}

init() {
  ::init() ;
  add_action("open","open");
}

open(arg) {
  if(!arg) {
    write("What would you like to open?\n"); return 1; }
  if(arg !="door") {
    write("You can't open that.\n");
  return 1; }
  say(capitalize(tp)+" opens the door.\n");
  mp("out the door#/players/cosmo/apt/rooms/elevator.c");
  return 1;
}

