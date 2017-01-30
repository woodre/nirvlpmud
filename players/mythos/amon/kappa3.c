inherit "obj/monster";
reset(arg)  {
  object armor;
  ::reset(arg);
  if(arg) return;
  set_name("kappa3");
  set_alias("kappa");
  set_race("spirit");
  set_short("Kappa");
  set_long("The Kappa looks like a monkey with no fur.  It has yellow-green skin\n"+
    "and is the size of a ten-year-old.  On its back is a tortoise shell and on its\n"+
    "head is an indentation filled with a small amount of water.\n");
  set_hp(45);
  set_level(3);
  set_al(0);
  armor = clone_object("/players/mythos/aarmor/shell.c");
  move_object(armor,this_object());
  init_command("wear shell");
  set_wc(7);
  set_ac(4);
  set_aggressive(0);
  set_chat_chance(10);
  set_frog();
  set_a_chat_chance(15);
  load_chat("The Kappa jumps into the water and laughs.\n");
  load_chat("The Kappa eats something that looks like it was a fish.\n");
  load_a_chat("The Kappa grins at you.\n");
  load_a_chat("The Kappa's claws gleam in the light.\n");
}
