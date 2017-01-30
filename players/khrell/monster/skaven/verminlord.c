#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(YEL+"Kweethul"+NORM+" the"+HIK+" Verminlord"+NORM);
  set_alt_name("kweethul");
  set_alias("verminlord");
  set_short(YEL+"Kweethul"+NORM+" the"+HIK+" Verminlord"+NORM);
  set_long(
"   The Verminlords are the chief agents of the Great Horned Rat though\n"+
"few in number they make up for it in their craft.  It is rumored to be\n"+
"ultimate reward granted to skaven who please their evil god.  They hold\n"+
"in their clawed paws a mighty HellGlave, a fell weapon of dire powers.\n");
  set_race("demon");
  set_level(25);
move_object(clone_object("/players/khrell/weapons/skaven/hglave.c"));
init_command("wield glave");  
  set_wc(55);
  set_ac(25);
  set_hp(2500);
  set_heal(10,5);
  set_al(-1000);
  set_aggro(1, 10, 100);
  add_money(random(3000) + 2000);

  set_chat_chance(10);
load_chat("Your head swims and you feel faint.\n");
load_chat("Your stomach spasms in pain in the presence of the evil creature.");
load_chat("Your sword arm wavers.");

  set_a_chat_chance(10);
load_a_chat("Raw warp energy floods the room!\n");

  set_multi_cast(1);

  add_spell("bubonic bile",
"#MN# spews a glob of infernal $HG$bile$N$ at you!\n",
"#MN# spews a glob of infernal $HG$bile$N$ at #TN#!\n",
5,({12,12}),({"other|poison","other|evil"}));

  add_spell("warp lightning",
"#MN# surrounds one claw with crackling bolt of $G$lightning$N$\n"+
"then releases it directly at you!\n",
"#MN# surrounds one claw with crackling bolt of $G$lightning$N$\n"+
"then releases it directly at #TN#!\n",
20,({40,40}),({"other|evil","other|lightning"}));

  add_spell("drain",
"#MN# whispers a dire $HM$curse$N$, you feel part of your soul drain away!\n",0,
10,30,"other|evil");

  add_spell("warp fire",
"#MN# summons forth a massive pillar of $G$WARP$N$-$HR$FLAME$N$\n"+
"engulfing you!\n",
"#MN# summons forth a massive pillar of $G$WARP$N$-$HR$FLAME$N$!\n",
15,({35,35}),({"other|fire","other|evil"}),1);    

}

init() {
::init();	
  add_action("stop_move","out");
}

stop_move() {
  if(this_player()->is_npc()) return 0;
  if(this_player()->query_ghost()) return 0;
  write(YEL+"Kweethul"+NORM+" snickers and painfully"+HIR+" backhands"+NORM+" you back into the room!\n");
  if(!query_attack()) attack_object(this_player());
  this_player()->hit_player(60);
  return 1; 
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\n"+YEL+"Kweethul"+NORM+" snarls: You will pay-pay mortal for this!  Watch your back!\n"+
  "\n\n"+YEL+"Kweethul's"+NORM+" form shrinks and melts into a terribly scarred sacrificial victim.\n"+
  "\n\n\nA maddening laughter fills your head, and you see a transparent form of the monster vanish before your eyes\n");
    return 0; 
}
