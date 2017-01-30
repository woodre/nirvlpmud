#include "/players/feldegast/defines.h"

inherit ROOM;

reset(arg) {
  if(arg)return;
  set_light(1);
  short_desc="The place between worlds";
  long_desc=
"  You are hurtling through a strange, starry void, adrift on the ocean of\n"+
"space and time.  There is no air here, and no warmth.  Colorful streams\n"+
"and pools of opaque light, glimpses of strange landscapes pass you as you\n"+
"hurtle through the place between worlds.\n";
}
