/* Kramer's Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Kramer's Room"+NORM;
  no_castle_flag = 0;
  long_desc=
RED+"  You cautiously step through the door to 5B and discover\n"+
"that you have found Kramer's room!  You stand in awe at not\n"+
"only the luck of being here, but the mere sight of this place.\n"+
"It is the most extraordinary room you have ever seen.  You had\n"+
"heard rumors that Kramer was a bit extravagant and flamboyant,\n"+
"but you never really expected to see a hot tub and a cigar store\n"+
"Indian (not to mention the glaring red light) in this apartment."+
NORM+"\n",

  items=
  ({
    "door","It is closed behind you",
    "indian","A six foot tall Indian, like the ones found in a cigar store",
    "tub","A large, noisy, six-person hot tub",
    "light","The light beams through the window.  It appears to be coming\n"+
         "from the Kenny Rogers Roasters across the street",
  });

  if(!present("kramer", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/kramer.c"), this_object());
  }
  if(!present("joe", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/joe.c"), this_object());
  }
}

init() {
  ::init() ;
  add_action("open","open");
}

open(arg) {
  if(!arg) {
    write("What would you like to open?\n"); return 1; }
  if(arg =="door") {
    say(capitalize(tp)+" opens the door.\n");
    mp("out the door#/players/cosmo/apt/rooms/hallway.c");
  return 1; }
  else { write("You can't open the "+arg+".\n"); return 1; }
}

