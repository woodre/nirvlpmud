#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;
  short_desc = "A courtyard";
  long_desc = 
    "A large clearing is enclosed by towering castle walls.  Well worn\n"+
    "gravel pathways cut varying swaths among the well kept grass.\n"+
    "Most of the trees are well pruned and many of the bushes have been\n"+
    "trimmed in the likenesses of different animals and other fanciful\n"+
    "beasts of legend.  A tree to the west towers high into the air,\n"+
    "even dwarfing even the tall tower walls.  A large fountain rests\n"+
    "in the path of a eastward pathway, while the courtyard continues\n"+
    "opening up further north.  A passageway to the south leads back\n"+
    "inside.\n";
  set_light(1);
  add_item(,
    "");
  add_exit(ROOT+"castle/courtyard2","north");
  add_exit(ROOT+"castle/fountain","east");
  add_exit(ROOT+"castle/entry1b","south");  
  add_exit(ROOT+"castle/tree1","west");  
}
