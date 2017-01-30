/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg)  {
object wep1,wep2,gold;
  ::reset(arg);
  if(arg) return;

set_name("centaur");
set_alias("wendle centaur");
set_race("creature");
set_short("Wendle Centaur");
set_long(
	"  This is the smallest of the centaurs, standing only about\n"+
	"4 feet tall.  They resemble Abasaninians and are sometimes\n"+
	"mistaken for their young.  However, this centaur has golden\n"+
	"eyes and a stubby tail and, instead of a ribcage, he has a\n"+
	"solid bone plate.. making him very durable.\n");

set_level(19);
set_hp(485);
set_al(150);
set_wc(28);
set_ac(18);
set_heal(random(10),3,);
set_aggressive(0);

set_chat_chance(9);
  load_chat("The centaur paws the ground.....\n");
  load_chat("You look very carefully at this man/beast...\n");
  load_chat("The centaur asks: Can I help you?\n");
set_a_chat_chance(10);
  load_a_chat("The centaur REARS up....\n");
  load_a_chat("\nThe centaur's hoof just misses your head..\n");
  load_a_chat("\nThe centaur gallops behind you to attack..\n");

set_chance(8);
set_spell_dam(random(18));
set_spell_mess1("The centaur REARS UP on its hind legs.\n");
set_spell_mess2("The centaur CLOBBERS YOU with a front hoof.\n");

gold = clone_object("obj/money");
gold->set_money(3250 +random(1000));
move_object(gold,this_object());
}
