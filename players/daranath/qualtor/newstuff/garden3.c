#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";
  int a, b;

reset(int arg){
  a = random(2); b = random(3);
if(a == 1) {
move_object(clone_object(ROOT+"mon/gravestorm.c"),this_object());
}
if(b < 2) {
move_object(clone_object(ROOT+"mon/morgue_toad.c"),this_object());
}
if(b == 2) {
move_object(clone_object(ROOT+"mon/frightcrawler.c"),this_object());
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
  ROOT +"garden4.c","north",
  ROOT +"garden2.c","south",
  ROOT +"garden_shrine.c","west",
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

