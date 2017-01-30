/* A rabbit, Created <6/14/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("rabbit");
  set_short("A wild rabbit");
  set_race("rabbit");
  set_long("The small, brown bunny is quite plump. He has a fluffy tail\n"+
    "and long, white whiskers. His little"+HIM+" nose"+NORM+" is constantly wiggling.\n");
  set_level(3);
  set_ac(4);
  set_wc(7);
  set_hp(45);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  load_chat("The rabbit wiggles his nose.\n");
  load_chat("The rabbit digs in the dirt with his paws.\n");
  load_chat("The rabbit wiggles his fluffy tail.\n");
   }
}
