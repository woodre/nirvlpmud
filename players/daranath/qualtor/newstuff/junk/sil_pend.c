#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/armor";
reset(arg){
   ::reset(arg);

  set_name("silver pendant");
  set_short("A silver "+WHT+"pendant"+NORM+" on a small chain");
  set_alias("pendant");
  set_long("A small silver pendant on a beautful silver chain.\n");
  set_type("amulet");
  set_ac(1);
  set_weight(1);
  set_value(400);
}

