#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("dwarf axe");
   set_alias("axe");
   set_type("axe");    /* sword/knife/club/axe/bow/polearm   */
   set_short("Dwarfen Axe");
   set_long("This is a description of a sword.\n");
   set_read("This blade was forged by Sengard.\n");
   set_class(18);
   set_weight(2);
   set_value(1200);
}