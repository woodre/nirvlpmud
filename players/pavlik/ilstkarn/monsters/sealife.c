inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sealife");
  set_alias("sealife");
  set_short("sealife");
  set_long("sealife");
  set_race("ilstkarn_monster");
  set_level(15+random(3));
  set_hp(225+random(275));
  set_ac(12+random(5));
  set_wc(20+random(7));
  set_al(random(500) - random(499));
  set_aggressive(0);
  set_chat_chance(30);
  set_a_chat_chance(30);
  load_chat("A sea urchin moves across the lake's bottom.\n");
  load_chat("A small fish swims past you.\n");
  load_chat("Tiny bubbles squiggle past you as they float upwards.\n");
  load_chat("A bizzare looking jellyfish swims by.\n");
  load_chat("A large fish swims circles around you.\n");
  money = 400+random(400);
  config();
  call_out("r_move", 10+random(20));
}

stop_fight() {
  if(this_player()->query_level() > 20) {
	::stop_fight();
	return 1;
  }
  return;
}

r_move() {
  int x;
  x = random(4);
  if(x==0) command("north");
  if(x==1) command("south");
  if(x==2) command("east");
  if(x==3) command("west");
  call_out("r_move", 20+random(60));
  return 1;
}

config() {
  int i;
  i = random(4);

  if(i==0) {
    set_name("A school of fish");
    set_alias("fish");
    set_short("A school of fish");
    set_long("A few dozen tiny sea fish.  The appear harmless enough...\n");
    load_a_chat("Small fish nips you with its sharp teeth.\n");
    load_a_chat("A small fish darts in front of you.\n");
    load_a_chat("Fish whacks you with its tail!\n");
  }
  else if(i==1) {
    set_name("Shark");
    set_alias("shark");
    set_short("A Shark");
    set_long(
    "A sleek, dangerous looking shark.  You hope he is not hungry!\n");
    load_chat("A Shark swims lazy circles around you.\n");
    load_chat("Shark stares at you curiously.\n");
    load_a_chat("Shark buries its sharp teeth into you!\n");
    load_a_chat("Shark bites you!\n");
  }
  else if(i==2) {
    set_name("Manta Ray");
    set_alias("manta ray");
    set_short("A Manta Ray");
    set_long(
    "The wide gracefully Manta Ray is always a beautiful sight to behond.\n"+
    "The strange creature swims effortless around you.\n");
    load_chat("The gracefully Manta Ray glides past you.\n");
    load_a_chat("Manta Ray stings you with its tail!\n");
    load_a_chat("Manta Ray whacks you with its tail!\n");
    load_a_chat("Manta Ray swims circles around you.\n");
  }
  else if(i==3) {
    set_name("Jellyfish");
    set_alias("jellyfish");
    set_short("A Jellyfish");
    set_long("A bizarre looking Jellyfish.\n");
    load_chat("The Jellyfish contracts and expands, contracts and expands...\n");
    load_chat("Jellyfish jets out some water and swims away from you.\n");
    load_a_chat("Jellyfish stings you!  <OUCH!>\n");
  }
  return 1;
}

