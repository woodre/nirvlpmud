#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("Cowboy's Backpack");
  set_alias("pack");
  set_short("Cowboy's Backpack");
  set_long("\
This backpack has the cowboy's logo and it is blue and silver.\n\
This is used as a shield armor, you can not put things in it.\n"
  );
  set_ac(1);
  set_type("shield");
  set_weight(1);
  set_value(300);
}

/* Added by Rumplemintz */
int id(string str) {
  return str == "pack" || str == "Cowboy's Backpack" || str == "backpack";
}
