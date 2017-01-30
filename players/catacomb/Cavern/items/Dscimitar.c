inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("scimitar");
  set_alias("sword");
  set_short("A fine scimitar");
  set_long(
    "  A long slender blade created deep under the earth in the Durkor city.\n");
  set_type("sword");
  set_class(17);
  set_weight(2);
  set_value(1000);
}

  