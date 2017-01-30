/* Updated 10/18/01 to conform to /doc/build/RULES/monster.guide  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("stahnk");
set_race("creature");
set_short(BOLD+"Stahnk"+NORM);
set_long(
	"This creature of the undead is about the size of a small dragon.\n"+
        "Its bones protrude from within its rotting flesh.  It has a\n"+
        "great horned head, and all its ribs are bare and barbed, form-\n"+
	"ing a nasty ribcage.  It walks on all fours but it can rear up\n"+
        "on its hind legs, balancing with its stubby tail, to bring\n"+
        "its powerful forearms to bear.\n");

set_level(19);
  set_hp(550);
  set_al(0);
  set_wc(32);
  set_ac(16);
  set_aggressive(1);

set_chat_chance(15);
  load_chat("The Stahnk circles you slowly....\n");
set_a_chat_chance(15);
  load_a_chat("\nThe Stahnk rears up on its hind legs...\n");
  load_a_chat("\nHuge claws rip into your flesh....\n\n");
  load_a_chat("\nSharp pain from the Stahnk's bite....\n");

set_chance(10);
set_spell_dam(random(40));
set_spell_mess1(
  GRY+"The stahnk RIPS its opponent!\n"+NORM);
set_spell_mess2(
  GRY+"The stahnk RIPS you with a fierce strike!\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(3900 + random(200));
move_object(gold,this_object());
}
