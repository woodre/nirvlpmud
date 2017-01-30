/*
  keep_soldier_sword.c - sword for use by the soldiers in the keeps
*/

inherit "obj/weapon";

reset(arg) {
  ::reset(arg);

  set_name("short sword");
  set_alias("sword");
  set_short("A short sword");
  set_long(
    "It appears to be a standard-issue short sword for keep soldiers.\n");
  set_class(14);
  set_weight(2);
  set_value(500);
}
