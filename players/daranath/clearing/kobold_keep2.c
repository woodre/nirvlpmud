inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Fortress)");
    long_desc=
  "Long feasting tables line this room, food and drink spilled about them.\n"+
  "Torches burn smokily along the walls, giving off just enough of a burnt\n"+
  "aroma that covers the smell of rotting food. No exits are visible from\n"+
  "the room, other then the one you came in.\n";

items=({
 "tables", "Grease and blood covered, the tables run the length of the\n"+
           "hall here. Piles of rotting food and debris are all about them",
 "food", "The food is rotting and rather gross",
 "torches", "The smell of the torches masks the other smells about",
 "walls", "The same dark red wooden walls run here as in the keep",
 });


dest_dir=({
 "/players/daranath/clearing/kobold_keep1.c","south",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing within the piles of garbage.\n");
say (tp +" searches the area.\n");
  return 1;
}

