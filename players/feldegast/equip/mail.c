inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_name("suit");
  set_alias("mail");
  set_short("A suit of scale mail");
  set_long(
    "A suit of thin interlocking steel scales.\n"
  );
  set_ac(3);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(3);
  set_value(700);
}
