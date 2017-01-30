inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("qurd");
  set_short("Qurd");
  set_alias("qurd");
  set_race("demon");
  set_long("The Qurd is something that appears to be somewhat\n"+
    "human, yet somewhat animal.  His tall, strong body is\n"+
    "human in shape, but is covered with fur.  He emits a\n"+
    "menacing growl as he notices you, and you feel his anger.\n");
    
  set_hp(500);
  set_level(20);
  set_al(-1000);
  set_wc(40);
  set_ac(17);
  set_aggressive(0);

  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("The Qurd eyes you with disdain and veiled anger...'\n");
  load_chat("The Qurd    GROWLLLLSSSS  at you.\n");
  load_a_chat("You feel latent earth-energy swirling around the\n"+
            "room and you know FEAR!\n");

  set_chance(30);
  set_spell_dam(20);
  set_spell_mess1(" The force of the Qurd's hatred engulfs you!\n");
  set_spell_mess2("The Qurd directs the earth-energy at you and you reel with pain!\n");
   

  gold=clone_object("obj/money");
  gold->set_money(random(4000)+3000);
        /*  Point of note: 3000 +random(4000)  averages 5000 coins i.e. legal limit */
  move_object(gold,this_object());
}

