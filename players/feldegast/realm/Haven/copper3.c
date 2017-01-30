#include "../def.h"
inherit MYROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Copper Street";
  long_desc=
"     The surrounding buildings are among the oldest in the\n"+
"city.  Once proud tributes to their resident's prosperity\n"+
"are now tragic derelicts abandoned to the ravages of time.\n"+
"A sickening stench emanates from a two-story building near\n"+
"the end of the street.\n";
  items=({
    "buildings","Most of the buildings in this area range from two\n"+
                "to three stories in height",
    "building","The building's doors and windows are boarded up, but\n"+
               "closer inspection reveals a lose board over a window\n"+
               "which you could use to enter the building"
  });
  dest_dir=({
    PATH+"Haven/copper2","east",
  });
}   
init() {
  ::init();
  add_action("cmd_enter","enter");
  add_action("cmd_smell","smell");
}
smell() {
  write("It smells like something died nearby.  Maybe several somethings.\n");
  return 1;
}
cmd_enter(str) {
  if(str && str=="building") {
    write("You shift aside a board and enter the building.\n");
    say(this_player()->query_name()+" shifts aside a board and enters the building.\n");
    move_object(this_player(),PATH+"Haven/rat1");
    command("look",this_player());
    return 1;
  }
  notify_fail("Enter what?\n");
}

