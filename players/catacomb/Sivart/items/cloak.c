inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("cloak");
  set_short("Dark cloak");
  set_long(
     " A fine cloak resembling the cloaks the Durkor scouts use.\n");
  set_type("misc");
  set_ac(1);
  set_weight(1);
  set_value(750);
}
