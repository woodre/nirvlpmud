/*
 romulan_armor.c
*/

inherit "obj/armor";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("battle armor");
  set_alias("romulan armor");
  set_alias("armor");
  set_short("romulan battle armor");
  set_long("romulan battle armor.\n");
  set_value(5000);
  set_weight(6);
  set_ac(4);
  set_type("armor");
}
