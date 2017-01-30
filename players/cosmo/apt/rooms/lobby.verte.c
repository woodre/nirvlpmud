/* Apartment room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  set_no_clean(1);
  short_desc="Apartment Lobby";
  no_castle_flag = 0;
  long_desc="\n"+
"You step timidly into the apartment building.  Glancing around at\n"+
"your surroundings, you realize that you stand in the front lobby of\n"+
"the building.  There is an elevator to your left and a reception desk\n"+
"in front of you.  A small note is tacked to the front of the desk.\n"+
"Behind the desk is a wall covered with colorful graffiti.  To your\n"+
"right is a large beeping and flashing screen.  Behind you is the door\n"+
"leading back outside.\n",

  items=
  ({
    "button","A small white button that calls the elevator",
    "elevator","It appears to be a standard elevator with a call button",
    "note","To gain a better appreciation of this area,\n"+
           "watch the television show "+BOLD+"Seinfeld"+NORM,
    "desk","Just a standard hotel desk.  Nothing special",
  });

  dest_dir= ({ "players/cosmo/apt/rooms/rstreet", "out", });

  if(!present("wall", this_object())){
    move_object(clone_object("players/cosmo/dc/dc_board.c"), this_object());
  }
  if(!present("screen", this_object())){
   /* new code by verte */
   object vb;
   call_other("/players/cosmo/hslist/svds_new", "???");
   vb = find_object("/players/cosmo/hslist/svds_new");
  move_object(vb, this_object());

  }
}

init() {
  ::init() ;
  add_action("a_push","push");
  add_action("a_push","press");
}

a_push(arg) {
  if(!arg) { write("Push what?\n"); return 1; }
  if(arg == "button" || arg == "call button") {
    say(capitalize(tp)+" pushes the button.\n");
    write("You push the elevator button, the doors slide open, and you\n"+
      "quickly step inside as the doors slam shut behind you.\n");
    mp("into the elevator#/players/cosmo/apt/rooms/elevator");
    return 1;
  }
  else {
    write("You push the "+arg+" and nothing happens.\n");
    return 1;
  }
}
