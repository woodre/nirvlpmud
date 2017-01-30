#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("Warped Spawn");
  set_alt_name("spawn");
  set_alias("warped");
  set_short("Warped Spawn");
  set_long(
"This is a a twisted mutated thing that you can not tell what it\n"+
"once was.\n");
  set_race("monster");
  set_level(18);
  set_wc(26);
  set_ac(16);
  set_hp(400);
  set_al(-1000);
  set_aggressive(2);
  

set_chat_chance(10);
load_chat("The sludge drips from overhead.\n");
load_chat("You feel sick.\n");
load_chat("You feel ill.\n");
load_chat("Your stomach churns.\n");
load_chat("You gasp for breath.\n");

set_a_chat_chance(20);
load_a_chat("The Spawn lashes out at you.\n");

  set_chance(25);
set_spell_dam(20);
set_spell_mess1( 
"The spawn flings some "+YEL+"s"+RED+"l"+CYN+"ud"+RED+"g"+YEL+"e"+NORM+"\n");

set_spell_mess2(
"The spawn tosses some "+YEL+"s"+RED+"l"+CYN+"ud"+RED+"g"+YEL+"e"+NORM+"\n");

gold = clone_object("obj/money");
gold->set_money(random(2000) + 1000);
move_object(gold,this_object());
}