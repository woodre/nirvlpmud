/* Farmer's Wife, Created <6/14/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  add_money(250);
  set_name("wife");
  set_short("Derk's Wife");
  set_race("human");
  set_long("The farmer's wife has dirty blonde hair that curls about her shoulders.\n"+
    "She wears a worn dress, dark blue in color and an apron is tied around her\n"+
    "waist. There are flour stains on her apron.\n");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  load_chat("The farmer's wife wipes her hands on her apron.\n");
   }
}
