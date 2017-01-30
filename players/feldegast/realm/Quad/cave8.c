#include "../def.h"
inherit MYROOM;
reset(arg) {
  if(!present("quadrian")&&!random(2))
    move_object(clone_object("/players/feldegast/mon/quadsmith"));
  if (arg) return;
  short_desc="A mine shaft";
  long_desc=
"    The natural walls of the cave end here, and give way\n"+
"to a painstakingly carved mine shaft supported by thick\n"+
"wooden beams.  The shaft continues down and to the north\n"+
"at a steap angle.\n";
  items=({
    "walls","These rough and uneven walls have been carved out\n"+
            "by pickaxes over the years",
    "beams","Thick wooden beams 6 feet in length by six inches, by six inches",
    "shaft","The shaft continues on into the darkness"
  });
  dest_dir=({
    PATH+"Quad/cave9","north",
    PATH+"Quad/cave4","south"

  });
}   
init() {
  ::init();
  add_action("search","search");
}
search(str) {
  write("You find nothing.\n");
  return 1;
}
