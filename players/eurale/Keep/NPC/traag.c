/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("traag");
set_alias("draconian");
set_race("creature");
set_short(BOLD+"Traag"+NORM+" the Draconian");
set_long(
	"  Tragg is one of the vile monstrosities known as dragonmen or \n"+
	"Draconians.  He is a cross between a humanoid and a dragon.\n"+
	"He is not overly tall but emaciated and gangly.  He has sharp\n"+
	"taloned hands and a crocodile-like snout.  His body is covered\n"+
	"with rough, metallic brass colored scales.\n");

set_level(20);
set_hp(500);
set_al(-100);
set_wc(30);
set_ac(17);
set_aggressive(0);

set_chat_chance(10);
  load_chat("Traag licks his lips in anticipation...\n");
  load_chat("You feel Traag's eyes pierce your soul..\n");
set_a_chat_chance(15);
  load_a_chat("\nTraag fights with a fury.....\n\n");
  load_a_chat("\nYou feel a pain in your side from Traag's blow..\n");

set_chance(7 + random(4));
set_spell_dam(random(20));
set_spell_mess1(BOLD+"Traag SLASHES out with his sharp talons.\n"+NORM);
set_spell_mess2(BOLD+"Traag SLASHES you with his sharp talons.\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(3500 + random(1000));
move_object(gold,this_object());
}
