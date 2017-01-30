inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_light(1);
set_short("A foyer");
set_long(
"This is a long hallway with pictures on both sides of the walls. Up ahead you c
an see some stairs.");
add_item("pictures","Pictures of the kings of the past.");
add_item("walls","The walls are lined with pictures on them of the kings of the 
past.");
add_item("stairs","It looks like stairs to the next floor in the castle.");
add_exit("/players/gohan/namek/namek20.c","north");
add_exit("/players/gohan/namek/namek15.c","south");
}
