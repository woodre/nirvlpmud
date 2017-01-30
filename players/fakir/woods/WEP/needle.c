#include "/players/fakir/color.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("needle");
  set_short(WHITE+"Silver Needle"+OFF);
  set_long("A very sharp gracile needle made entirely of silver.\n");
  set_class(5);
  set_weight(1);
  set_value(30);
}

