/*
 klingon_boots.c
*/

inherit "obj/armor";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("boots");
  set_alias("klingon boots");
  set_short("Klingon boots");
  set_long("Klingon boots, with sharp spikes on the toes.\n");
  set_value(500);
  set_weight(1);
  set_ac(1);
  set_type("boots");
}
