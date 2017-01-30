/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object ob,gold;
  ::reset(arg);
  if(arg) return;

set_name("elder");
set_alias("shadow elder");
set_race("creature");
set_short(BOLD+"Shadow Elder"+NORM);
set_long(
	"This elder resembles a slim, gangly ape.  He has a hairy\n"+
	"head with a small, flat nose, pointed ears and sharp fangs,\n"+
	"two of which protrude above his lip when his mouth is closed.\n"+
	"His eyes are amber and resemble those of a cat.  He has long\n"+
	"claws on his hands and feet.  Smooth fur covers his body.  A\n"+
	"long, stretchable membrane connects his arms to his flanks and\n"+
	"allows him to glide through the air.\n");

set_level(20);
set_hp(500);
set_al(60);
set_wc(30);
set_ac(17);
set_heal(20,4);
set_aggressive(0);

set_chat_chance(15);
  load_chat("The elder gestures and closes his eyes...\n");
  load_chat("The elder mutters a quiet chant....\n");
set_a_chat_chance(15);
  load_a_chat("\nThe elder closes his eyes in concentration..\n\n");
  load_a_chat("You feel intense anticipation...\n");
  load_a_chat("\nThe Elder squeaks loudly in pain....\n");

set_chance(20);
set_spell_dam(random(30));
set_spell_mess1(
  "\nYou watch as the Elder seems to THINK pain....\n\n");
set_spell_mess2(
  "\nYour head "+BOLD+" E * X * P * L * O * D * E * S "+NORM+" with pain..\n\n");

gold = clone_object("obj/money");
gold->set_money(4500 + random(1000));
move_object(gold,this_object());
}
