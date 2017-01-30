/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("neidar");
set_alias("dwarf");
set_race("human");
set_short(BOLD+"Neidar"+NORM);
set_long(
	"  Neidar is a dwarf of the hill clan.  He has deep tan skin,\n"+
	"ruddy cheeks, and bright eyes.  HIs hair is brown and he has\n"+
	"a long beard and moustache.  He tends to be coarse and rough\n"+
	"but is extremely loyal.\n");

set_level(19);
set_hp(475);
set_al(-10);
set_wc(28);
set_ac(16);
set_aggressive(0);

set_chat_chance(10);
  load_chat("Neidar adjusts his pants...\n");
  load_chat("Neidar smiles...\n");
set_a_chat_chance(15);
  load_a_chat("Neidar KICKS at you.....\n");
  load_a_chat("\nNeidar ducks your attack and punches you in the side..\n");

set_chance(9);
set_spell_dam(random(25));
set_spell_mess1("The dwarf "+BOLD+"HEADBUTTS"+NORM+" his foe!\n");
set_spell_mess2("The dwarf "+BOLD+"HEADBUTTS"+NORM+" you!\n");

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}
