inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Fortress)");
    long_desc=
  "The wooden walls of the kobold keep continue through here, the majority\n"+
  "of them painted with mosaics depicting various battle scenes and\n"+
  "triumphs of the clan. A pair of steel braziers burn softly, throwing\n"+
  "dancing shadows about the area, making it seem as if the paintings\n"+
  "are alive.\n";

items=({
 "braziers", "The steel of the braziers are polished to a high shine",
 "paintings", "The paintings depict several conquests of the kobold clan,\n"+
              "fighting within the realms of Nirvana",
 "mosaics", "The mosaics show the various kings within the clan,\n"+
            "past and present",
 "walls", "Not much can be seen of the walls here, due to the paintings",
 });


dest_dir=({
 "/players/daranath/clearing/kobold_keep1.c","north",
 "/players/daranath/clearing/kobold_keep5.c","west",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the kobold fortress.\n");
say (tp +" searches the area.\n");
  return 1;
}

