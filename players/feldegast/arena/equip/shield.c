inherit "obj/armor";

reset(arg) {
  set_name("shield");
  set_alias("steel shield");
  set_short("A steel shield");
  set_long(
    "A round steel shield approximately a foot and a half in diameter.\n"
  );
  set_ac(1);
  set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(3);
  set_value(200);
}
