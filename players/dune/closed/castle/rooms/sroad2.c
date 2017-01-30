inherit "room/room";
#include "definitions.h"


init()
{
  add_action("search","search");
  ::init();
}


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc="Southern swamp path";
    long_desc=
"     Cattails seem abundant here. You also notice there are more\n"+
"water pools here. You find yourself having to jump from one\n"+
"patch of dry land to the next. Tall green grass grows along the\n"+
"edges of the water. You hear the splashes of fish jumping in pools nearby.\n"+
"A bird caws overhead, flying under the curtain of tree branches. A thin\n"+
"layer of moisture lines the base of every tree. As you look up, the\n"+
"bark becomes dryer and lighter in color.\n";

    dest_dir=({
CASTLEROOM+"/2south1.c","east"  ,
CASTLEROOM+"/sroad3.c","south"  ,
CASTLEROOM+"/sroad1.c","north"  ,
    });

    items=({
"tracks",  "     The tracks are very faint, you will have to search",
"tree",    "     The tree has some sort of soft bark",
"pools",   "     The pools are normal water patches",
"bird",    "     You cannot identify this type of bird",
"cattails","     They stand 6 feet tall, obscuring view",
"bark",    "     It is moist and soft",
"grass",   "     The marsh grass cuts into your clothes",
    });
  }
}


search(str)
{
  if (!str)
  {
    write("Search what?\n");
    return 1;
  }
  if(str == "tracks")
  {
    write("The few tracks that are left head south.\n");
    return 1;
  }
  return 0;
}
