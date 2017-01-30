#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("Clanrat Spear");
   set_alias("spear");
   set_type("polearm");
   set_short("A Clanrat Spear");
   set_long("This is a simple yet effective spear used by the Clanrats.\n");
   set_class(16);
   set_weight(3);
   set_value(1000);
   set_hit_func(this_object());
}
