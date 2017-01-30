#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(YEL+"Plague"+MAG+" Monk"+NORM);
  set_alt_name("monk");
  set_alias("plague");
  set_short(YEL+"Plague"+MAG+" Monk"+NORM);
  set_long(
"  Clan Pestilens are the disciples of the Horned Rat in his aspect of\n"+
"the great Plague bringer.  Others in skavendom consider them quite   \n"+
"insane and utterly dedicated to their 'art'.  Clad in scraps of cloth\n"+
"and wearing tattered robes to cover their scabrous, weeping sores, and\n"+
"other disgusting ailments that they proudly wear.\n");  
  set_gender("male");
  set_race("skaven");
  set_level(19);
  set_wc(30);
  set_ac(14);
  set_ac_bonus(5);
  set_hp(450);
  set_al(-1000);
  set_aggressive(2);
  add_money(2000);

set_chat_chance(10);
load_chat("You feel sick to your stomach.\n");
load_chat("You feel a slight fever.\n");
load_chat("You feel ready to vomit.\n");
load_chat("Flies buzz noisily about the room.\n");

set_a_chat_chance(10);
load_a_chat("The "+YEL+"Plague"+MAG+" Monk"+NORM+" hacks up a gob of "+YEL+"phlegm"+NORM+" at you!\n");
  
  set_multi_cast(0);
  
add_spell("pestilent slash",
"#MN# rakes his $C$sc$R$ab$M$ro$R$us$N$ $HW$claws$N$ across your face!\n",
"#MN# rakes his $C$di$R$se$M$as$R$ed $HW$claws$N$ across #NT#'s face!\n",
20,({15,15}),({"physical","other|poison"}));  

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}
