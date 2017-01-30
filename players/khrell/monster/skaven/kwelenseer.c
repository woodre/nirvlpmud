#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(HIK+"Greyseer Kwelen"+NORM);
  set_alt_name("greyseer");
  set_alias("kwelen");
  set_short(HIK+"Greyseer Kwelen"+NORM);
  set_long("\
  The Greyseer are the prophets of the evil deity known only as the\n\
Great Horned Rat.  Kwelen ranks amongst the highest of the teeming \n\
hordes of Fester Peak.  Through typical skaven manipulation, plotting\n\
scheming and assassination, he has advanced his position.\n");
  set_gender("male");
  set_race("skaven");
  set_level(27);
  set_wc(40);
move_object(clone_object("/players/khrell/armors/skaven/twiscrown.c"));
init_command("wear crown");
move_object(clone_object("/players/khrell/armors/skaven/foulpendant.c"));
init_command("wear pendant");  
  set_ac(30);
  set_hp(1500);
  set_heal(10,1);
  set_al(-1000);
  set_aggressive(3);
  add_money(2000);  

  set_chat_chance(10);
load_chat("The Greyseer chitters quietly.\n");

  set_a_chat_chance(10);
load_a_chat(HIK+"Greyseer Kwelen"+NORM+" squeaks in rage.\n");

  set_multi_cast(1);
  
  add_spell("vermintide",
"The $G$ V E R M I N $Y$T I D E $N$ rolls over you!\n",
"#MN# squeaks and fllas to his knees, summoning the $G$Vermin$Y$Tide$N$!\n",
10,({10,10}),({"other|evil","other|physical"}),1);

  add_spell("warp lightning",
"#MN# surrounds one paw with crackleing bolt of $G$lightning$N$\n"+
"then releases it directly at you!\n",
"#MN# surrounds one paw with crackleing bolt of $G$lightning$N$\n"+
"then releases it directly at #TN#!\n",
20,({5,40}),({"physical","other|lightning"}));

  add_spell("plague",
"#MN# whispersa dire $HM$curse$N$, you feel part of your soul drain away!\n",0,
10,30,"other|evil");

  add_spell("warp fire",
"#MN# summons forth a massive pillar of $G$WARP$N$-$HR$FLAME$N$\n"+
"engulfing you!\n",
"#MN# summons forth a massiave pillar of $G$WARP$N$-$HR$FLAME$N$!\n",
15,({25,35}),({"other|fire","other|evil"}),1);    

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n"+HIK+"Greyseer Kwelen"+NORM+" squeaks pitifully, staggers then collaspes dead!\n");
    return 0; 
}
