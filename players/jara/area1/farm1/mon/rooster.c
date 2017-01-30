/* A rooster, Created <6/14/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("rooster");
  set_short("A proud rooster");
  set_race("chicken");
  set_long("The rooster stands tall, his chest puffed up to intimidate any danger\n"+
    "nearby. He has dark red and brown feathers and a bright red crop.\n");
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  load_chat("The rooster scratches at the dirt.\n");
   }
}
