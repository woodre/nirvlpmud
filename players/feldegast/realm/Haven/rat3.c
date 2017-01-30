#include "../def.h"
inherit MYROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A rooftop";
  long_desc=
"     This is the rooftop of a fair sized building in the\n"+
"city of Haven.  A wooden plank leads to the building to\n"+
"the south, while a wooden staircase appears to be the only\n"+
"way down into the building.\n";
  items=({
    "rooftop","It is a flat tar surface with a slight slope marred only\n"+
              "by a stairwell leading down into the building",
    "plank","It looks sturdy enough to hold your weight",
    "staircase","It appears to have been repaired recently, unlike the\n"+
                "rest of this area",
  });
  dest_dir=({
    PATH+"Haven/rat2","back",
    PATH+"Haven/rat4","down"
  });
}   
init() {
  ::init();
  add_action("cmd_jump","jump");
  add_action("smell","smell");
}
smell() {
  write("The air up here is relatively fresh.\n");
  return 1;
}
cmd_jump(str) {
  write("It is too far to jump to any other buildings.\n");
  return 1;
}
