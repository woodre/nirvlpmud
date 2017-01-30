inherit "/obj/monster";

int i;
string mood;

reset(arg) {
  ::reset(arg);
  if(arg && this_object()->query_attack()) {
    return;
  }

  mood = random(3);
  if(i == 0)  mood = "angered";
  else if(i == 1) mood = "pissed";
  else if(i == 2) mood = "confused";

  set_name("Cyclops");
  set_alias("cyclops");
  set_short("Cyclops ("+mood+")");
  if(mood == "angered" || mood == "pissed") set_long(
  "The Cyclops is a tall brutish one-eyed creature.  This one in\n"+
  "particular seems to be very upset about something.  Cyclops are\n"+
  "not known for their intelligence, however even with only one eye\n"+
  "they can be very insightful.\n");
  else if(mood == "confused") set_long(
  "A large brutish creature stands before you.  His only eye blinks\n"+
  "in stupid confusion.  The giant cyclops looks as if he is struggling\n"+
  "with some thought.  Cyclops are not known for their intelligence,\n"+
  "however even with only one eye they can be very insightful.\n");
  set_race("cyclops");
  if(random(2)==0) set_gender("male"); else set_gender("female");
  set_level(16+random(4));
  set_hp(350+random(200));
  set_ac(10+random(8));
  set_wc(20+random(12));
  set_al(-random(100));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(25);
  set_a_chat_chance(40);
  load_chat("The Cyclops sighs wearily.\n");
  load_chat("Cyclops blinks.\n");
  load_chat("The Cyclops says: Have you seen my bauble?\n");
  load_chat("The Cyclops says: It was here a minute ago...\n");
  load_a_chat("Cyclops roars: Give me my bauble!  You won't get away with it!\n");
  load_a_chat("The Cyclops bashes you soundly with its heavy fist!\n");
  load_a_chat("Cyclops grabs you and hurls you through the air!\n");
  load_a_chat("Cyclops roars: I want my bauble!\n");
  money = 700+random(200);
}

id(str) {
  return str == "cyclops" || str == mood || str == "ilstkarn_monster";
}

init() {
  ::init();
  if(this_player()->is_player() && !query_attack())
    call_out("blink", 3+random(5), this_player());
}

blink(ob) {
  if(!present(ob, environment(this_object()))) {
    return 1;
  }
  if(mood == "confused") {
    tell_object(ob,
    "Cyclops tells you: Where did my bauble go?\n"+
    "Cyclops tells you: I had it a moment ago, and now it is gone.\n"+
    "The Cyclops blinks.\n");
  }
  else {
    tell_object(ob,
    "Cyclops roars: Give me my bauble!   You must give it to me!\n");
    if(!this_object()->query_attack()) {
      tell_object(ob, "The Cyclops swings wildly in a blind rage.\n");
      this_object()->attack_object(ob);
    }
  }
  return 1;
}

monster_died() {
  object ob;
  int i;

  ob = present("corpse", environment(this_object()));

  if(random(4)==2) {
    move_object(clone_object("players/pavlik/items/t_ring"), ob);
  }
  else {
    i = random(5);
    if(i==0) move_object(clone_object("players/pavlik/items/blue_potion"), ob);
    if(i==1) move_object(clone_object("players/pavlik/items/clear_potion"), ob);
    if(i==2) move_object(clone_object("players/pavlik/items/red_potion"), ob);
    if(i==3) move_object(clone_object("players/pavlik/items/green_potion"), ob);
    if(i==4) move_object(clone_object("players/pavlik/items/black_potion"), ob);
    move_object(clone_object("players/pavlik/armor/animal_hide"), ob);
  }

  return 0;
}

