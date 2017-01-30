#include "/players/wocket/closed/ansi.h"
inherit "/room/room.c";

reset(arg){
  if(arg) return;
short_desc = "Middle of a Pond";
long_desc = HIB+"WATER WATER EVERYWHERE :P .\n"+NORM;
set_light(1);
dest_dir = ({
  "/players/wocket/junk/water2.c","south",
});
}
