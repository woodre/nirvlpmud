inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("greaves");
  set_alias("boots");
  set_short("A pair of greaves");
  set_long(
     " A solid pair of greaves.\n");
  set_type("boots");
  set_ac(1);
  set_weight(1);
  set_value(1000);
}
