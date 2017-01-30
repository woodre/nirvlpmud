inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("owlbear");
  set_short("An Owlbear");
  set_alias("bear");
  set_race("owlbear");
  set_long("The owlbear is a mix between a large black bear and a giant\n"+
           "hunting owl. Dark fur runs the length of its 8 foot tall body\n"+
           "and an ivory beak stands out from its mouth. Large powerful\n"+
           "talons extend from its paws, bringing about a sense of danger.\n");
  set_level(15);
  set_al(-750);
  set_hp(295);
  set_wc(24);
  set_ac(12);
  set_aggressive(0);

  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("The owlbear growls angrily at your presence.\n");
  load_chat("The owlbear extends its large talons torwards you.\n");
  load_a_chat("The owlbear snaps at you with its beak.\n");
  load_a_chat("The owlbear rakes at you with its claws.\n");

  set_chance(30);
  set_spell_dam(25);
  set_spell_mess1("The owlbear tears at you with its claws, drawing blood.\n");
  set_spell_mess2("The owlbear wraps you in a giant bearhug and SQUEEZES!!\n");

  gold=clone_object("obj/money");
  gold->set_money(random(1250)+500);
  move_object(gold,this_object());
}

