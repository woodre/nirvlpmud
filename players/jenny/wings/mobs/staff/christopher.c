inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "christopher ilitch" ||  str == "christopher" || str == "ilitch" || str == "Christopher Ilitch"; } 
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Christopher Ilitch");
   set_race("human");
   set_gender("male");
   set_al(500+random(100));
   set_level(17);
   set_hp(350+random(20));
   set_wc(23+random(4));
   set_ac(14);
   add_money(2100+random(200));
   set_short(BOLD+WHT+"Christopher Ilitch"+NORM);
   set_long(
      "Christopher Ilitch is one of the sons of owners Mike and Marian Ilitch.\n"+
      "He is a young man with short dark hair, and wearing a black suit.  As\n"+
      "Mike and Marian grow older, Christopher and his sister Denise are\n"+
      "becoming more and more involved with the major decisions of the Ilitch\n"+
      "owned businesses, including the Red Wings.\n");
}
