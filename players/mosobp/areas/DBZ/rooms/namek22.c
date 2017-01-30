inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_light(1);
set_short("A royal hallway");
set_long(
"This is the hallway leading to the chamber of King Vegeta. The footprints seem 
to have stopped here, maybe because the guards have cleaned them up.");
add_item("footprints","There are no footprints. The guards cleaned them up.");
add_item("hallway","Strung along this end of the hallway are maps of the planets
 Vegeta has conquered.");
add_item("maps","Planets that have been conquered by King Vegeta and his son Veg
eta jr..");
add_exit("/players/gohan/namek/namek25.c","west");
add_exit("/players/gohan/namek/namek27.c","north");
add_object("/players/gohan/learning/pguard2.c");
add_object("/players/gohan/learning/pguard2.c");
}
