inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "mickey redmond" ||  str == "mickey" || str == "redmond" || str == "Mickey Redmond"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Mickey Redmond");
   set_race("human");
   set_gender("male");
   set_al(400+random(150));
   set_level(15);
   set_hp(220+random(30));
   set_wc(22);
   set_ac(11);
   add_money(800+random(375));
   set_short(BOLD+WHT+"Mickey Redmond"+NORM);
   set_long(
      "Mickey Redmond is the television analyst for local Red Wing telecasts.\n"+
      "He is a pretty big middle aged guy with dark hair and a mustache.\n"+
      "Mickey is a former player, who is a very popular analyst because of his\n"+
      "hockey knowledge, and likeable personality.\n");
}
