/*
 klingon_armor.c
*/

inherit "obj/armor";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("battle armor");
  set_alias("klingon armor");
  set_alias("armor");
  set_short("Klingon battle armor");
  set_long("Klingon battle armor.\n");
  set_value(5000);
  set_weight(6);
  set_ac(4);
  set_type("armor");
}
