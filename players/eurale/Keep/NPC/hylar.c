/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("hylar");
set_alias("dwarf");
set_race("human");
set_short(BOLD+"Hylar"+NORM);
set_long(
	"  Hylar is a dwarf of the mountains.  He has deep tan skin,\n"+
	"ruddy cheeks, and bright eyes.  HIs hair is brown and he has\n"+
	"a long beard and moustache.  He tends to be coarse and rough\n"+
	"and his battlefield skills are legendary.\n");

set_level(20);
set_hp(500);
set_al(20);
set_wc(30);
set_ac(17);
set_aggressive(0);

set_chat_chance(10);
  load_chat("Hylar asks: You lost, stranger?\n");
  load_chat("Hylar pretends to ignore your presence..\n");

set_chance(14);
set_spell_dam(20 + random(10));
set_spell_mess1(
  "The hylar "+BOLD+"SMASHES"+NORM+" his opponent in the face!\n");
set_spell_mess2(
  "Hylar "+BOLD+"SMASHES YOU"+NORM+" in the face!\n");

gold = clone_object("obj/money");
gold->set_money(4700 + random(100));
move_object(gold,this_object());
}
