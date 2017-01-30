inherit "obj/armor";

reset(arg) {
  set_name("amulet");
  set_alias("amulet of visions");
  set_short("Amulet of Visions");
  set_long(
"A fine silver amulet with a stylized eye in gold leaf on it.\n"+
"  You may 'view <player>' to use its power.\n"
  );
  set_ac(1);
  set_type("amulet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(150);
}
init() {
  ::init();
  add_action("view","view");
}
view(str) {
  object blank;
  blank=clone_object("/players/feldegast/arena/equip/blank.c");
  if(!str) { write("Usage: view <player>\n"); return 1;}
  blank->load_info(str);
  destruct(blank);
  return 1;
}
