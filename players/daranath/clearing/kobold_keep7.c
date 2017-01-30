inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){
move_object(clone_object("/players/daranath/mons/kobold6a.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold6a.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2a.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2a.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2a.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2a.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2a.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2a.c"),this_object());
    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Fortress)");
    long_desc=
  "Red carpeting extends from wall to wall within the confines of this\n"+
  "area, the deep red color matching that of the wooden walls here. A\n"+
  "pair of torches burn quietly along the walls, giving off an aura of light\n"+
  "in the room. A massive archway leads to the north, following the carpet\n"+
  "into the unknown. No other exits are apparent in here.\n";

items=({
  "carpet", "The deep red carpeting was brought in to here, stolen from\n"+
          "somewhere else",
 });


dest_dir=({
 "/players/daranath/clearing/kobold_keep8.c","north",
 "/players/daranath/clearing/kobold_keep6.c","east",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
  add_action("dar_north","north");
}

search() {
write("You find nothing within the kobold fortress.\n");
say (tp +" searches the area.\n");
  return 1;
}

dar_north() {
if(present("kobold")) {
write("A kobold steps in front of you, barking in a threatening manner.\n");
return 1; }
return 0;
}
