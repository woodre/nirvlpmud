/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Home of the Bubble Boy"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You find yourself walking through a doorway and into the\n"+
"room of a young boy.  You see sports posters on the walls,\n"+
"a baseball glove tossed in the corner, and racing cars on the\n"+
"wallpaper.  Then suddenly you realize that half of the room is\n"+
"taken up by a large plastic bubble.  The bubble stretches from\n"+
"ceiling to floor and has an intricately engineered hole that\n"+
"allows the small boy inside to connect to the rest of the world.\n"+
"There is also a door behind you.\n",

  items=
  ({
    "bubble","It is somewhat translucent, causing the boy to appear blurry",
    "hole","The hole allows communication and the passing of objects",
    "door","It is closed behind you",
    "posters","There is one of Kenny Lofton in his old Indians uniform",
    "glove","An old beatup catcher's mit",
    "wallpaper","Cars stream across the walls in a checkered pattern",
  });

  if(!present("boy", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/bboy.c"), this_object());
  }
}

init() {
  ::init() ;
  add_action("open","open");
  add_action("a2","a2");
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

