#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
  ob->set_money(random(3000) + 3000);
/* average coins of 4500, 500 below monster guide */
  move_object(ob, this_object());

set_name("Roc");
set_alias("platmon");
set_alt_name("roc");
set_race("bird");
set_gender("creature");

set_short("A "+WHT+"Roc"+NORM);
set_long("An enormous, giant sized bird, the Roc makes this corner of the Gundar\n"+
         "plateau its home. The bird has a massive wingspan, easily over 25 feet\n"+
         "across, and has the power to lift an elephant right off the ground.\n"+
         "Not a creature to be taken lightly.\n");

set_level(20);
set_ac(17);
set_wc(27 + random(7));
set_hp(460 + random(100));
set_al(0);
set_aggressive(0);

set_chance(15);
set_spell_dam(25 + random(50));
set_spell_mess1("Roc rears back and lets off a thundering screech.\n");
set_spell_mess2("\nRoc rears back and lets off a tremendous screech into the sky.\n"+
     "Causing your ears to bleed.\n\n");

set_a_chat_chance(10);
load_a_chat("Roc beats its wings fiercly, causing you to loose your balance.\n");
load_a_chat("Roc pecks at the ground in front of you, causing a tremor to shake the plateau.\n");
load_a_chat("Roc seems to enjoy fighting pesky explorers like yourself.\n");

   }
}
