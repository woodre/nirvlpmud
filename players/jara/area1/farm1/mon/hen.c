/* A chicken, Created <6/14/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("hen");
  set_short("A plump hen");
  set_race("chicken");
  set_long("The hen is plump, and her long feathers are slightly ruffled. She has\n"+
    "a yellow beak and black eyes.\n");
  set_level(3);
  set_ac(4);
  set_wc(7);
  set_hp(45);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  load_chat("The hen picks at the grain.\n");
   }
}
