#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("Nurglitch");
  set_alt_name("plaguelord");
  set_alias("nurglitch");
  set_short(GRN+"Nurg"+YEL+"litch"+NORM+" the "+GRN+"Plague"+HIK+"Lord"+NORM);
  set_long(
"   Nurglitch is the name given to the highest member of clan Pestilens\n"+
"PlagueLords.  His scabrous mangy fur is the most foul of his kind.\n"+
"Open weeping sores and bursting boils squirt their foulness as he\n"+
"capers about in a mad glee.  His grey cataract clouded eyes stare out\n"+
"at the world with fevered madness.  In one paw is the virulent Liber\n"+
"Bubonicus, and in the other the Pandemic Staff.\n");
  set_gender("male");
  set_race("skaven");
  set_level(27);
move_object(clone_object("/players/khrell/weapons/skaven/pandstaff.c"));
init_command("wield staff"); 
  set_wc(48);
  set_wc_bonus(15);
move_object(clone_object("/players/khrell/armors/skaven/plrobe.c"));
init_command("wear robe");
move_object(clone_object("/players/khrell/armors/skaven/liberbub.c"));
init_command("wear shield");  
  set_ac(35);
  set_hp(2000);
  set_al(-1000);
  set_aggro(1, 10, 100);
  set_assist("/players/khrell/monster/skaven/plrat.c", 5, 5, 15);

  set_multi_cast(0);
  
  add_spell("pestilent wind",
"A $G$foul$N$ wind lashes you!\n",
"A $G$foul$N$ wind blows into the room.\n",
20,100,"other|poison");

  add_spell("rat swarm",
"$Y$Rats$N$ burst up from the ground and attack you!\n",
"$Y$Rats$N$ burst from the ground and swarm over everything.\n",
15,({5,5,5,5,5,5}),({"physical","physical","physical","physical","physical","physical"}),1);

gold = clone_object("obj/money");
gold->set_money(12000);
move_object(gold,this_object());
}

init() {
::init();
  add_action("stop_move","south");
  }

stop_move() {
  if(this_player()->is_npc()) return 0;
  if(this_player()->query_ghost()) return 0;
  write(GRN+"Nurg"+YEL+"litch"+HIW+" bodyslams"+NORM+" you back into the room!\n");
  if(!query_attack()) attack_object(this_player());
  this_player()->hit_player(30);
  return 1; }

monster_died() {
  tell_room(environment(this_object()),
  "\n"+GRN+"Nurg"+YEL+"litch"+NORM+" sprays "+RED+"bloody"+NORM+" pus about as he spasms before dieing!\n");
    return 0; 
}
  
