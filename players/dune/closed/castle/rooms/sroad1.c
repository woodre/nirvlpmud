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
    short_desc="North swamp junction";
    long_desc=
"     Dense bushes and black trees completely block off all but a\n"+
"bogs and pools lie around you. Some patches of land are raised higher\n"+
"than the water level, so travel on them is dry and relatively easy.\n"+
"You note that this will be your main way of travel in the swamp. Any\n"+
"other way would be to struggle each step in thick mud or wade through\n"+
"murky waters, and who knows what could be swimming through the waters.\n";

    dest_dir=({
CASTLEROOM+"/many_tracks.c","north"  ,
CASTLEROOM+"/1sw1.c","southwest"  ,
CASTLEROOM+"/2se1.c","southeast"  ,
CASTLEROOM+"/sroad2.c","south"  ,
    });

    items=({
"tracks","     The tracks are very faint, you will have to search",
"trees", "     The trees here grow less upwards, more sideways",
"bushes","     The bushes have many small green leaves",
"pools", "     The pools are lined with various vegetation",
"waters","     The waters are too murky to see in",
"land",  "     The land is dry on the raised areas",
"bogs",  "     The bogs are bubbling mudholes. Why do they bubble?",
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
    write("The tracks, barely discernable, head south.\n");
    return 1;
  }
  return 0;
}
