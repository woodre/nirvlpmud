inherit "/obj/monster";

int tres;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Automaton");
  set_alias("automaton");
  set_short("A stoic Automaton");
  set_long(
  "An 8 foot tall mass of flesh and muscle, the Automaton is a soulless\n"+
  "killing machine.  The monster's magically animated body is covered\n"+
  "with scars and stitches.\n");
  set_race("unknown");
  set_gender("nueter");
  set_level(18);
  set_hp(400+random(200));
  set_ac(5);
  set_wc(30+random(10));
  set_al(-1000);
  set_aggressive(0);
  set_chat_chance(20);
  set_a_chat_chance(40);
  load_chat("Automaton jerks convulsivly.\n");
  load_chat("Automaton stares blankly.\n");
  load_chat("You hear the faint creaking of old muscles at Automaton moves.\n");
  load_a_chat("Automaton opens its mouth in a silent scream.\n");
  load_a_chat("Automaton flails you mercilessly.\n");
  load_a_chat("Automaton jerks convulsivly.\n");
  set_dead_ob(this_object());
  tres = random(2);
  if(tres == 0) money = random(650)+300;
  else money = random(300);
}

id(str) {
  return str == "automaton" || str == "auto" || str == "ilstkarn_monster";
}

init() {
  ::init();
  if(this_player()->is_player() && !query_attack())
	call_out("creak", 3+random(6), this_player());
}

creak(ob) {
  if(!present(ob, environment(this_object()))) {
	return 1;
  }
  if(ob->query_alignment() < -150) {
	tell_object(ob,
	"The Automaton stares at you blankly.  It doesn't seem to realize you exist.\n");
  }
  else {
    tell_object(ob,
	"The Automaton's blank eyes glow red.\n"+
	"Automaton attacks!\n");
	this_object()->attack_object(ob);
	ob->attack_object(this_object());
  }
  return 1;
}

monster_died() {
  if(tres == 1) {
	move_object(clone_object("players/pavlik/ilstkarn/heals/heal_potion"),
	present("corpse", environment(this_object())));
  }
  write_file("/players/pavlik/ilstkarn/KILL_LOG",
	ctime() + "\t"+query_name()+" killed by "+capitalize(this_player()->query_name())+" ("+	
	this_player()->query_level()+")\n");

  return 0;
}

