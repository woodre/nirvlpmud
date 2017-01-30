#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("staff");
  set_alias("black staff");
  set_short("Black staff");
  set_long(
"This is a black oak staff a meter and a half in length\n"+
"with iron bands on either end.\n"
  );
  set_type("staff");
  set_class(18);
  set_weight(3);
  set_value(1500);
}

weapon_hit(ob) {
  if(query_wear()>40) {
    hits=0;misses=0;
    environment(this_object())->add_spell_point(-random(5));
  }
}
