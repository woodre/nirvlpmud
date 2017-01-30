inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("cat3");
  set_alias("cat");
  set_race("spirit");
  set_short("Black Cat");
  set_long("The Cat is a sleek looking animal.  Its ebony fur seems\n"+
    "to suck the light from the room.  It sees you and \n"+
    "seems mildly amused.\n");
  set_hp(45);
  set_level(3);
  set_al(0);
  set_wc(7);
  set_ac(4);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The Black Cat pads sloftly across the room.\n");
  load_chat("A black cat looks at you and seems to * wink *\n");
  load_a_chat("A FurBall of Fury snarls and jumps at you.\n");
  load_a_chat("\nS W I P E         You might have a permanent scar.\n\n");
  gold=clone_object("obj/money");
  gold->set_money(random(10)+90);
  move_object(gold,this_object());
}
