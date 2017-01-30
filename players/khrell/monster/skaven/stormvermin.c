#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(HIK+"stormvermin"+NORM);
  /* 11/17/05 Earwax changed this from skaven */
  set_alias("stormvermin");
  set_short(HIK+"Stormvermin"+NORM);
  set_long(
"   The fur of larger skaven tends to be darker than normal and for\n"+
"this reason black-furred skaven are respected and feared by their\n"+
"brethren.  These stronger, more vicious warriors are normally picked\n"+
"by the warlords to create units of elite stormvermin.  Better equipped\n"+
"then the rest of the skaven, they form the bodyguard of warlords and\n"+
"greyseers.\n");  
  set_gender("male");
  set_race("skaven");
  set_level(20);
move_object(clone_object("/players/khrell/weapons/skaven/stormhalb.c"));
init_command("wield polearm");  
  set_wc(32);
move_object(clone_object("/players/khrell/armors/skaven/stormshield.c"));
init_command("wear shield");
move_object(clone_object("/players/khrell/armors/skaven/stormplate.c"));
init_command("wear armor");
move_object(clone_object("/players/khrell/armors/skaven/stormhelm.c"));
init_command("wear helm");
move_object(clone_object("/players/khrell/armors/skaven/stormgaunts.c"));
init_command("wear gauntlets");
  set_ac(24);
  set_hp(550);
  set_al(-1000);
  set_aggressive(0);
  add_money(random (2000) + 2000);  

  set_chat_chance(10);
load_chat("The "+HIK+"stormvermin"+NORM+" sneers at you.\n");
load_chat("The"+HIK+" stormvermin"+NORM+" chitters to itself.\n");
load_chat("The "+HIK+"stormvermin"+NORM+" twitches its whiskers.\n");
load_chat("The"+HIK+" stormvermin"+NORM+" lashes his tail.\n");

  set_a_chat_chance(10);
load_a_chat("The "+HIK+"stormvermin"+NORM+" snaps at you with sharpened fangs.\n");

  set_multi_cast(0);
  
add_spell("shield bash",
"You are smashed in the face by a shield block!\n",
"#TN# is bashed in the face!\n",
15,40,"physical");

add_spell("HA-HE-HO!",
"The $HK$Stormvermin$N$ becomes a blur of motion,\n"+
".....his halberd quickly $HW$SMACKS$N$ you upside the head then...\n"+
".......quickly $HR$CHOPS$N$ you in the chest and finally....\n"+
".........$R$IMPALES$N$ you on the sharpened point!\n",
"The $HK$Stormvermin$N$ becomes a blur of attacks on his foe!\n",
10,({20,20,20}),({"physical","physical","physical"}));
}

init() {
::init();
  add_action("stop_move","north");
  add_action("stop_move","south");
  add_action("stop_move","west");
  add_action("stop_move","east");
  }

stop_move() {
  if(this_player()->is_npc()) return 0;
  if(this_player()->query_ghost()) return 0;
  write("The "+HIK+"stormvermin"+NORM+" smashes you with his halberd!\n");
  if(!query_attack()) attack_object(this_player());
  this_player()->hit_player(55);
  return 1; }
  