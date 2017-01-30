/*
  silk_tie.c - made from skins
*/

inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("black tie");
  set_short("A black silk tie");
  set_long("A black silk necktie.\n");
  set_value(50);
  set_weight(1);
  set_ac(1);
  set_type("amulet");
}

id(str) {
  return str=="amulet" ||
         str=="tie" ||
         str=="black tie" ||
         str=="silk tie" ||
         str=="black silk tie";
}
