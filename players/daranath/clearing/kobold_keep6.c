inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Fortress)");
    long_desc=
  "A plain wooden hallway runs between two rooms here, torches mounted\n"+
  "against the walls giving off light. A well kept red carpet runs the\n"+
  "length of the hall itself, as if it were lain here to give off a\n"+
  "sense of royalty.\n";

items=({
 "hallway", "The hallway runs east and west about the keep",
 "rooms", "The room to the west of here is carpeted in the same deep\n"+
         "red flooring. The east is a large open area, used in defense",
 "torches", "The torches are the same as in the rest of the keep",
 "carpet", "The carpet was obviously taken from somehwere else to make\n"+
          "the keep look better then it truely is",
 "light", "A soft, dancing light is given off by the torches",
 });


dest_dir=({
 "/players/daranath/clearing/kobold_keep5.c","east",
 "/players/daranath/clearing/kobold_keep7.c","west",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing within the kobold fortress.\n");
say (tp +" searches the area.\n");
  return 1;
}

