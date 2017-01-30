inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_light(1);
set_short("A stairway");
set_long(
"This is the top of the stairs, and you see the footprints picking up at the sta
irs and heading east.  You barely see a maid as she goes by to the west.");
add_item("stairs","The stairs lead back down to the second floor.");
add_item("footprints","Tracks of mud. Maybe you should follow them.");
add_item("maid","One of the Queen's servants.");
add_exit("/players/gohan/namek/namek26.c","east");
add_exit("/players/gohan/namek/namek24.c","down");
}
