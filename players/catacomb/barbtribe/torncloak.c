inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("cloak");
  set_short("A torn cloak");
  set_long("  A crude cloak full of tears.\n");
  set_type("misc");
  set_ac(1);
  set_weight(1);
  set_value(100);
}
