#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";



reset(arg){
  ::reset(arg);
  if (arg) return;
set_alias("newbie_wep");
set_class(15);
set_weight(1);
set_value(0);
}






