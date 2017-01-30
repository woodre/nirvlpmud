#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+BLK+"LoOpy ViLLaGe"+NORM);
   set_long(
      "  You now stand on the east end of the village. The streets\n"+
      "are made of hard packed dirt. The sun is bright here and you\n"+
      "can feel the sun on your back.\n");
   add_item("streets","A long street running east and west");
   add_item("dirt","Packed hard dirt forms the road");
   add_item("sun","You scream as the sun blinds you");
   add_listen("main","You can hear children laughing off in the distance.");
   add_exit("/players/fred/forest/Rooms/vill_6.c","south");
   add_object("/players/fred/forest/Mon/vkid.c");
}

