inherit "obj/armor" ;

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("Dwarven Cloak");
  set_long("A cloak made from dwarven materials.\n");
  set_ac(1);
  set_weight(1);
  set_value(500);
  set_alias("cloak");
  set_name("Dwarven Cloak");
  set_type("misc");
}
