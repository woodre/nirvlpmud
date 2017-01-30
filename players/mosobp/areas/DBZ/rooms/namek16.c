inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
    set_light(1);
    set_short("A stairwell");
    set_long(
      "Looking around you see the stairs leading upwards to the next floor of th
e castle, and you notice that when you step on a stair it creaks like an old doo
r.");
    add_item("stairs","Lead to the second floor.");
    add_object("/players/gohan/learning/pguard.c");
    add_object("/players/gohan/learning/pguard.c");
    add_exit("/players/gohan/namek/namek19.c","south");
    add_exit("/players/gohan/namek/namek21.c","up");
}
