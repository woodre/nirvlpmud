#include "/players/fakir/color.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("choker");
  set_short("A Chain Choker");
  set_long("A thick leather strap with a heavy chain attached\n"+
           "It is used by loggers to hook heavy logs to their\n"+
           "horse team for dragging.\n");
  set_class(10);
  set_weight(3);
  set_value(300);
}

