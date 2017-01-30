/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg)  {
object ob,gold;
  ::reset(arg);
  if(arg) return;

set_name("warrior");
set_alias("shadow warrior");
set_alt_name("warrior 1");
set_race("creature");
set_short("Shadow Warrior");
set_long(
	"This warrior resembles a slim, gangly ape.  He has a hairy\n"+
	"head with a small, flat nose, pointed ears and sharp fangs,\n"+
	"two of which protrude above his lip when his mouth is closed.\n"+
	"His eyes are amber and resemble those of a cat.  He has long\n"+
	"claws on his hands and feeet.  Smooth fur covers his body.  A\n"+
	"long, stretchable membrane connects his arms to his flanks and\n"+
	"allows him to glide through the air.\n");

set_level(19);
set_hp(475);
set_al(30);
move_object(clone_object("players/eurale/Keep/OBJ/shadowstaff"),TO);
init_command("wield staff");
set_wc(29);
set_ac(15);
set_aggressive(0);

set_chat_chance(15);
  load_chat("The warrior grunts and squeaks.....\n");
  load_chat("The warrior readies his shadowstaff...\n");
set_a_chat_chance(15);
  load_a_chat("The warrior jabs at you with his shadowstaff...\n");
  load_a_chat("The warrior ducks your attack....\n");
  load_a_chat("You feel the point of the shadowstaff against your chest..\n");

set_chance(20);
set_spell_dam(random(20));
set_spell_mess1(
  "\nYou feel a terrible pain in your head....\n\n");
set_spell_mess2(
  "\nYou feel intense pain in your head.....\n\n");

gold = clone_object("obj/money");
gold->set_money(500 + random(1000));
move_object(gold,this_object());
}
