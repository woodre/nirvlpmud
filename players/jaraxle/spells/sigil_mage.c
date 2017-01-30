#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("mage");
set_alt_name("sigil_mage");
set_alias("illkaunder");
set_race("human");
set_short("Illkaunder the Sigil Mage");
set_long(
"  This is the great archmage Illkaunder. He is middle aged and wears a\n"+
"long red robe.  On his hand is a glowing red sigil. He seems to be\n"+
"tired, although at the same time he seems full of excited energy. A\n"+
"streak of silver runs directly through his long dark hair, and his\n"+
"brown eyes seem to pierce you. He is a very intelligent man, you\n"+
"might be able to ask him about the sigils he sells.\n"); 

set_level(20);
set_hp(650);
set_al(50);
set_wc(70);
set_ac(20);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Illkaunder says, 'Welcome to my store.'\n");
  load_chat("The Sigil Mage writes something down.\n");
  load_chat("The mage nods at you politely.\n");
  load_chat("Illkaunder says, 'Have something to ask me?'\n");
gold = clone_object("obj/money");
gold->set_money(5000);
move_object(gold,this_object());
}

