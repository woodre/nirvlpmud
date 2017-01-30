/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Newman's Room"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You slowly gather your senses and realize that you are in Newman's\n"+
"apartment.  This place is a total mess!  Clothes are scattered\n"+
"everywhere, dirty dishes lie throughout the kitchen, old news-\n"+
"papers cover the floor.  The curtains are drawn and the door is\n"+
"closed behind you, making the room dark and musty.  You smell\n"+
"moldy food in the air.  This is probably the last place you'd\n"+
"like to be right now.\n",

  items=
  ({
    "clothes","Mostly dirty postal uniforms gathering dust",
    "dishes","They have a pretty blue check pattern on them",
    "newspapers","You see one dated January 22, 1971",
    "curtains","They are closed, blocking out the sun",
    "door","The door is closed behind you",
  });

  if(!present("Newman", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/newman.c"), this_object());
  }
}

init() {
  ::init() ;
  add_action("open","open");
  add_action("read","read");
  if (present("rubble", this_object())){
    add_action("search","search");}
}

open(arg) {
  if(!arg) {
    write("What would you like to open?\n"); return 1; }
  if(arg=="door") {
    say(capitalize(tp)+" opens the door.\n");
    mp("out the door#/players/cosmo/apt/rooms/elevator.c");
    return 1; }
  else if(arg=="curtains") {
    write("The strings are all tangled and won't budge.\n");
    return 1; }
  else { write("You can't open that.\n"); }
  return 1;
}

read(arg) {
  if(!arg) {
    write("What would you like to read?\n"); return 1; }
  if(arg=="newspaper") {
    say(capitalize(tp)+" reads the paper.\n");
    write("In the lower corner of the paper you see:\n"+
      YEL+"   Today's Birth Announcement:\n"+
      RED+"              Cosmo"+NORM+"\n\n"+
      "You feel that you should remember this date for some reason.\n"); }
  else { write("You can't read that.\n"); }
  return 1;
}



