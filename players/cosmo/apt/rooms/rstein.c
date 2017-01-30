/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Steinbrenner's Office"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You cautiously glance around and find yourself in\n"+
"George Steinbrenner's office.  That's right, you are in\n"+
"the office of the famous owner of the New York Yankees\n"+
"baseball team, who is coincidently the boss of George\n"+
"Castanza.  You stand in the center of the large, plush\n"+
"office.  A huge mohogany desk lies in front of you, while\n"+
"a set of oak doors towers behind you.  Large plants adorn\n"+
"each side of the desk, and the walls are covered with\n"+
"pictures of past moments in Yankee history.\n",

  items=
  ({
    "doors","The doors are closed",
    "desk","Perhaps the largest desk you have even seen",
    "plants","Large tropical plants in pristine condition",
    "pictures","A picture of Mickey Mantle catches your eye",
  });

  if(!present("steinbrenner", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/stein.c"), this_object());
  }
}

init() {
  ::init() ;
  add_action("open","open");
}

open(arg) {
  if(!arg) {
    write("What would you like to open?\n"); return 1; }
  if(arg=="door" || arg=="doors") {
    if (present("freedom key",this_player())) {
      say(capitalize(tp)+" unlocks and then opens the doors.\n");
      mp("out between the doors#/players/cosmo/apt/rooms/elevator.c");
    }
    else { write("The doors are firmly locked shut.  You need the key.\n"); }
  }
  else { write("You can't open that.\n"); }
  return 1;
}


