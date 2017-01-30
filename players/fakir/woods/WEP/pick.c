#include "/players/fakir/color.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("pick");
  set_short("A steel pick");
  set_long("A double bladed pick used for digging in the mines.\n");
  set_class(5);
  set_weight(1);
  set_value(40);
}

