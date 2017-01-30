inherit "obj/armor";

#include <ansi.h>

reset(arg){
   ::reset(arg);
	set_short(HIBLK+"Ammo Belt"+NORM);
  set_long(
"This is a black UTG Heavy Duty Elite Law Enforcement Ammo Belt. The\n\
modern-design belt is sewn with reinforced threads and double-edge\n\
stitched for extra durability and strength. It features a quick\n\
release buckle system that proves critical when you need fast access\n\
to your equipment.\n");
   set_ac(1);
   set_weight(1);
   set_value(1200);
   set_name("belt");
   set_type("belt");
   SetMultipleIds( ({ "ammo belt", "walkerobj" }) );
}

void init() 
{
  ::init();
}
