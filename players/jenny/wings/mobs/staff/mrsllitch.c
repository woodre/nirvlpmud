inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "marian ilitch" ||  str == "marian" || str == "ilitch" || str == "Marian Ilitch"; } 
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Marian Ilitch");
   set_race("human");
   set_gender("female");
   set_al(700+random(100));
   set_level(19);
   set_hp(450+random(30));
   set_wc(27+random(4));
   set_ac(16);
   add_money(4000+random(700));
   set_chance(20);
   set_spell_dam(20);
   set_spell_mess2("\n"+
"Mrs. Ilitch's diamond ring scrapes across your face as she hits you.\n"+
"\n"+
 "A trickle of "+RED+"Blood "+NORM+"runs down your cheek\n");
   set_short(BOLD+WHT+"Marian Ilitch"+NORM);
   set_long(
      "Marian Ilitch co-owns the Red Wings with her husband, Mike.  She is\n"+
      "an older woman, with curly blonde hair, and wearing an elegant blue dress.\n"+
      "She keeps a lower profile than her husband, but nevertheless, plays a major\n"+
      "role in all financial decisions of the Ilitch owned businesses.\n");
}
