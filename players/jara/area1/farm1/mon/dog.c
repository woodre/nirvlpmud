/* A dog, Created <6/14/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("dog");
  set_short("A farm dog");
  set_race("dog");
  set_long("The dog has thick, black fur and short, cropped ears. His tail\n"+
    "is long and thick at the base. He has huge paws, and his tongue\n"+
    "hangs loosely from his mouth.\n");
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  load_chat("The dog pants heavily.\n");
   }
}
