/*
  linen_gloves.c - made from skins
*/

inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("white gloves");
  set_short("A pair of gloves");
  set_long("A pair of pure white, linnen gloves.\n");
  set_value(75);
  set_weight(1);
  set_ac(1);
  set_type("misc");
}

id(str) {
  return str=="misc" ||
         str=="white gloves" ||
         str=="linen gloves" ||
         str=="white linen gloves" ||
         str=="gloves";
}
