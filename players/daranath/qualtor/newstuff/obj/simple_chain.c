#include <ansi.h>
inherit "obj/armor";

reset(arg){
  ::reset(arg);
                  
  set_name("simple chainmail");
set_short("A suit of simple chainmail");
  set_alias("chainmail");
set_long("A suit of simple chainmail, heavy yet protective.\n");
  set_type("armor");
  set_ac(3);
  set_weight(3);
  set_value(750);
}

