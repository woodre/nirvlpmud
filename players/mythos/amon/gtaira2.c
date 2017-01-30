inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("officer");
  set_race("spirit");
  set_short("Officer of Taira");
  set_long("The Officer stands in quiet dignity.  He is one of the\n"+
    "officers that fell during the Gempei War- the war\n"+
    "between the Minamotos and the Tairas.\n");
  set_hp(120);
  set_level(8);
  set_al(100);
  move_object(clone_object("/players/mythos/aarmor/hara-ate.c"),this_object());
  move_object(clone_object("/players/mythos/aarmor/haramaki.c"),this_object());
  move_object(clone_object("/players/mythos/aarmor/kabuto.c"),this_object());
  move_object(clone_object("/players/mythos/aarmor/kote.c"),this_object());
  move_object(clone_object("/players/mythos/aarmor/mempo.c"),this_object());
  move_object(clone_object("/players/mythos/aarmor/sode.c"),this_object());
  move_object(clone_object("/players/mythos/aarmor/sune-ate.c"),this_object());
/*
  removed wearing of armor due to new armor system makes ac too high
  9 - 27 - 2000 - mythos
  init_command("wear hara");
  init_command("wear haramaki");
  init_command("wear kabuto");
  init_command("wear kote");
  init_command("wear mempo");
  init_command("wear sode");
  init_command("wear sune");
*/
  set_wc(12);
  set_ac(10);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The officer stands contemplating the enemy below.\n");
  load_chat("The officer mutters something.\n");
  load_a_chat("The officer grins as he attacks you.\n");
  load_a_chat("The officer smiles as he watches you dance in pain.\n");
}
