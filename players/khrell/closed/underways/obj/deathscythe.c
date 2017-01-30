#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("scythe");
   set_alias("death scythe");
   set_type("polearm");    /* sword/knife/club/axe/bow/polearm   */
   set_short("The Scythe of "+HIK+"Death"+NORM);
   set_long("You shouldn't be reading this if your a player.\n");
   set_class(20);
   set_weight(0);
   set_value(0);
}

