inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

set_name("Shortsword");
set_alias("sword");
set_type("sword");
set_short("A nobleman's shortsword");
set_long(
"This is the sword of a noble of Namek. Nobles use these swords \n"+
"mainly to threaten slaves with when in reality they arent that great at \n"+
"swordsmanship. The sword appears to be somewhat heavy but looks \n"+
"like it could do decent damage.\n");
set_class(13);
set_weight(3);
set_value(500);
}
