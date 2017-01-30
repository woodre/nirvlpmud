#include "../def.h"
inherit MYROOM;
reset(arg) {
  if(!present("slave")) {
    int i;
    for(i=0;i<=random(5);i++) {
      move_object(clone_object("/players/feldegast/mon/slave"));
    }
  }
  if (arg) return;
  short_desc="A mine shaft";
  long_desc=
"    The natural walls of the cave end here, and give way\n"+
"to a painstakingly carved mine shaft supported by thick\n"+
"wooden beams.  The shaft ends here near a pile of rock.\n";
  items=({
    "walls","These rough and uneven walls have been carved out\n"+
            "by pickaxes over the years",
    "pile","This is a pile of stones carved from the walls of this shaft",
    "beams","Thick wooden beams 6 feet in length by six inches, by six inches",
    "shaft","The shaft leads up and to the south at a steep angle"
  });
  dest_dir=({
    PATH+"Quad/cave9","south"

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
