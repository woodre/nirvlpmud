#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Fields)");
    long_desc=
  "Tall grass surrounds you as you walk along the nothern edge of Qual'tors\n"+
  "ruins, alongside the fields that have not been tended to since the fall of\n"+
  "the city. The roadway itself narrows here, becoming little more than a dirty\n"+
  "trail leading east.\n";

    items=({
  "grass","Tall yellowing grass grows in the place of crops",
  "ruins","The ruins of the city extend to the south from here",
  "field","The fields have long since been forgotten, with noone needing food",
  "fields","The fields have long since been forgotten, with noone needing food",
  "road","The packed dirt roadway narrows as it runs east from the Northgate",
  "roadway","The packed dirt roadway narrows as it runs east from the Northgate",
  "trail","The road narrows into little more then a trail leading east",
    });

    dest_dir=({
  "/players/daranath/outside/tallgrass.c","north",
  "/players/daranath/outside/field2.c","east",
     "/players/daranath/qualtor/nor_qual1.c","west",
    });

    }
  }

    init(){
      ::init();
  add_action("search","search");
  add_action("dar_north","north");
    }

    search(){
    write("Nothing of interest lies about his empty lot.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_north(){
  if(this_player()->query_level() > 10){
write("You seem to be too high a level to continue through the grass. Why not\n"+
      "continue to the east and find something more suitable to kill.\n");
return 1; }
write("You push through the tall grass to find adventure!\n");
return 0;
}
