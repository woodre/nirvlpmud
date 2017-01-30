/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg)  {
object wep1,wep2,gold;
  ::reset(arg);
  if(arg) return;

set_name("centaur");
set_alias("endscape centaur");
set_race("creature");
set_short("Endscape Centaur");
set_long(
	"  By human standards, the Endscape Centaur is the least \n"+
	"attractive of all the centaurs.  He is about 5 feet tall and\n"+
	"has a shaggy coat and tail.  The hair on their heads often grows\n"+
	"to their waists.  What they lack in beauty, they make up for\n"+
	"in battle prowess.\n");

set_level(19);
set_hp(500);
set_al(0);
move_object(clone_object("players/eurale/Keep/OBJ/scythe"),TO);
init_command("wield scythe");
set_wc(31);
set_ac(16);
set_aggressive(1);

set_chat_chance(9);
  load_chat("The centaur paws the ground.....\n");
  load_chat("You look very carefully at this man/beast...\n");
  load_chat("The centaur asks: Can I help you?\n");
set_a_chat_chance(10);
  load_a_chat("The centaur REARS up....\n");
  load_a_chat("\nThe centaur's hoof just misses your head..\n");
  load_a_chat("\nThe centaur gallops behind you to attack..\n");

set_chance(10);
set_spell_dam(random(25));
set_spell_mess1(
  BOLD+"The centaur kicks WILDLY at its foe!\n"+NORM);
set_spell_mess2(
  BOLD+"The centaur KICKS WILDLY at you!\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2500 +random(1000));
move_object(gold,this_object());
}
