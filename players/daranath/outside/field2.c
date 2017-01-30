#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Fields)");
    long_desc=
  "The dirt trail continues, winding itself through the everlasting fields with\n"+
  "grass tall enough to obscure your vision. After finally breaking free\n"+
  "from the grass, you come upon a river that feeds the area, keeping\n"+
  "the land fertile. The only way across the river is a small wooden bridge.\n";

    items=({
  "bridge","A small weather worn bridge cross the river here",
  "footprints","A variety of footprints run around the area, mostly human",
  "grass","Tall yellowing grass grows in the place of crops",
  "ruins","The ruins of the city extend to the south from here",
  "field","The fields have long since been forgotten, with noone needing food",
  "fields","The fields have long since been forgotten, with noone needing food",
  "road","The packed dirt roadway narrows as it runs east from the Northgate",
  "roadway","The packed dirt roadway narrows as it runs east from the Northgate",
  "trail","The road narrows into little more then a trail leading east",
    });

    dest_dir=({
  "/players/daranath/outside/bridge.c","bridge",
  "/players/daranath/outside/field1.c","west",
    });

    }
  }

    init(){
      ::init();
  add_action("search","search");
    }

    search(){
  write("Varied footprints are the only thing that are of interest in the area.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

