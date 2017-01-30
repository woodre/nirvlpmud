#include "/players/fakir/color.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("peavey");
  set_short("A Loggers Peavey");
  set_long("A lumbermans cant hook, having a spike fixed\n"+
           "on the end of its lever, and a wooden handle\n"+
           "of six feet in length.\n");
  set_class(14);
  set_weight(2);
  set_value(400);
}

