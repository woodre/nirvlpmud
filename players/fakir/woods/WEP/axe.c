#include "/players/fakir/color.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("axe");
  set_short("A Hand Axe");
  set_long("A double bladed axe with a hickory handle.\n");
  set_class(10);
  set_weight(2);
  set_value(440);
}

