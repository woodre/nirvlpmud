#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth (clearing)";
long_desc =
  "  A small clearing in the woods emerges out of\n"+
  "nowhere.  The ground has been neatly kept, the\n"+
  "grass is soft, and managed expertly.  The trees\n"+
  "and bushes surround the clearing into a small\n"+
  "enclosed circle.  A sign stands on one side of\n"+
  "the clearing, standing alone.\n";
items = ({
  "clearing","A meadow in the middle of the forest, encircled by trees",
  "ground","The ground is flat and soft",
  "trees","Large trees looming over head.\nThey circle the clearing into a nice area",
  "bushes","Short bushes, growing along the treeline",
  "sign","A short wooden sign staked into the ground",
});
MOCO("/players/jaraxle/3rd/warrior/mon/daize.c"),TO);
dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/shop_path2.c","out",
});
}
init() {

::init();

add_action("read","read");
}

read(arg) {             
if(arg == "sign"){
write("Daize's area.\n"+
      "This area belongs to Daize.  If you are here\n"+
      "it means one of two things: Either you wanna\n"+
      "fight, or you wanna buy my stuff.  If you're\n"+
      "interested in my stuff, just ask me about it.\n"+
      "                                      Daize.\n");
return 1; }
write("Read what?\n");
return 1; }

