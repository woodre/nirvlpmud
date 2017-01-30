inherit "room/room";
#include "definitions.h"

int closet, bed;

init() {
add_action("search","search");
::init();
}

reset(arg) {

  bed=0;
  closet=0;
  if(!present("sithi")) {
    move_object(clone_object(CASTLEMONSTER+"/desnon_lord.c"),this_object());
    }

        if(!arg) {
        closet=0;
        set_light(1);
        short_desc="Lord's room";
        long_desc=
"     The room around you is very luxurious as compared to the rest of\n"+
"the temple.  Ebony furniture and torches are abundant.  A nice wicker\n"+
"bed and a large closet line the walls.  A 6 foot tall mirror is fixed\n"+
"to the wall opposite the bed.  Wicker rugs spread across the floor.\n"+
"A large symbol of a forked tongue wrapping around a sword is hastily\n"+
"painted upon one of the walls.\n";

   dest_dir=({
        CASTLEROOM+"/guardslord.c","north"  ,
            });

   items=({
        "symbol",
"     The tongue must have been painted in quick preparation for the king.\n"+
"It looks like this room was originally the bedroom of the head priest",
        "furniture","     The furniture is simple, yet strong",
        "torches","     The torches are arranged in a straight line",
        "bed",
"     The bed is raised off the floor by wooden pegs, perhaps to keep\n"+
"away bugs",
        "mirror",
"     You look at your reflection in the huge mirror.  Suddenly, you\n"+
"glance at something moving from under the bed in the reflection.  A\n"+
"decayed hand and a grinning rotted head poke out from underneath the\n"+
"bed.  You gasp in horror.  You swirl around to face the threat, but\n"+
"it is gone.  You look back into the mirror, but no spook is seen.\n"+
"How wierd",
        "closet","     The closet is rather large for its purpose",
        "rugs","     The wicker rugs are fairly new",
   });
   }   }

search(str) {
  if (!str) {
    write("What do you search?\n");
    return 1;}
  if (str == "bed") {
    write("The bed contains nothing of interest.\n");
    return 1;}
  if (str == "closet") {
    if (closet == 0) {
    write("You uncover a secret panel, and a gleaming voulge lies inside!\n");
    move_object(clone_object(CASTLEOBJECT+"/voulge.c"),this_object());
    closet=1;
    }
    else {
    write("You find a secret panel, but it contains nothing.\n");
    }
    return 1;}
}
