/*
  boots.c - made from skins
*/

inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("boots");
  set_short("A pair of boots");
  set_long("A pair of calf height, highly polished boots.\n");
  set_value(200);
  set_weight(1);
  set_ac(1);
 set_type("boots");
}

id(str) {
  return str=="boot" || str=="boots";
}
