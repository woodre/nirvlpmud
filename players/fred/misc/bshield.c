#include "/players/fred/ansi.h"
inherit "/obj/armor.c";

reset(arg) {
  if(arg) return;
  set_name("shield");   
  set_alias("yup_yup");       
  set_short("An old shield");
  set_long(
  "  An old wooden shield that is barely held together by\n"+
  "several strong metal bands. There is a round insignia in\n"+
  "in the middle of the shield with a picture of a small gold cup.\n");
  set_type("shield");
  set_ac(1);
  set_weight(2);
  set_value(250);
}
