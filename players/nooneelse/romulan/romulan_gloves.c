/*
 romulan_gloves.c
*/

inherit "obj/armor";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("gloves");
  set_alias("romulan gloves");
  set_short("Romulan gloves");
  set_long("Romulan gloves, with sharp spikes on the backs of the knuckles.\n");
  set_value(500);
  set_weight(1);
  set_ac(1);
  set_type("misc");
}
