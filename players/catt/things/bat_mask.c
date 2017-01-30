inherit "obj/armor";
reset(arg) {
  if(arg) return;
  set_name("bat mask");
  set_alias("mask");
  set_short("Bat Mask");
  set_long("The mask of Batman.\n");
  set_value(1000);
  set_weight(1);
  set_ac(1);
  set_type("helmet");
}
