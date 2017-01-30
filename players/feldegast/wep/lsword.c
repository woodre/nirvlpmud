#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("long sword");
  set_alias("sword");
  set_short("An ancient long sword");
  set_long(
"This ancient long sword is well-fashioned and taken care\n"+
"care of, but the ravages of time have had their effect.  The\n"+
"pommel of this sword is shaped into a ghastly death's head.\n"
  );
  set_type("sword");
  set_class(16);
  set_weight(2);
  set_read("An tiny inscription is written on the guard:\n"+
            "Beyond death, in service to my liege I am fulfilled.\n");
  set_value(500);
}

