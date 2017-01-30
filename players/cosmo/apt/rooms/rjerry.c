/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

object mort;
int counter;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Jerry's Room"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You arrive in Jerry Seinfeld's apartment.  Everything seems\n"+
"to be in proper order.  The kitchen is to your left, the\n"+
"bedroom and bathroom are to your right, the living room and\n"+
"dining room lie in front of you, and the door is behind you.\n"+
"It looks like Jerry isn't here.  He must be down at the cafe\n"+
"with George.  But you do notice Jerry's parents waiting for\n"+
"something impatiently.\n",

  items=
  ({
    "kitchen","Typical appliances: refrigerator, microwave, stove",
    "bedroom","It's around the corner and you can't see it from here",
    "bathroom","The door is closed.  Perhaps someone is in there",
    "living room","A large couch and TV lie in front of you",
    "dining room","A small table with some chairs around it",
    "door","It is closed",
    "couch","It looks like there is something stuffed in between the\n"+
            "the cushions.  It might be worth a closer inspection",
  });

  if(!present("morty", this_object())){
    mort = clone_object("/players/cosmo/apt/mon/morty.c");
    move_object(mort, this_object());
  }
  if(!present("helen", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/helen.c"), this_object());
  }
}

init() {
  ::init() ;
  add_action("open","open");
  add_action("check","search");
}

open(arg) {
  if(!arg) {
    write("What would you like to open?\n"); return 1; }
  if(arg !="door") {
    write("You can't open that.\n");
  return 1; }
  say(capitalize(tp)+" opens the door.\n");
  mp("out the door#/players/cosmo/apt/rooms/hallway.c");
  return 1;
}

check(arg) {
object shirt;
  if(!arg) {
    write("Perhaps you should search something in particular.\n");
  return 1; }
  if(!counter && arg=="couch") {
    shirt = clone_object("/players/cosmo/apt/armor/babyblue.c");
    if(present("morty", this_object())) {
      write("You catch a glimpse of "+BLU+"Baby Blue"+NORM+" but Morty\n"+
        "quickly grabs it before you can.\n");
      move_object(shirt,mort); }
    else {
      write("You find "+BLU+"Baby Blue"+NORM+"!!.\n");
      move_object(shirt,this_player()); }
    counter = 1;
  return 1; }
  write("You find nothing.\n");
return 1; }
