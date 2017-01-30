inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "karen newman" ||  str == "karen" || str == "newman" || str == "Karen Newman"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Karen Newman");
   set_race("human");
   set_gender("female");
   set_al(150+random(100));
   set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   add_money(420+random(100));
   set_short(BOLD+WHT+"Karen Newman"+NORM);
   set_long(
      "Karen Newman is an attractive middle-aged woman with long blonde\n"+
      "hair.  She is wearing a sexy red dress.  Karen sings the national\n"+
      "anthem before every home game.\n");
}
