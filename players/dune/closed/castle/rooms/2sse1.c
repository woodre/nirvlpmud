#include <definitions.h>
inherit "room/room";


reset(arg)
{
  if (!present("willow"))
    move_object(clone_object(CASTLEMONSTER+"/willow.c"), this_object());

  if(!arg)
  {
    set_light(1);
    short_desc="Willow trees";
    long_desc=
"     The swamp here is strangely different. Pools of water lie in\n"+
"circular formations around abnormally thick and stout trees. The trees\n"+
"are very curved and windy. Their roots shoot down into the water pools\n"+
"as if to drink from the water.\n";

    dest_dir=({
CASTLEROOM+"/2east.c","north"  ,
CASTLEROOM+"/sroad3.c","west"  ,
CASTLEROOM+"/2se1.c","northwest"  ,
    });

    items=({
"trees","     They are quite strange",
"water","     The water pools are quite deep",
    });
  }
}
