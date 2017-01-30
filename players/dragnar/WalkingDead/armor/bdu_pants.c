inherit "obj/armor";

#include <ansi.h>

reset(arg){
   ::reset(arg);
	set_short(HIBLK+"BDU Pants"+NORM);
  set_long(
"This is pair of black Blackhawk BDU combat pants. These seem to be\n\
of the highest quality, with extra armor built into the knees and\n\
shins. Life-saving tourniquets have been built into the legs in case\n\
of a serious injury. The side pockets are double stiched and have top\n\
mounted zippers so they can be accessed when crouching.\n");
   set_ac(1);
   set_weight(1);
   set_value(1200);
   set_name("pants");
   SetMultipleIds( ({ "bdu pants","bdu", "walkerobj"}) );
   set_type("pants");
}

void init() 
{
  ::init();
}
