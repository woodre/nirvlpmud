inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("club");
  set_short("A large club");
  set_long(
    "  A large club with spikes extruding from the end.\n");
  set_type("club");
  set_class(16);
  set_weight(1);
  set_value(750);
}

  