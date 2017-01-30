#include <ansi.h>
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("monkey");
  set_short("Mr Bigglesworth the Hairless Spidermonkey");
  set_long(
  "  This is the personal pet of Tallos, Mr Bigglesworth the hairless spider monkey.\n");
  set_type("spear");
  set_class(100);
  set_weight(1);
  set_params("other|physical",1000,0);
  set_value(600);
}

    
