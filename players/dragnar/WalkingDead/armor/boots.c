inherit "obj/armor";

#include <ansi.h>

reset(arg){
   ::reset(arg);
	set_short(HIBLK+"Tactical Boots"+NORM);
  set_long(
"This is pair of black Oakley Tatical boots. Made of the finest\n\
materials such as SympaTex waterproof barrier, Vibram outsole,\n\
Cordura and full-grain leather upper, Dri-Lex lining, and Ortholite\n\
footbed. These boots are comfortable, light, and are great protection.\n");
   set_ac(2);
   set_weight(1);
   set_value(1500);
   set_name("boots");
   SetMultipleIds( ({ "tactical boots","tactical", "walkerobj" }) );
   set_type("boots");
}

void init() 
{
  ::init();
}
