#include "/obj/ansi.h"
inherit"/obj/monster.c";
reset(arg) {
object gold;
object armor;
object weapon;
object treasure;
::reset(arg);
if(arg) return;
set_chat_chance(40);
set_a_chat_chance(20);
load_chat("Dragon says:  What do we have here?  A little creature has come to play.\n");
load_chat("Dragon says:  Lets see if the adventures have learned to fight yet.\n");
load_chat("Dragon says:  You smell good!\n");
load_a_chat("Dragon says:  Nice knowing you.\n");
set_name("green");
set_alias("dragon");
set_short(GRN+"Dragon"+NORM);
set_long(
  "This green dragon is huge.  His wing span is just unbelievable.\n"
+ "He is about 116 feet long with a tail of about 104 feet. You start \n"
+ "to run at the site of him, but something helps you fight against the \n"
+ "deadly dragon fear.  He grins as you look him over cause he knows how\n"
+ "glorious he looks.\n");
set_level(30);
set_al(-500);
set_race("dragon");
set_hp(1000);
set_wc(40);
set_ac(20);
set_aggressive(1);
set_chance(50);
set_spell_dam(40);
set_spell_mess1("Breaths out a cloud of poisonous gas.");
set_spell_mess2("You are consumed in a could of poisonous gas!");
gold = clone_object("obj/money");
 gold->set_money(random(500)+300);
 move_object(gold,this_object());
armor = clone_object("/players/mouzar/castle/under/obj/ddamulet");
 move_object(armor,this_object());
weapon = clone_object("/players/mouzar/castle/under/obj/ddsword");
 move_object(weapon,this_object());
treasure = clone_object("/players/mouzar/castle/under/obj/ddplate");
 move_object(treasure,this_object());
}
