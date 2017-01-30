inherit "/obj/weapon.c";
#include <ansi.h>

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("baton");
  set_short("Baton");
  set_long(
 "  A small baton that is about 3 feet in length and about\n"+
 "2 1/2 inches in diameter. It fits nicely in your hand and\n"+
 "if used properly could be very effective.\n" );
  set_type("club");
  set_class(16);
  set_weight(2);
  set_value(700);
  }
