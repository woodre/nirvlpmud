inherit "obj/monster";
reset(arg)  {
  object armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("master");
  set_race("spirit");
  set_short("Master Kappa");
  set_long("This Kappa is a bit bigger than the others.  Its green skin shines in the light.\n"+
    "He sees you looking at him and he grins- revealing hundreds of needle sharp teeth.\n"+
    "You don't think you want to fight him.\n");
  set_hp(215);
  set_level(12);
  set_al(0);
  weapon = clone_object("/players/mythos/awep/claw.c");
  move_object(weapon,this_object());
  init_command("wield claws");
  set_wc(15);
  set_ac(9);
  set_aggressive(0);
  set_chat_chance(10);
  set_frog();
  set_a_chat_chance(15);
  load_chat("The Master Kappa smiles grimly.\n");
  load_chat("The Master sharpens his claws on a small rock.\n");
  load_a_chat("Master cries out with a blood-cudling sound.\n");
  load_a_chat("Master smiles and bites into your flesh.\n");
}
