inherit "obj/monster";
reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("slave");
  set_race("monkey");
  set_short("Slave of the Master Kappa");
  set_long("The Slave is the personal retainer of the Master of the Kappa.  He is set here\n"+
    "to watch over the other Kappa.  He is a small monkey and is you\n"+
    "notice when he moves his mouth that he has no tongue.  On his right\n"+
    "hand he wears silver ring.\n");
  set_hp(115);
  set_level(7);
  set_al(0);
  weapon = clone_object("/players/mythos/awep/ring.c");
  move_object(weapon,this_object());
  init_command("wield ring");
  set_wc(12);
  set_ac(6);
  set_aggressive(0);
  set_chat_chance(5);
  set_a_chat_chance(10);
  load_chat("The Slave looks at you with a blank expresson.\n");
  load_a_chat("The Slave screams horribly and attacks its foe.\n");
  load_a_chat("The Slave spits at you.\n");
}
