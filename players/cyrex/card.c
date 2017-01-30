inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;
set_name("accesscard");
set_alias("card");
set_short("A strange access card");
set_long(
  "This rectangular card has a lightning hologram on it.\n");
set_class(1);
set_weight(1);
set_value(225);
}
