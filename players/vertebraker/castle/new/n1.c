#include "../../define.h"
#define PATH "/players/vertebraker/castle/new/"
inherit ROOM;

reset(arg) {
if(arg) return;
set_short("A darkened forest");
set_long(
"    Restless leaves blow carelessly around this thick patch of\n"+
"foresting.  Thick tendrils of mist rise and fall in a heart's beat,\n"+
"preventing total view of the area.  Giant trees tower above\n"+
"your head on either side of you, preventing entry to a few other\n"+
"parts of the forest.\n");
add_item("leaves",
"Rustling leaves blow around the immediate area, dusting the area\n"+
"as they crackle around");
add_item(({"tendrils","mist"}),
"The tenuous mist rises and falls quickly, and floats gloomily in\n"+
"some areas, sometimes so thick you cannot make out anything a few\n"+
"feet from you");
add_item("trees",
"They appear to be of a dark wood.  The bark is scaled and hard.\n"+
"The branches are ripe with a bounty of dark leaves");
add_exit(PATH+"n2","north");
add_exit(PATH+"n0","south"); }
