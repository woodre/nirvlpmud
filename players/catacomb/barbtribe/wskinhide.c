inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("cloak");
  set_short("A wolfskin hide");
  set_long("  A weathered cloak made of wolf hides.\n");
  set_type("misc");
  set_ac(1);
  set_weight(2);
  set_value(200);
}
