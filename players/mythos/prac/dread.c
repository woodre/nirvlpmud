inherit "players/mythos/prac/doom";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dread");
  set_race("demon");
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
  thp = maxhp = 1000;
rcount = 1;
}

stats() {
  say("The Dread is at "+this_object()->query_hp()+".\n");
call_out("stats",3);
return 1;
}

init() {
  if(this_player()->query_level() > 20) add_action("tat","tat");
}

tat(str) {
  if(!str) return 0;
  if(!present(str,environment(this_object()))) return 0;
   attack_object(present(str,environment(this_object())));
return 1; }
