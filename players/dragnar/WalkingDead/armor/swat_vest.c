inherit "obj/armor";

#include <ansi.h>

reset(arg){
   ::reset(arg);
	set_short(HIBLK+"SWAT Vest"+NORM);
  set_long(
"A black SWAT Vest that has many pockets to hold extra ammo and\n\
reinforced shoulder padding for recoil reduction. There are pouches\n\
to hold magazines and a pistol gun holster for your backup weapon.\n\
This vest had been modified to have a bullet proof lining to combine\n\
critical armor protection with the convenience of the vests capabilities.\n");
   set_ac(2);
   set_weight(2);
   set_value(1800);
   set_name("swat vest");
   SetMultipleIds( ({ "swat","vest", "walkerobj" }) );
   set_type("chest");
}

void init() 
{
  ::init();
}
