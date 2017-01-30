/*
  lich.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
  ::reset(arg);
  if (arg) return;

  set_name("cabal");
  set_level(18);
  set_alias("lich");
  set_hp(2286);
  set_al(-700);
  set_short("A lich");
  set_long("He is a terrible undead creature.  Oddly, he seems to be\n"+
           "carrying a small silver cross.\n");
  set_wc(19);
  set_ac(14);
  set_aggressive(0);
  set_gender("male");
  set_alt_name("undead");
  obj=clone_object("obj/money");
  obj->set_money(1000);
  move_object(obj, this_object());
  set_dead_ob(this_object());
}

heart_beat() {
  if(environment(this_object()))
  if (query_attack() && random(100) < 30) {
    tell_room(environment(this_object()),
              "A red flame shoots from his eyes.\n");
    query_attack()->hit_player(25);
    return 0;
  }
  ::heart_beat();
}

monster_died() {
  object obj, crypte_lower_obj, cryptw_lower_obj;
  string str1, str2;
  call_other("players/nooneelse/graveyard/g_path_crypte_lower", "???");
  crypte_lower_obj =
    find_object("players/nooneelse/graveyard/g_path_crypte_lower");
  call_other("players/nooneelse/graveyard/g_path_cryptw_lower", "???");
  cryptw_lower_obj =
    find_object("players/nooneelse/graveyard/g_path_cryptw_lower");
  str1=file_name(environment());
  sscanf(str1, "%s.c", str2);
  if (!str2) str2=str1;

  /* we're in the west crypt */
  if (str2=="players/nooneelse/graveyard/g_path_cryptw_lower") {
    /* if the icon's been placed, make the cross & let it die */
    if (crypte_lower_obj->query_icon()) {
      tell_room(environment(this_object()),
                "As the lich dies, it drops a small silver cross.\n");
      obj=clone_object("players/nooneelse/obj/cross");
      move_object(obj, this_object());
      return 0;
    }
    /* move a new lich to the other crypt & destruct this one */
    if (present("corpse")) destruct(present("corpse"));
    tell_room(environment(this_object()),
      "\nAfter a moment, the lich's corpse raises and laughing, says, "+
      "as he vanishes:\n"+
      "     Maybe next time mortal.\n\n");
    obj=clone_object("players/nooneelse/mon/lich");
    move_object(obj, crypte_lower_obj);
    return 1;
  }

  /* we're in the east crypt */
  if (str2=="players/nooneelse/graveyard/g_path_crypte_lower") {
    /* if the icon's been placed, make the cross & let it die */
    if (cryptw_lower_obj->query_icon()) {
      tell_room(environment(this_object()),
                "As the lich dies, it drops a small silver cross.\n");
      obj=clone_object("players/nooneelse/obj/cross");
      move_object(obj, this_object());
      return 0;
    }
    /* move a new lich to the other crypt & destruct this one */
    if (present("corpse")) destruct(present("corpse"));
    tell_room(environment(this_object()),
      "\nAfter a moment, the lich's corpse raises and laughing, says, "+
      "as he vanishes:\n"+
      "     Maybe next time mortal.\n\n");
    obj=clone_object("players/nooneelse/mon/lich");
    move_object(obj, cryptw_lower_obj);
    return 1;
  }
}
