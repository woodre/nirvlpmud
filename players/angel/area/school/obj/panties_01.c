#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("silk black panties");
  set_alias("panties");
  set_short("Silk Panties");
  set_long("\
These are a pair of silk black panties. They are made\n\
of the finest silk.\n");
  set_ac(1);
  set_type("underwear");
  set_weight(1);       
  set_value(500);
}