#include "/players/fakir/color.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("stick");
  set_short("Pixie Stick");
  set_long("A small twig from the ancient Tree of Life.\n");
  set_class(5);
  set_weight(1);
  set_value(60);
}

