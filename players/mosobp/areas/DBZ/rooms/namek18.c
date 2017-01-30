inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_light(1);
set_short("A foyer");
set_long(
"This is a hallway. You see pictures of people on the walls, and you see a famil
y portrait on the wall as well.");
add_item("portrait","A family picture of King Vegeta, the queen, and prince Vege
ta.");
add_item("pictures","Pictures of Saiyan fighters who have given their lives to d
efend the kingdom.");
add_item("walls","The walls are decorated with the pictures of the great fighter
s of the past.");
add_exit("/players/gohan/namek/namek23.c","north");
add_exit("/players/gohan/namek/namek21.c","south");
}
