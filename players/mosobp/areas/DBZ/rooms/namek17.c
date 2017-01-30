inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_light(1);
set_short("A stairway");
set_long(
"This is the top of the stairs. Looking ahead you notice some stairs.");
add_item("stairs","The stairs up ahead of you are probably to the third floor.")
;
add_exit("/players/gohan/namek/namek22.c","north");
add_exit("/players/gohan/namek/namek20.c","down");
}
