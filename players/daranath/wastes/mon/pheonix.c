#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2;
 ob = clone_object("obj/money");
  ob->set_money(random(3000) + 1000);
/* Average value from kill 3500 coins, less then monster guide */
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"wep/beak.c");
  move_object(ob2, this_object());

set_name("Minor Phoenix");
set_alias("lavamon");
set_alt_name("phoenix");
set_race("bird");
set_gender("creature");

set_short("A "+HIR+"huge Phoenix"+NORM);
set_long("Silently hovering in the air, the Phoenix looks much like a typical bird,\n"+
         "if you ingnore the fact that its wings are made of pure flame. A\n"+
         "shiny, dark metallic beak protrudes from the face of the Phoenix,\n"+
         "just daring you to fight it. The Phoenix is a tough fight.\n");

set_level(19);
set_ac(15);
set_wc(27 + random(5));
  /* WC higher then Guide, showcasing the power of the Phoenix. */
set_hp(420 + random(90));
set_al(-1000);
set_aggressive(0);

init_command("wield beak");

set_chance(20);
set_spell_dam(25);
set_spell_mess1("\n"+HIR+"Phoenix "+NORM+"lashes out with its firey wings, buring your skin.\n");
set_spell_mess2(HIR+"Phoenix "+NORM+"burns everything within the throne room area.\n");

set_chat_chance(4);
set_a_chat_chance(10);
load_chat("Phoenix hovers silently in the air, waiting for you to make your move.\n");
load_chat("Phoenix flys about the area, leaving a trail of flame in its wake.\n");
load_a_chat("The Phoenix burns you with its "+HIR+"Flame"+NORM+"!\n");
load_a_chat("Phoenix strikes you with a crushing wing buffet.\n");
load_a_chat("The Phoenix flys into the air, then swoops back down at you.\n");

   }
}
