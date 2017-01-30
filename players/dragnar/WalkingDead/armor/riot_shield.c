inherit "obj/armor";

#include <ansi.h>

reset(arg){
   ::reset(arg);
	set_short("SWAT Riot Shield");
  set_long(
"A clear SWAT Riot Shield made from Lexan Polycarbonate. It has a\n\
quick release strap in case it needs to be dropped quickly and an\n\
ergonomic handle. This shield is 2 feet wide by 3 feet long and is\n\
curved toward the edges. Although large, the clear material does not\n\
block sight in any direction. Perfect for fending off Biters.\n");
   set_ac(2);
   set_weight(1);
   set_value(1500);
   set_name("shield");
   SetMultipleIds( ({ "swat","swat shield","swat riot shield","riot shield", "walkerobj"}) );
   set_type("shield");
}

void init() 
{
  ::init();
}
