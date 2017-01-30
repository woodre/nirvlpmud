/*
 nautilus_captain_nimo.c - captain of the nautilus
*/

inherit "obj/monster";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("nimo");
  set_alt_name("nautilus captain");
  set_alias("captain");
  set_race("human");
  set_short("The ship's captain");
  set_long("The captain is a very strong, intelligent looking man.\n");
  set_level(9);
  set_hp(280);
  set_wc(15);
  set_ac(1000);
  set_al(250);
  set_aggressive(0);
}
