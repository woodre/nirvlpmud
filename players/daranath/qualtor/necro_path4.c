#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("gravemon")) {
move_object(clone_object(ROOT+"newstuff/mon/morgue_toad.c"),this_object());
move_object(clone_object(ROOT+"newstuff/mon/frightcrawler.c"),this_object());
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
   "shadow","The shadow of the ruined keep bathe the area in darkness",
   "keep","The ruined keep is a sad reminder of the days of old",
   "archway","The archway lies to the east of your location",
   "graveyard","The pathway leads east into an old graveyard.\n"+
        "Many Qual'tor heroes were once buried there",
   "entrance","A stone archway leads into the old graveyard",
   "darkness","The dark can hide many enemies from view",
    });

    dest_dir=({
  ROOT+"newstuff/garden1.c","north",
  ROOT+"necro_path3.c","south",
  ROOT+"necro_path5.c","east",
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
