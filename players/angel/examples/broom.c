#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("yellow quest broom");
   set_alias("broom");
   set_short("A Yellow Broom");
   set_long("This broom is made with a yellow handle and rubber wisks.\n");
   set_ac(1);
   set_type("sword");
   set_weight(1);
   set_value(300);
}