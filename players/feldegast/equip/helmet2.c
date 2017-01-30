inherit "obj/armor";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("helmet");
  set_alias("helm");
  set_short("A bowl-shaped helmet");
  set_long(
    "A cast-iron helmet in a bowl like shape.  It is crude, but sturdy.\n"
  );
  set_ac(1);
  set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(125);
}

