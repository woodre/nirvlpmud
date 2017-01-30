inherit "obj/armor";

#include <ansi.h>

reset(arg){
   ::reset(arg);
	set_short(HIBLK+"Balaclava"+NORM);
  set_long(
"A black heavy duty balaclava constructed of NOMEX fabic to protec the\n\
head and neck from fire and flash damage. It has an extended bib that\n\
covers the neck and shoulders. This is made with the finest quality,\n\
the stiches are even flat so it won't caused irritation when worn\n\
with a helmet.\n");
   set_ac(1);
   set_weight(1);
   set_value(1200);
   set_name("balaclava");
   set_type("misc");
   SetMultipleIds( ({ "walkerobj" }) );
}

void init() 
{
  ::init();
}
