/*
  tuxedo2.c - made from skins
*/

inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("tuxedo");
  set_short("A black tuxedo");
  set_long("A black tuxedo, with carved onyx buttons.\n");
  set_value(500);
  set_weight(1);
  set_ac(0);
  set_type("armor");
}

id(str) {
  return (str=="armor" || str=="tuxedo" || str=="black tuxedo");
}
