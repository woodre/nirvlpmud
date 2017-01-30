#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("cowboy boots");
   set_alias("boots");
   set_short("Cowboy Boots");
   set_long("They are plan brown cowbot boots\n");
   set_ac(0);
   set_type("boots");   /* armor,helmet,boots,ring,amulet,shield,misc,  */
   set_weight(1);       /* chest,necklace,cloak,bracelet,pants,gloves,  */
   set_value(300);        /* earing,underwear                             */
}

