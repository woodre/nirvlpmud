#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("belt");
   set_alias("a belt");
   set_short("A Belt");
   set_long("This is a basic belt\n");
   set_ac(1);
   set_type("belt");   /* armor,helmet,boots,ring,amulet,shield,misc,  */
   set_weight(2);       /* chest,necklace,cloak,bracelet,pants,gloves,  */
   set_value(200);        /* earing,underwear                             */
}