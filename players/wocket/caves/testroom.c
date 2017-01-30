#include "/players/wocket/closed/ansi.h"
#define resetlog "/players/wocket/caves/resetlog"
inherit "/room/room.c";

reset(arg){
move_object(clone_object("/players/wocket/turtleville/OBJ/mstaff.c"),this_object());
move_object(clone_object("/players/wocket/mushrooms/nonge.c"),this_object());
write_file(resetlog,"reset called-> "+ctime()+"\n");
if(arg) return;
short_desc = "A room";
long_desc = "A testroom.\n";
set_light(1);
}
