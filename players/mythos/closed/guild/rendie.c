inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("rendie");
  set_short();
  set_alias("rend");
  set_race("spirit");
  set_long("A misty, wispy thing.  Born of the rent orb it hungers\n"+
           "for something....  perhaps blood...\n");
  set_hp(400 + random(1000));
  set_level(16);
  set_al(-random(700) - 500);
  set_wc(20 + random(30));
  set_ac(10 + random(10));
  set_aggressive(1);
  set_wimpy();
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The rendie envelops the area in mist.\n");
  load_chat("The rendie vanishes from sight.\n");
  load_a_chat("The rendie whips around its prey!\n");
  set_chance(20);
  set_spell_dam(60);
  set_spell_mess1("The rendie whips around its prey!\n");
  set_spell_mess2("The Mist wraps around you and you feel pain!\n");
call_out("random_move",10);
}

status random_move() {
  int n;
  n = random(4);
switch(n) {
  case 0 : init_command("north"); break;
  case 1 : init_command("east"); break;
  case 2 : init_command("south"); break;
  case 3: init_command("west"); break;
}
  call_out("random_move",10);
  return 1;
}
