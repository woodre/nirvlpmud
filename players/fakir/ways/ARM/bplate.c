#include "/players/fakir/color.h"
inherit "obj/armor";

reset(arg) {
set_name("breastplate");
set_alias("plate");
set_short("Garnet Studded Breastplate");
set_long(
  "A full length breastplate with dark brown garnet insets at the shoulder\n"+
  "and waist straps.  It is dented from many battles but still serviceable.\n");

set_ac(3);
set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(2);
set_value(800);
}

