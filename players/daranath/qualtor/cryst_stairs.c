#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("crysmal")) {
move_object(clone_object(ROOT+"mon/crysmal.c"),this_object());
move_object(clone_object(ROOT+"mon/crysmal.c"),this_object());
move_object(clone_object(ROOT+"mon/crysmal.c"),this_object());
move_object(clone_object(ROOT+"mon/crysmal.c"),this_object());
move_object(clone_object(ROOT+"mon/crysmal.c"),this_object());
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "A wide stone stairwell extends down into darkness here, the vast\n"+
     "majority of the stairs covered in broken shards of crystal. Footing\n"+
     "is treacherous, one false step could drive a piece of crystal\n"+
     "into your foot. Nowhere in Qual'tor is the destruction more\n"+
     "evident then here, where the Circle once ruled from.\n";

    items=({
     "stairwell","The stairs are made from a dark grey stone",
     "darkness","The darkness hides many critters and rodents from view",
     "stairs","The stairs are made from a dark grey stone",
     "shards","The broken shards of crystal are all that remains of the tower above",
    });

    dest_dir=({
      "/players/daranath/qualtor/back.c","up",
      "/players/daranath/qualtor/cryst_land.c","down",
    });

    }
  }

    init(){
      ::init();
add_action("dar_down","down");
    }

    search(){
    write("The shards that cover the stairwell are of no value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_down() {
if(present("crysmal")) {
write("The Crysmal blocks you from heading down into the Crystalline ruins.\n");
return 1; }
return 0;
}

