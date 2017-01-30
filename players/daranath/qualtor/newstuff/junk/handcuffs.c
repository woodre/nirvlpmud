#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/armor";
reset(arg){
   ::reset(arg);

  set_name("silver handcuffs");
  set_short("A pair of silver handcuffs");
  set_alias("handcuffs");
  set_long("A pair of silver handcuffs, they can have many used, depending upon\n"+
           "the imagination of the owner.\n");
  set_type("ring");
  set_ac(1);
  set_weight(1);
  set_value(100);
}

