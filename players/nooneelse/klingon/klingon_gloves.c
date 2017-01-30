/*
 klingon_gloves.c
*/

inherit "obj/armor";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("gloves");
  set_alias("klingon gloves");
  set_short("Klingon gloves");
  set_long("Klingon gloves, with sharp spikes on the backs of the knuckles.\n");
  set_value(500);
  set_weight(1);
  set_ac(1);
  set_type("misc");
}
