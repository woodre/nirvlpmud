/*
  silk_shirt.c - made from skins
*/

inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("silk shirt");
  set_short("A silk shirt");
  set_long("A white silk shirt, with a ruffled front & pearl buttons.\n");
  set_value(400);
  set_weight(1);
  set_ac(2);
  set_type("shield");
}

id(str) {
  return str=="shield" ||
         str=="white silk shirt" ||
         str=="white shirt" ||
         str=="silk shirt" ||
         str=="shirt";
}
