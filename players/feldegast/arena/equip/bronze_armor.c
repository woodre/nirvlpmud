#include "/players/feldegast/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
  set_name("armor");
  set_short(HIY+"Gleaming Bronze Armor"+NORM);
  set_long(
    "This is a gleaming suit of bronze armor.\n"
  );
  set_ac(4);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(4);
  set_value(2000);
}
