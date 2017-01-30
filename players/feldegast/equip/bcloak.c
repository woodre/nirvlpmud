inherit "obj/armor";

reset(arg) {
  set_name("cloak");
  set_alias("brown cloak");
  set_short("A brown cloak");
  set_long(
    "This is an earthy brown cloak with several dirt stains and\n"+
    "mismatched patches on it.\n"
  );
  set_ac(1);
  set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(500);
}
