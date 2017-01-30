inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "denise ilitch" ||  str == "denise" || str == "ilitch" || str == "Denise Ilitch"; } 
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Denise Ilitch");
   set_race("human");
   set_gender("female");
   set_al(500+random(100));
   set_level(17);
   set_hp(350+random(10));
   set_wc(23+random(3));
   set_ac(14);
   add_money(2000+random(200));
   set_short(BOLD+WHT+"Denise Ilitch"+NORM);
   set_long(
      "Denise Ilitch is one of the daughters of owners Mike and Marian Ilitch.\n"+
      "She is a middle aged woman with blonde hair and wearing a black dress.\n"+
      "As Mike and Marian grow older, Denise and her brother Christopher are\n"+
      "becoming more and more involved with the major decisions of the Ilitch\n"+
      "owned businesses, including the Red Wings.\n");
}
