inherit "obj/armor.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("leather armor");
  set_short("A suit of leather armor");
  set_type("armor");
  set_ac(3);
  set_weight(3);
  set_value(110);
  set_alias("leather");
}
