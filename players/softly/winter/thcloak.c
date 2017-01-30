#include "/players/softly/misc/ansi.h"

inherit "obj/armor.c";

reset(arg){


   set_name("threadbare cloak");
   set_alias("cloak");
   set_type("misc");
   set_short("A threadbare cloak");
   set_long("A threadbare cloak that will provide little protection.\n");
   set_ac(1);
   set_weight(1);
   set_value(45);
}
