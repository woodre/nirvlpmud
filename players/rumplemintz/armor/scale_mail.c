inherit "obj/armor.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("scale mail");
  set_short("A suit of scale mail");
  set_type("armor");
  set_ac(3);
  set_weight(3);
  set_value(110);
  set_alias("mail");
}
