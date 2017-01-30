inherit "obj/monster";
object gold, orb, armor;
int items;

reset(arg) {
::reset(arg);
if(arg) return;

set_name("Regis");
set_alias("regis");
set_short("Invid Queen, Regis");
set_long("An evil and sinister looking creature. She looks like a cross\n"+
	  "between a wasp and a dragon. With her powerful wings and claws,\n"+
	  "she looks like she can do some heavy damage to a fool who tries\n"+
	  "to attack her.\n");
set_level(21);
set_hp(1500);
set_al(-1000);
set_ac(17);
set_wc(23);
set_aggressive(0);

set_chance(30);
set_spell_mess1("Queen Regis spits a blazing fireball at you!\n");
set_spell_mess2("You are smashed to the floor with a gust of wind!\n");
set_spell_dam(30);

set_chat_chance(15);
load_chat("Regis says: soon I will be done generating and then...\n");
load_chat("Regis says: soon...soon...very soon.\n");

set_a_chat_chance(15);
load_a_chat("Regis screams: you are not one of my Invids! you will die!\n");
load_a_chat("Regis screams: think you can destroy me?! think again!!\n");

gold = clone_object("obj/money");
gold->set_money(random(500)+1000);
move_object(gold,this_object());

orb = clone_object("players/cyrex/quest/protoorb");
move_object(orb,this_object());

armor = clone_object("players/cyrex/quest/shockplate");
move_object(armor,this_object());
return 1;
}
