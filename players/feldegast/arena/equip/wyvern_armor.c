#include "/players/feldegast/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
  set_name("armor");
  set_short("Wyvernskin armor");
  set_long(
"This suit of armor is formed from the treated hide of a wyvern,\n"+
"a distant cousin of the common dragon.  It is simultaneously\n"+
"extremely flexible and extremely tough, making it an exceptional\n"+
"armor for those lucky enough to obtain it.\n"
  );
  set_ac(4);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(4);
  set_value(2000);
}
