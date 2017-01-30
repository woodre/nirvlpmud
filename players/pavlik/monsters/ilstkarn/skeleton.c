inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Skeleton");
  set_alias("skeleton");
  set_short("A Skeleton");
  set_long(
  "An unrested soul is forced to walk the halls of this Dungeon.  The\n"+
  "skeletons bones clack together noisily as it moves.  The wicked\n"+
  "spirit branishes its sword and prepares to make you a member of the\n"+
  "lost souls that are trapped here forever.\n");
  set_race("undead");
  set_level(13+random(4));
  set_hp(195+random(250));
  set_ac(5);
  set_wc(20+random(20));
  set_al(-500);
  set_aggressive(1);
  set_a_chat_chance(40);
  load_a_chat("The silent skeleton nearly decapitates you!\n");
  load_a_chat("Skeleton's bones splinter from the force of combat.\n");
  load_a_chat("Skeleton buries its sword in your body.\n");
  load_a_chat("The Skeleton flails at you with its sword.\n");
  load_a_chat("Skeleton bashes you with the hilt of its sword.\n");
  load_a_chat("Skeleton moves forward with jerky steps.\n");
  load_a_chat("A Skeleton hacks away mercilessly.\n");
  set_dead_ob(this_object());
}

init() {
  ::init();
  if(this_player()->is_player()) {
    add_action("nope","north");
    add_action("nope","south");
    add_action("nope","east");
    add_action("nope","west");
  }
}

nope() {
  write("The skeleton blocks your path!\n");
  return 1;
}

stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  else {
    write("The skeleton's empty eye sockets blaze angrily!\n");
    return;
  }
}

monster_died() {
  object ob;

  /* no corpses from the skeleton */
  tell_room(environment(),
  "The heap of bones clatters to the floor and turns to dust.\n");
  destruct(present("corpse", environment()));

  ob = clone_object("obj/money");
  move_object(ob, environment());
  ob->set_money(200+random(500));
  
  return 0;
}

