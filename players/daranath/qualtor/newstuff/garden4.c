#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
if(!present("undead")) {
move_object(clone_object(ROOT+"mon/morgue_toad.c"),this_object());
move_object(clone_object(ROOT+"mon/morgue_toad.c"),this_object());
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BLK+BOLD+"Dark Graveyard"+NORM+")");
    long_desc=
     "The shadow of the ruined keep falls all about the area, continually\n"+
     "keeping the pathway in darkness. The path itself turns east from\n"+
     "this point, leading to the arched entrance of an old \n"+
     "graveyard.\n";

    items=({
"keep","The ruined keep is a sad reminder of the days of old",
 "gravel","The gravel itself is dark grey in color",
 "path","The gravel path is simple in design, leading north and south",
 "pathway","The gravel path is simple in design, leading north and south",
 "garden","The ruins of Qual'tors garden lies north",
 "lords","The Lords of Qual'tor are long since gone",
 "spot","The garden was a favorite spot of the king",
    });

    dest_dir=({
  ROOT +"garden3.c","south",
  ROOT +"garden6.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("You find nothing of interest around the archway leading into the graveyard.\n");
return 1;
 }

