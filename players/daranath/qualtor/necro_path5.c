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
     "The dark pathway continues to the east from here, leading through\n"+
     "a large bone archway that heads into the old graveyard of the\n"+
     "ruined keep. Many brave knights and lords were once buried there,\n"+
     "all fallen in service to the lord of Qual'tor.\n";

    items=({
   "archway","A large stone archway stands as the enterance of the graveyard",
   "pathway","The pathway ends here, with the graveyard to the east",
   "keep","The keep has long since been destroyed by fire",
   "graveyard","Many heroes and knights of Qual'tor were buried within this graveyard",
   "bone","A great deal of bone was used in making the archway.\n"+
       "It looks as if the bone is not as worn as the rest\n"+
       "of the area. It must be new",
    });

    dest_dir=({
     "/players/daranath/qualtor/necro_path6.c","east",
     "/players/daranath/qualtor/necro_path4.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("You find nothing of interest about the pathway.\n");
return 1;
 }

gravesite() {return "yes"; }

