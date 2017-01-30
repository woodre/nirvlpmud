inherit "players/mythos/closed/guild/spells/monster2";

reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("tonpi");
  set_race("cat");
  set_alias("cat");
  set_short("Tonpi- master of Mythos");
  set_long("A orange and white cat.  A mutt between an orange\n"+
    "tabby and a short-haired white. He rules the world of\n"+
   " Mythos' and needs constant attention.\n");
  set_level(1);
  set_hp(100000);
  set_al(100);
  weapon = clone_object("/players/mythos/prac/claw.c");
  move_object(weapon,this_object());
  init_command("wield claws");
  set_wc(100);
  set_ac(2);
  set_aggressive(0);
  set_chat_chance(2);
  set_a_chat_chance(10);
  load_chat("Tonpi rubs against your leg.\n");
  load_chat("Mew........\n");
  load_chat("Tonpi curls under the light and goes to sleep.\n");
  load_chat("Tonpi pounces around.\n");
  load_chat("puuurrrrrrrrr......\n");
  load_chat("Tonpi finds a bag and commences to play with it.\n");
  load_a_chat("Tonpi is VERY ANGRY.\n");
  load_a_chat("HHHHHHHHHHHHHHSSSSSSSSSSSSS\n");
  set_mult(13);
  set_mult_chance(50);
  set_mult_dam1(10);
  set_mult_dam2(100);
}
query_prevent_shadow() { return 1; } 
