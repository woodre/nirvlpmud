#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth (hidden path)";
long_desc =
  "  The tunnel of trees and bushes ends here abruptly.\n"+
  "The tunnel is strangely quiet, with only the sound\n"+
  "of the trees swaying above.\n";
items = ({
    "tunnel","A tunnel path made from the surrounding bushes and trees",
  "bushes","Dense bushes surround the tunnel.\nThere is a pair of dead bushes at the edge of the tunnel",
  "dead bushes","Brown, wilted bushes.\nYou think you see something on the other side.\nMaybe you should "+HIW+"dive"+NORM+" through the "+HIW+"bushes"+NORM+"",
});
dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/shop_path1.c","southeast",
});
}
init() {

::init();

add_action("dive","dive");
}

dive(arg) {             
if(arg == "bushes"){write("You dive into the bushes.\n");
say(TP->query_name()+" dives into the bushes.\n");
move_object(this_player(), "/players/jaraxle/3rd/warrior/rooms/healshop.c");
say(TP->query_name()+" crashes into the room through the bushes.\n");
command("look",TP);
return 1; }
write("Dive where?\n");
return 1; }
