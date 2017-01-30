#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(HIR+"War"+NORM+RED+"lord"+HIK+" Qurnk"+NORM);
  set_alt_name("warlord");
  set_alias("qurnk");
  set_short(HIR+"War"+NORM+RED+"lord"+HIK+" Qurnk"+NORM);
  set_long(
"   This is Warlord Qurnk.  His massive furred frame bulges with\n"+
"large slabs of muscle.  His black fur marks him out as a fierce\n"+
"fighter.  Gripped in one hand is the infamous 'Fellblade', and\n"+
"he wears the Warpstone Armor as a mark of his high rank.  Many\n"+
"are his victories and few are his defeats.\n");
  set_gender("male");
  set_race("skaven");
  set_level(26);
move_object(clone_object("/players/khrell/weapons/skaven/fellblade.c"));
init_command("wield blade");  
  set_wc(56);
  set_wc_bonus(10);
move_object(clone_object("/players/khrell/armors/skaven/warparmor.c"));
init_command("wear armor");
move_object(clone_object("/players/khrell/armors/skaven/stormhelm.c"));
init_command("wear helm");
move_object(clone_object("/players/khrell/armors/skaven/stormgaunts.c"));
init_command("wear gauntlets");
move_object(clone_object("/players/khrell/armors/skaven/stormshield.c"));
init_command("wear shield"); 
  set_ac(34);
  set_ac_bonus(20);
  set_hp(1200);
  set_hp_bonus(1000);
  set_heal(40,2);
  set_al(-1000);
  set_dead_ob(this_object());
  set_aggro(1, 10, 100);

  set_multi_cast(1);
  
add_spell("shield bash",
"You are smashed in the face by a shield block!\n",
"#TN# is bashed in the face!\n",
15,50,"physical");

add_spell("eight-slash","",
"#MN# draws his blade back, then quickly spins a vicious\n"+
"figure-eight, $HR$S-L-I-C-I-N-G$N$ you multiple times!\n",
15,({15,15,15,15,15,15,15,15}),({"physical","physical","physical","physical","physical","physical","physical","physical"}),1); 

gold = clone_object("obj/money");
gold->set_money(10000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n"+HIR+"War"+NORM+RED+"lord"+HIK+" Qurnk"+NORM+" gurgles and coughs up dark "+RED+"blood"+NORM+" and collapses dead!\n");
    return 1; 
}
