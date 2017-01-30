/* A cat, Created <6/14/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;

  ob = clone_object("/players/jara/area1/docks/obj/collar.c");
    move_object(ob,this_object());

  set_name("cat");
  set_short("A tabby cat");
  set_race("cat");
  set_long("The small cat has dark markings, with brown and black stripes.\n"+
    "a long, wiry tail and long whiskers. His green eyes seem to glow.\n");
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  load_chat("The cat swishes his tail.\n");
   }
}
