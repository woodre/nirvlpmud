/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Elaine's Room"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You arrive in a brightly lit and well-decorated room.\n"+
"There is a couch in the center and flowers on the end table\n"+
"next to it.  A large door with a hanging wreath on it exists\n"+
"behind you.  This is obviously a woman's room judging by the\n"+
"decor.  Hmm... only one lady comes to mind -- Elaine!\n"+
"\n",

  items=
  ({
    "couch","It looks very soft and comfortable",
    "flowers","They are in full bloom and smell delightful",
    "table","It is a square table made of oak",
    "wreath","A hand-woven wreath of pine needles",
    "door","It is closed behind you",
  });

  if(!present("elaine", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/elaine.c"), this_object());
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

