inherit "obj/armor.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("ring mail");
  set_short("A suit of ring mail");
  set_type("armor");
  set_ac(2);
  set_weight(2);
  set_value(50);
  set_alias("mail");
}
