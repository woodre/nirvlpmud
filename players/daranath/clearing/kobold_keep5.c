inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){
move_object(clone_object("/players/daranath/mons/kobold7.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold3.c"),this_object());
    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Fortress)");
    long_desc=
  "A pair of hallways come together within this small area, while an\n"+
  "ornately carved wooden arch leads to the west from here. Nothing much\n"+
  "of note is about the area, it looks as if it was used as a strong point\n"+
  "within the fortress.\n";

items=({
 "hallways", "The hallways run north and south from here",
 "arch", "The ornatly carved archway leads to the west from here",
 });


dest_dir=({
 "/players/daranath/clearing/kobold_keep4.c","north",
 "/players/daranath/clearing/kobold_keep6.c","west",
 "/players/daranath/clearing/kobold_keep3.c","east",
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

