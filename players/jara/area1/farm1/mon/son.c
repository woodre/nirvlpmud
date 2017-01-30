/* Farmer's Son, Created <6/14/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  add_money(250);
  set_name("son");
  set_short("Derk's Son");
  set_race("human");
  set_long("The farmer's son is a tall boy with sandy brown hair and bright eyes.\n"+
    "He wears a pair of shorts, cut crudely at the knees and a white shirt.\n"+
    "His knees are scabbed and he has a crooked smile.\n");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  load_chat("The farmer's son grins at you.\n");
   }
}
