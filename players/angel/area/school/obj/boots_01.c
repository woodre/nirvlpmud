#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("military boots");
   set_alias("boots");
   set_short("Military Boots");
   set_long("They are plain black military boots.\n");
   set_ac(1);
   set_type("boots");   /* armor,helmet,boots,ring,amulet,shield,misc,  */
   set_weight(1);       /* chest,necklace,cloak,bracelet,pants,gloves,  */
   set_value(300);        /* earing,underwear                             */
}