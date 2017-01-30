#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
  ob->set_money(random(200) + 300);
 /* Random coins of 400, less then monster guide */
  move_object(ob, this_object());

set_name("Chul");
set_alias("cavemon");
set_alt_name("chul");
set_race("chul");
set_gender("male");

set_short("A "+MAG+"chul"+NORM);
set_long("A short, purple creature that the goblins use much as human use a dog,\n"+
     "the Chul has a large, protruding jaw to snap at you with, Its scaly\n"+
     "skin makes you think of it as a reptile, but you are not sure.\n");

set_level(10);
set_ac(8);
set_wc(12 + random(4));
set_hp(130 + random(30));
set_al(-900);
set_aggressive(0);

set_a_chat_chance(10);
load_a_chat("Goblin barks at you during the fight.\n");
load_a_chat("The goblin swings the sword poorly.\n");

   }
}
