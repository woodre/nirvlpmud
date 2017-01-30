inherit "obj/armor";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("helmet");
  set_alias("plumed helmet");
  set_short("A plumed helmet");
  set_long(
    "A shiny steel helmet with a horsehair plume.\n"
  );
  set_ac(1);
  set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(125);
}

