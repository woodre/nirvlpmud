#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth (hidden path)";
long_desc =
  "  A dark tunnel of bushes and trees.  The ground\n"+
  "is untamed, growing with wild flowers and dark, \n"+
  "thick grass.  Twigs, branches, rocks and stones\n"+
  "litter the ground.\n";
items = ({
  "tunnel","A tunnel path made from the surrounding bushes and trees",
  "trees","Tall, thick trees growing around",
  "bushes","Short bushes, thick with foliage",
  "twigs","Twigs, which have fallen from the bushes",
  "branches","Branches, laying on the ground.\nThey must have fallen from the trees",
  "rocks","Small rocks on the ground",
  "stones","Large stones on each side of the tunnel, laying out a path",
  "flowers","Dandilions growing in tight bunches over the ground",
  "grass","The grass has not seen much wear and tear.\nThe grass is thick, and full",
  "ground","Hard ground, covered with dead leaves, old sticks, and twigs",
});
dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/roomw3.c","southeast",
  "/players/jaraxle/3rd/warrior/rooms/shop_path2.c","northwest",
});

}
