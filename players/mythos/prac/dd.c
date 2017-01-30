inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dread");
  set_race("daemon");
  set_alias("lord");
  set_short("Dread Lord");
  set_long("The Dread Lord seems to suck your energy away.  It is\n"+
      "a being which destroys all life- it is ANTI-LIFE\n");
  set_level(30);
  set_hp(1000);
  set_al(-100000);
  set_wc(50);
  set_ac(15);
  set_aggressive(0);
  set_chat_chance(20);
  set_a_chat_chance(35);
  load_chat(".....energy....is...sucked....away....\n");
  load_chat("The Dread Lord moves closer to you.\n");
  call_out("stats",3);
}

stats() {
  say("The Dread is at "+this_object()->query_hp()+".\n");
call_out("stats",3);
return 1;
}

init() {
  ::init();
  add_action("heal_self","heal_self");
  add_action("add_hit_point","add_hit_point");
}

heal_self() {
  say("hehe\n");
  return 1;
}

add_hit_point() {
  say("wont work!\n");
return 1;
}
