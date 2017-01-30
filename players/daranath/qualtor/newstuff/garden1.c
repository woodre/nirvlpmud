#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/frightcrawler.c"),this_object());
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BLK+BOLD+"Dark Graveyard"+NORM+")");
    long_desc=
 "A small gravel pathway leads to the remains of the once beautiful garden\n"+
 "here in Qual'tor. Tucked in alongside the keep, the garden was often visited\n"+
 "by the lords of Qual'tor, and was a favorite spot for the king himself.\n"+
 "The pathway runs north and south.\n";

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
ROOT +"garden2.c","north",
"/players/daranath/qualtor/necro_path4.c","south",
    });

    }
  }

init() {
  ::init();
add_action("search","search");
}

search() {
write("The gravel of the pathway must have been imported from somewhere else.\n");
return 1;
 }

