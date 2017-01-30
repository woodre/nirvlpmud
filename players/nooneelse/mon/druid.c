/*
  druid.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
    ::reset(arg);
  if (arg) return;

  set_name("sebastion");
  set_level(17);
  set_alias("druid");
  set_race("human");
  set_hp(600);
  set_al(0);
  set_short("An old druid");
  set_long("An old man, who looks at peace in the forest.\n");
  set_wc(19);
  set_ac(13);
  set_aggressive(0);
  load_chat("The Druid says: I wish I could remember where the mistletoe"+
            " is growing.\n");
  load_chat("The Druid says: I really need some mistletoe.\n");
  load_chat("The Druid says: I'll trade a piece of oak for some mistletoe.\n");
  set_chat_chance(40);
  set_gender("male");
  obj=clone_object("obj/money");
  obj->set_money(300);
  move_object(obj, this_object());
}

heart_beat() {
  if (query_attack() && random(100) < 25) {
   if(environment(this_object()))
    tell_room(environment(this_object()),
              "The druid casts a shocking grasp spell.\n");
    query_attack()->hit_player(25);
  }
  ::heart_beat();
}

init() {
  ::init();

  add_action("say",            "say");
  add_action("get_mistletoe",  "give");
  add_action("get_mistletoe",  "hand");
  add_action("get_mistletoe2", "trade");
}

say(str) {
  string a, b, c, message;
  a="x"+str+"x";
  if (sscanf(a, "stake%s", b)==1 ||
      sscanf(a, "%sstake", b)==1 ||
      sscanf(a, "%sstake%s", b, c)==2) {
    tell_my_room(str);
    tell_room(environment(),
              "The Druid says: Stake? I'll trade you an oak branch for some "+
              "mistletoe.\n");
    write("You say: "+str+"\n");
    return 1;
  }
  if (sscanf(a, "branch%s", b)==1 ||
      sscanf(a, "%sbranch", b)==1 ||
      sscanf(a, "%sbranch%s", b, c)==2) {
    tell_my_room(str);
    tell_room(environment(),
              "The Druid says: Oak branch?  I'll trade you one for some "+
              "mistletoe.\n");
    write("You say: "+str+"\n");
    return 1;
  }
  if (sscanf(a, "mistletoe%s", b)==1 ||
      sscanf(a, "%smistletoe", b)==1 ||
      sscanf(a, "%smistletoe%s", b, c)==2) {
    tell_my_room(str);
    tell_room(environment(),
              "The Druid says: Mistletoe?  You have some?  I'll trade you a\n"+
              "                piece of oak for some mistletoe.\n");
    write("You say: "+str+"\n");
    return 1;
  }
  return 0;
}

/* tell my room, but not me (need this instead of say for this critter) */
tell_my_room(str) {
  object w_here;
  w_here = first_inventory(environment(this_object()));
  while (w_here) {
    if (living(w_here) &&
        !w_here->query_npc() &&
        w_here != this_player()) {
      tell_object(w_here, this_player()->query_name()+" says: "+str+"\n");
    }
    w_here=next_inventory(w_here);
  }
  return 1;
}

get_mistletoe(str) {
  string str2;
  if (!str) return 0;
  str2=0;
  sscanf(str, "mistletoe to %s", str2);
  if (!str2 || !id(str2)) {
    write(capitalize(query_verb())+" the mistletoe to who?\n");
    return 1;
  }
  swap_mistletoe();
  return 1;
}

get_mistletoe2(str) {
  string str2;
  if (!str) return 0;
  sscanf(str, "mistletoe for %s", str2);
  if (!str2 || (str2!="branch" && str2!="stake" && str2!="oak" &&
      str2!="a piece of oak")) {
    write("Trade the mistletoe for what?\n");
    return 1;
  }
  swap_mistletoe();
  return 1;
}

swap_mistletoe() {
  object obj;
  obj=present("nooneelsemistletoe", this_player());
  if (!obj) {
    tell_room(environment(),
      "The Druid says:  What?  You don't have any mistletoe.  "+
      "I need some mistletoe!\n");
    return 1;
  }
  destruct(obj);
  obj=clone_object("players/nooneelse/obj/oak_branch");
  move_object(obj, environment(this_object()));
  tell_room(environment(),
    "The Druid says:  Thank you!  That's what I needed!\n"+
    "He drops an oak branch.\n");
  return 1;
}
