#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
  ob->set_money(random(400) + 300);
/* Random coins average out to 500 per monster guide */
  move_object(ob, this_object());

set_name("Lurker");
set_alias("cavemon");
set_alt_name("lurker");
set_race("lurker");
set_gender("male");

set_short("A "+CYN+"lurker"+NORM);
set_long("The lurker is a small, scaly creature similar to the Chul, but built\n"+
     "for flying. Large wings protrude from its back, with talons that reach\n"+
     "out from both wings. Its large teeth are perfect for tearing flesh\n"+
     "and bone.\n");

set_level(11);
set_ac(9);
set_wc(10 + random(4));
set_hp(140 + random(45));
set_al(-1000);
set_aggressive(0);

set_a_chat_chance(10);
load_a_chat("The Lurker snaps at you with it jaws.\n");
load_a_chat("The Lurker's talon draw blood!\n");

   }
}
