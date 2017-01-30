inherit "obj/armor";

reset(arg) {
  set_name("cloak");
  set_alias("forester's cloak");
  set_short("A forester's cloak");
  set_long(
    "This is a thick, mottled green cloak used by foresters and\n"+
    "woodsmen to blend into their surroundings.\n"
  );
  set_ac(1);
  set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(500);
}
