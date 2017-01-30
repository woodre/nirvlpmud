#include "/players/fakir/color.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("dagger");
  set_short("A slim dagger");
  set_long("A slender double edged dagger.  It looks deadly.\n");
  set_class(12);
  set_weight(1);
  set_value(100);
}

