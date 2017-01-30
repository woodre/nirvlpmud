#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("fungusbrew");
  add_alias("brew");
  add_alias("fungus brew");
  add_alias("fungi");
  add_alias("jug");
  set_short("A jug of"+GRN+" Fungus Brew"+NORM);
  set_long("This is a jug of goblin brew, its in some sort of old jug\n\
smeared with stains and other foulness.\n");
  set_type("sips");
  set_msg("You take a gulp of the fungus brew and then replace the cork.\n");
  set_msg2(" drinks some brew.\n");
  add_cmd("drink");
  add_cmd("swig");
  add_cmd("sip");
  set_heal((35 + random(15)), (-5 - random(6)));
  set_charges(3);
  set_intox(10);
  set_value(600);
}
