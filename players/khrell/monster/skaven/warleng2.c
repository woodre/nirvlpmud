#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(HIW+"Warlock Engineer"+NORM);
  set_alt_name("engineer");
  set_alias("warlock");
  set_short(HIW+"Warlock Engineer"+NORM);
  set_long("\
  Clan Skryre are the mad creators of the arcane machinery and deadly\n\
devices of war the skaven make frequent use of.  The warlock engineer\n\
are the inventors and caregivers of their warpcraft.  To better aid \n\
them in their work they usually have all manner of different brass   \n\
'enhancements', though they appear to be crude, they are, by no small\n\
measure, any less deadly or dangerous.                               \n");  
  set_gender("male");
  set_race("skaven");
  set_level(22);
  set_wc(38);
  set_wc_bonus(5);
  set_ac(20);
  set_hp(700);
  set_al(-1000);
  set_aggressive(0);  

  set_chat_chance(10);
load_chat("The engineer adjusts one of the bolts on his body.\n");

  set_a_chat_chance(10);
load_a_chat("A jolt of electric power numbs your sword arm.\n");

  set_multi_cast(0);
  
  add_spell("warp lightning",
"The $G$WARP$HG$LIGHTNING$N$ sizzles you!\n",
"#MN# throws his arm forward and releases $G$WARP$HG$LIGHTNING$N$!\n",
10,({25,25}),({"other|evil","other|electric"}),1);   

gold = clone_object("obj/money");
gold->set_money(random(3000) + 3000);
move_object(gold,this_object());
}
