inherit "obj/armor.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("medium shield");
  set_short("A medium shield");
  set_type("shield");
  set_ac(1);
  set_weight(1);
  set_value(50);
  set_alias("shield");
}
