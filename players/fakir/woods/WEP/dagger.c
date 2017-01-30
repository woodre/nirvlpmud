#include "/players/fakir/color.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("dagger");
  set_short("A rusty dagger");
  set_long("A short blade almost rusted away with a stick handle.\n");
  set_class(3);
  set_weight(1);
  set_value(40);
}

