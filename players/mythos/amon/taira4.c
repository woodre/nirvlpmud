inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("taira4");
  set_alias("taira");
  set_race("spirit");
  set_short("Soldier of Taira");
  set_long("The soldier stands- he doesn't look at ease.  His eyes shift\n"+
    "and his hands shake.  But he won't admit to his fear.  From\n"+
    "him an aura of determination eminates.  He will fight to\n"+
    "the death.\n");
  set_hp(30);
  set_level(2);
  set_al(10);
  move_object(clone_object("/players/mythos/aarmor/hara-ate.c"),this_object());
  init_command("wear hara-ate");
  set_wc(6);
  set_ac(3);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The soldier shifts his stance.\n");
  load_chat("The soldier chews on some nuts.\n");
  load_a_chat("The soldier strikes out quickly.\n");
  load_a_chat("The soldier grins.\n");
}
