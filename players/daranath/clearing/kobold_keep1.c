inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){
move_object(clone_object("/players/daranath/mons/kobold2.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold2.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold6.c"),this_object());
    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Fortress)");
    long_desc=
  "Just inside the large gate that serves the kobold fortress, flags and\n"+
  "banners of the clan hang about the area, trying to bring about a measure\n"+
  "of respect for the diminutive race. Torches are mounted within iron\n"+
  "sconces about the walls, shedding a good amount of light.\n";

items=({
 "gate", "The large wooden gateway separates the village from those\n"+
         "within the keep",
 "flags", "The colorful flags hand from the ceiling in tribute to the\n"+
          "kobold clans within the fortress",
 "banners", "The colorful banners match those of the flags within the area",
 "torches", "The torches burn smokily within the iron sconces",
 "sconces", "Wrought iron sconces hold the torches about the walls",
 "walls", "The walls are made of a deep red wood",
 });


dest_dir=({
 "/players/daranath/clearing/kobold_keep2.c","north",
 "/players/daranath/clearing/kobold_keep3.c","south",
 "/players/daranath/clearing/kobold_keep4.c","west",
 "/players/daranath/clearing/kobold7.c","exit",
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

