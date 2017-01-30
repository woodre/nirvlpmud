inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Large Bat");
  set_alias("black bat");
  set_short("A Large Bat");
  set_long(
  "You have disturbed a large black bat from its slumber and it does\n"+
  "not appear to be very happy about it!  The bats eyes glow red with\n"+
  "intense anger.  The bat chitters angrily as it swoops down on you\n"+
  "from above.\n");
  set_race("bat");
  set_level(15+random(5));
  set_hp(1000);
  set_ac(14+random(15));
  set_wc(17+random(15));
  set_al(-random(1000));
  set_aggressive(1);
  set_a_chat_chance(40);
  load_a_chat("The large bat swoops down from above!\n");
  load_a_chat("Large bat bites into you!\n");
  load_a_chat("The Bat sinks its teeth into your neck!\n");
  load_a_chat("The Large bat rakes your skin with sharp claws!\n");
  load_a_chat("The swift bat avoids your clumsy attacks.\n");
  call_out("vamp", 30);
}

vamp() {
  object obj;

  if(!query_attack()) {
    call_out("vamp", 25);
    return 1;
  }

  if(query_hp() < 275) {
    tell_room(environment(), "\n"+
    "A large cloud of mists appears and surrounds the bat.\n"+
    "When the mist clears, a strong tall man dressed in black stands\n"+
    "before you.  The dark man grins evily, his sharp fangs glisten.\n"+
    "\n");
    obj = clone_object("players/pavlik/monsters/ilstkarn/vampire");
    move_object(obj, environment());
    obj->do_vamp(query_attack());
    destruct(this_object());
    return 1;
  }

  call_out("vamp", 15);
  return 1;
}


stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

init() {
  ::init();
  add_action("nope","north");
  add_action("nope","south");
  add_action("nope","east");
  add_action("nope","west");
}

nope() {
  write("The bat will not let you leave!\n");
  return 1;
}

