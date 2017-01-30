inherit "/obj/monster";
#define ME capitalize(obj->query_name())
#define IT capitalize(ob[i]->query_name())

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("the Vampire");
  set_alias("vampire");
  set_short("The Vampire");
  set_long(
  "A tall elegant man dressed all in black.  His skin is smooth and very\n"+
  "pale.  His gaze meets your own and you find it difficult to look away.\n");
  set_race("vampire");
  set_gender("male");
  set_level(30);
  set_hp(1750);
  set_ac(18);
  set_wc(35);
  set_al(-1000);
  set_aggressive(1);
  set_a_chat_chance(30);
  set_dead_ob(this_object());
  load_a_chat("Vampire hisses angrily at you!\n");
  load_a_chat("The Vampire chokes you with his superhuman strength!\n");
  load_a_chat("The Vampire smiles and shows his sharp fangs.\n");
  load_a_chat("Vampire says: I will feast on your blood!\n");
  call_out("bite", 10);
}

id(str) {
  return str == "vampire" || str == "ilstkarn_monster";
}

stop_fight() {
  tell_room(environment(), "The Vampire throws his head back and cackles!\n");
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
  if(present("vampire_charm", this_player())) {
    write("The Vampire will not let you escape!\n");
    return 1;
  }
}

/*
 * No modifying stats either!
 */
set_ac(x) {
  if(this_player() != this_object()) { return; }
  ::set_ac(x);
  return 1;
}

set_wc(x) {
  if(this_player() != this_object()) { return; }
  ::set_wc(x);
}

set_heal_rate(x,y) {
  if(this_player() != this_object()) { return; }
  ::set_heal_rate(x,y);
}

bite() {
  object obj;
  int i;

  obj = query_attack();
  i = random(10);

  if(!obj || !present(obj, environment())) {
    call_out("bite", 15);
    return 1;
  }

  if(i == 1) {
    tell_room(environment(), "the Vampire sinks his fangs deep into "+ME+"'s neck!\n");
    tell_object(obj, "The Vampire sucks your blood!!!\n");
    obj->hit_player(random(30));
    heal_self(random(50));
  }
  else if(i == 3) {
    tell_room(environment(), "The Vampire gives you a charming smile.\n");
    tell_room(environment(), "You feel a little weak in the knees.\n");
  }
  else if(i == 5) {
    tell_room(environment(), "the Vampire lifts "+ME+" of the ground and "+
    "tosses him across the room!\n");
    tell_object(obj, "You smash into the wall with a loud 'SMACK!'\n");
    obj->hit_player(10);
  }
  else if(i == 7) {
    do_charm(obj);
  }
  else if(i == 8) {
    tell_room(environment(),
    "The Vampire tire to mesmerize "+ME+" with his charming stare.\n"+
    ME+" trembles and flees in terror!\n");
    tell_object(obj, "You suddenly freak out!\n");
    obj->run_away();
  }
  else if(i == 9) {
    tell_object(obj, "The Vampire blasts you with a fireball!\n");
    obj->hit_player(random(20));
  }

  call_out("bite", 5+random(10));
  return 1;
}

/*
 * The vampire can charm other beings in the room and make them
 * fight the attacker.  See the object ~/items/ilstkarn/vampire_charm
 * for further details.
 */
do_charm(att) {
  object ob;
  int i;

  ob = all_inventory(environment());
  i = random(sizeof(ob));

  /* if not a valid target then just give up */
  if(ob[i] == this_object() || ob[i] == att ||  !living(ob[i]) ||
  present("vampire_charm", ob[i])) {
    tell_room(environment(), "The Vampire flashes his sharp fangs at you.\n");
    return 1;
  }

  tell_room(environment(),
  "The Vampire stares at "+IT+" intently.\n"+
  "Vampire's eyes shine brightly with an evil red glow.\n");
  tell_object(ob[i],
  "The Vampire whispers kind words in your ear.  You try to ignore them\n"+
  "but you can't!  The Vampire has charmed you!\n");
  tell_object(environment(),
  "The Vampire orders "+IT+" to attack "+capitalize(att->query_name())+"!!!\n");

  move_object(clone_object("players/pavlik/items/ilstkarn/vampire_charm"), ob[i]);
  present("vampire_charm", ob[i])->set_owner(ob[i]);
  present("vampire_charm", ob[i])->do_charm(att);

  return 1;
}

monster_died() {
  tell_room(environment(),
  "The Vampire says: You win ........ this time.\n"+
  "The Vampire says: But do not walk alone at night, I'll be back!\n");
  destruct(present("corpse", environment()));
  if(!random(3)) {
    move_object(clone_object("players/pavlik/armor/blood_pendant"), environment());
  }
  else {
    move_object(clone_object("players/pavlik/items/heals/heal_potion"), environment());
  }
  move_object(clone_object("players/pavlik/items/ilstkarn/teleport_key"), environment());

  if(this_player()->query_real_name())
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" killed the Vampire. ["+ctime()+"]\n");

  return 0;
}

