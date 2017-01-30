inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_light(1);
set_short("A stairwell");
set_long(
"This is the stairway to the third floor of the castle. It seems like there is a
 presence of danger lurking in the air. Looking around you see that there are a 
couple of decorations hung on the stairway rails. You also see that there are nu
merous footprints on the floor.");
add_item("rails","The hand rails are decorated for something important.");
add_item("decorations","The tinsel used for Christmas trees is hanging on the ra
ils for something important.");
add_item("footprints","The footprints are made from mud and are leading up the s
tairs.");
add_exit("/players/gohan/namek/namek23.c","south");
add_exit("/players/gohan/namek/namek25.c","up");
add_object("/players/gohan/learning/pguard.c");
add_object("/players/gohan/learning/pguard.c");
}
