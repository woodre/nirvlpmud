inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_light(1);
set_short("A foyer");
set_long(
"There are pictures on the walls, and on one wall you notice a picture of a man 
named Bardock. Beside his picture you see nothing but wall for a few feet on bot
h sides.");
add_item("bardock","A tall man with black wavy hair. You can tell by his build h
e is powerful.");
add_item("walls","The walls are strung with pictures.");
add_item("wall","The wall is strung with pictures.");
add_item("picture","Pictures of family vacations.");
add_item("pictures","Pictures of family vacations.");
add_exit("/players/gohan/namek/namek22.c","south");
add_exit("/players/gohan/namek/namek24.c","north");
}
