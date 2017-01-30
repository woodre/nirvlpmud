inherit "obj/armor";

reset(arg) {
  ::reset(arg);
   if(arg) return;
  set_name("cloak");
  set_alias("green cloak");
  set_short("A green cloak");
  set_long(
    "A warm green cloak with fur lining.\n"
  );
  set_ac(1);
  set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(100);
}
