#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc =
        "  The path ends abruptly at the base of the Dark Pyramid.\n"+
        "The trees of the forest wilt heavilly away from the pyramid\n"+
        "and the ground is grass free.  An aura of great evil can be\n"+
        "felt spewing from an open doorway of the pyramid.\n";
items = ({
  "path","A dirt path leads through the forest",
  "pyramid","A looming Dark Pyramid at the end of the forest",
  "forest","All of the foliage in the area seems from death, to near death",
  "trees","Large oak trees that bend away from the pyramid",
  "ground","As the forest reaches the pyramid, the grass stops growing",
  "aura","A wavy aura around the pyramid",
  "doorway","A dark doorway at the base of a pyramid you can "+BLK+BOLD+"enter"+NORM+"",
});

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/pyr_path3.c","north",
});

}

init() {

::init();

add_action("enter","enter");

}
enter(arg){
if(arg == "doorway" || arg == "pyramid") {
write("\n[ "+HIC+"Do not forget the "+HIW+"<"+HIG+"j_help"+HIW+">"+HIC+" commands work everywhere . . ."+NORM+" ]\n");
write("\n"+BLK+BOLD+"Evil"+NORM+" invades your body as you enter the pyramid.\n");
this_player()->move_player("into the pyramid#/players/jaraxle/3rd/pyramid/rooms/room");
return 1; }
notify_fail("Enter what?\n"); return 0; }

