/* Updated 10/18/01 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg)  {
object wep1,wep2,gold;
  ::reset(arg);
  if(arg) return;

set_name("centaur");
set_alias("abanasinian centaur");
set_alt_name("centaur 1");
set_race("creature");
set_short("Abanasinian Centaur");
set_long(
	"  This is the largest and most handsome of the centaurs.  All\n"+
	"adults exceed 1000 pounds and are at least six feet tall.  Their\n"+
	"broad backs and powerful legs enable them to gallop for long\n"+
	"distances without tiring.  This centaur is extremely robust and\n"+
	"an excellent fighter.\n");

set_level(20);
  set_hp(500);
  set_al(0);
move_object(clone_object("players/eurale/Keep/OBJ/twisted_dagger"),TO);
move_object(clone_object("players/eurale/Keep/OBJ/scythe"),TO);
init_command("wield scythe");
  set_wc(30);
  set_ac(17);
  set_heal(10,4);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(9);
  load_chat("The centaur paws the ground.....\n");
  load_chat("The centaur asks: Can I help you?\n");
set_a_chat_chance(10);
  load_a_chat("The centaur REARS up....\n");
  load_a_chat("\nThe centaur's hoof just misses your head..\n");
  load_a_chat("\nThe centaur gallops behind you to attack..\n");

set_chance(10);
set_spell_dam(random(30));
set_spell_mess1(
  RED+"The centaur strikes out with a sharp hoof!\n"+NORM);
set_spell_mess2(
  RED+"The centaur strikes you with a sharp hoof!\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(3500 +random(1000));
move_object(gold,this_object());
}
