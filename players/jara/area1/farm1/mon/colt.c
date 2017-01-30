/* A colt, Created <6/14/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("colt");
  set_short("A young colt");
  set_race("horse");
  set_long("The young colt stands on wobbly legs. He has a long, wild mane and\n"+
    "light brown markings. His ears stand alert, and he has large, brown eyes.\n");
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  load_chat("The colt munches contently on his hay.\n");
   }
}
