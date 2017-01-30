#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("silk bra");
  set_alias("bra");
  set_short(HIM+"Silk Bra"+NORM);
  set_long("\
This is an elegant silk bra. The tag show 36C.\n"
  );
  set_ac(1);
  set_type("chest");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(500);
}