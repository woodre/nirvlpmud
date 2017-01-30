inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){
move_object(clone_object("/players/daranath/mons/kobold8.c"),this_object());
move_object(clone_object("/players/daranath/mons/panther.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold7.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold7.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold7.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold7.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Throne Room)");
    long_desc=
  "The red carpeting leads into this room, extending in a walkway up\n"+
  "to a large black throne. Large, wooden tables parralel the carpeted\n"+
  "path, room enough for twenty or thirty individuals to sit on each\n"+
  "table. Behind the throne, a large tapestry hangs along the far wall.\n"+
  "The only exit remains to the south.\n";

items=({
 "carpet", "The carpet was obviously taken from somewhere else to make\n"+
           "the keep look better then it truely is",
 "tapestry", "The tapestry is a stunning mosaic of color, with a setting\n"+
             "sun against a field of gray",
 "path", "The carpeted path leads from the southern doorway to the\n"+
         "wooden throne",
 });


dest_dir=({
 "/players/daranath/clearing/kobold_keep7.c","south",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the throne room.\n");
say (tp +" searches the area.\n");
  return 1;
}

