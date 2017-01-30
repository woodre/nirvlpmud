inherit "obj/armor.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("metal helmet");
  set_short("A metal helmet");
  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(75);
  set_alias("metal");
}
