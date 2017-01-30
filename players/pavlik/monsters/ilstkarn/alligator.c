inherit "obj/monster";

reset(arg){
  ::reset(arg);
 if(arg) return;
 set_name("alligator");
 set_alias("gator");
 set_short("A "+(8+random(8))+" foot long Alligator");
 set_long(
 "Yes Indeed!  This alligator has grown fat feeding on the helpless\n"+
 "prisoners of the dungeon.  He chews contentedly on the remains of\n"+
 "another helpless victim.  He looks at you and you get the feeling\n"+
 "'dessert' is stamped on your forehead in big letters.\n");
 set_race("alligator");
 set_level(17+random(3));
 set_wc(24+random(4));
 set_ac(12+random(5));
 set_hp(400+random(100));
 set_al(-(random(500)));
 set_aggressive(1);
 set_a_chat_chance(40);
 load_a_chat("The alligator thrashes around in the cell.\n");
 load_a_chat("The alligator snaps his fiercesome jaws down on your arm!\n");
 load_a_chat("Alligator sinks his sharp teeth into your knee!\n");
 load_a_chat("Alligator gives you the evil eye.\n");
 load_a_chat("Alligator bashes you in the leg with his powerful tail!\n");
 set_dead_ob(this_object());
 money = random(400);
}

id(str) {
  return str == "alligator" || str == "gator" || str == "ilstkarn_monster";
}

monster_died(){
  move_object(clone_object("players/pavlik/items/ilstkarn/alligator_hide"),
  environment());
  destruct(present("corpse", environment()));

 return 0;
}

/*
 * No stopping combat with this guy
 */
stop_fight(){
  return;
}

/*
 * Non of this heal_self crap
 */
heal_self(i) {
  if(i <=0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

