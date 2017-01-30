#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
set_name("plant");
set_short("A frail white plant");
set_long("A small plant that grows from the cracks in the floor.  It seems to\n"+
         "shrink back from the light of the room.  It is very frail and chalk\n"+
         "white in color.\n");
set_level(1);
set_hp(50);
set_wc(2);
set_ac(3);
}

