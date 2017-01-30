#include "/players/mosobp/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
set_short("The Outfield");
set_long(
"Looking around you, you see the fence a little ways behind you, and the other fielders\n"+
"in front of you. You notice a nice plush green grass growing around the outfield.\n"+
"There are a few flowers growing scattered across this part of the outfield.\n");
items = ({
"fence","Looking at the fence you seen a sign on it that says 375."
"grass","The grass all around you is a plush green color almost like it is taken care of on a regular basis."
"fielders","The other players on your team getting warmed up for the game."
"flowers","A couple of daisy scattered sporadically across this part of the outfield."});
move_object(clone_object("/players/mosobp/arena/NPC/baseball/lfield.c"), this_object());
add_exit("/players/mosobp/arena/baseball/r2.c","northeast");
}
