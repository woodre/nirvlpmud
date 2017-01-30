#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("stick");
  set_short("A Pointy Stick");
  set_long(
    "    A sharpened stick.\n");
  set_type("spear");
  set_class(13);
  set_weight(1);
  set_value(600);
}

    
