/*
chitin.c
*/
 
inherit "obj/armor";

object chitin;

reset(arg) {
  ::reset(arg);

  set_name("chitin armor");
  set_short("chitin armor");
  set_long("Armor pieced together from an insect's chitin.\n");
  set_value(220);
  set_weight(3);
  set_ac(3);
  set_type("armor");
}

id(str) {
  return (str=="armor" || str=="chitin" || str=="chitin armor");
}
