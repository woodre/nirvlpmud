inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "barry smith" ||  str == "barry" || str == "smith" || str == "Barry Smith"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Barry Smith");
   set_race("human");
   set_gender("male");
   set_al(200+random(50));
   set_level(14);
   set_hp(225);
   set_wc(18);
   set_ac(11);
   add_money(700+random(100));
   set_short(BOLD+WHT+"Barry Smith"+NORM);
   set_long(
      "Barry Smith is an associate coach for the Detroit Red Wings.  He is\n"+
      "an average size man with wavy grey hair.  Barry has been an associate\n"+
      "coach in Detroit for the past eight seasons.  He primarily works with\n"+
      "the team's forwards.\n");
}
