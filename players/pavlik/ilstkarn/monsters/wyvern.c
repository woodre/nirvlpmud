inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Wyvern");
  set_alias("wyvern");
  set_short("A Wyvern");
  set_long(
  "The Wyvern is often mistaken for a dragon, which it is not.  However,\n"+
  "the wyvern can be just as deadly.  The large scaly monster casually\n"+
  "whips its poison-tipped tail back and forth.  Although the Wyvern isn't\n"+
  "very bright it is a very cunning hunter.\n");
  set_race("wyvern");
  if(random(2)==1) set_gender("male"); else set_gender("female");
  set_level(17);
  set_hp(400+random(100));
  set_ac(14);
  set_wc(20+random(10));
  set_al(-1000);
  set_aggressive(0);
  set_chat_chance(20);
  set_a_chat_chance(40);
  load_chat("Wyvern licks its razor-sharp teeth hungrily.\n");
  load_chat("Wyvern stares at you with a dull, witless stare.\n");
  load_chat("Wyvern fidgits restlessly.\n");
  load_a_chat("Wyvern just misses you with its deadly tail.\n");
  load_a_chat("A Wyvern bashes your skull with its heavy tail.\n");
  load_a_chat("Wyvern shrieks loudly.  The sound makes your head ache.\n");
  load_a_chat("A Wyvern slashes at your with its razor-like claws.\n");
  set_dead_ob(this_object());
  money=300+random(450);
}

id(str) {
  return str == "wyvern" || str == "Wyvern" || str == "ilstkarn_monster";
}

init() {
  ::init();
  if(this_player()->is_player() && !query_attack())
    call_out("glare", 3, this_player());
}

glare(ob) {
  if(!present(ob, environment(this_object()))) {
    return 1;
  }
  if(ob->query_alignment() < -50) {
    tell_object(ob,
    "The large Wyvern looks you over carefully.\n"+
    "The Wyvern bows its head to you slightly.\n");
  }
  else {
    tell_object(ob,
    "The large Wyvern looks you over carefully.\n"+
    "The Wyvern snarls menacingly and attacks!!!\n");
    this_object()->attack_object(ob);
    ob->attack_object(this_object());
  }
  return 1;
}

monster_died() {
  object ob;
  int i;

  ob = present("corpse", environment(this_object()));
  i = random(4);
  if(i==0) move_object(clone_object("players/pavlik/ilstkarn/treasure/red_potion"), ob);
  if(i==1) move_object(clone_object("players/pavlik/ilstkarn/treasure/blue_potion"), ob);
  if(i==2) move_object(clone_object("players/pavlik/ilstkarn/treasure/green_potion"), ob);
  if(i==3) move_object(clone_object("players/pavlik/ilstkarn/treasure/clear_potion"), ob);

  move_object(clone_object("players/pavlik/items/heals/salve"), ob);

  write_file("/players/pavlik/ilstkarn/KILL_LOG",
        ctime() + "\t"+query_name()+" killed by "+capitalize(this_player()->query_name())+" ("+ 
        this_player()->query_level()+")\n");

  return 0;
}

