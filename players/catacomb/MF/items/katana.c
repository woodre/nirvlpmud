#include "/players/catacomb/misc/ansi.h"
inherit "/obj/weapon.c";

reset (arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("katana");
  set_alias("sword");
  set_short("A razor-sharp katana");
  set_long(
   "  A fine blade chosen by the rangers for its excellent \n"+
   "handling and durability.\n");

  set_type("sword");
  set_class(17);
  set_weight(2);
  set_value(1000);
  set_hit_func(this_object()); 
}
  

  
