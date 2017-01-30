inherit "/obj/monster";
#define ME capitalize(att->query_name())
#define IT capitalize(ob->query_name())

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Syrian Blacksmith");
  set_alias("syrian blacksmith");
  set_short("Syrian Blacksmith");
  set_long(
  "A round, normally jovial man the Blacksmith travels from town to\n"+
  "town to sell his goods.  He evidently got lost on his travels and\n"+
  "is now stuck in the Ilstkarken mountains.  Although he appears to be\n"+
  "strong and skilled with the hammer and anvil, the Blacksmith is\n"+
  "obviously very scared of being lost and on his own.\n");
  set_race("human");
  set_level(12);
  set_hp(180);
  set_ac(10);
  set_wc(15);
  set_al(500);
  set_aggressive(0);
  money = 100 + random(500);
  call_out("this_chat", 5);
}

id(str) {
  return str == "syrian blacksmith" || str == "blacksmith" ||
  str == "ilstkarn_monster" || str == "syrian_blacksmith";
}

stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

this_chat() {
  object obj, att;
  int i;

  if(!environment(this_object())) {
       call_out("this_chat", 10);
       return 1;
  }

  if(this_object()->query_attack()) {
       call_out("this_chat", 10);
       return 1;
  }

  obj = present("blacksmith_killer", environment(this_object()));

  if(obj && obj->query_attack()) {
       i = 12 + random(6);
       att = obj->query_attack();
  }
  else if(obj)
       i = random(6);
  else
       i = 6+random(6);

  if(i == 0) tell_room(environment(this_object()),
  "Blacksmith swings his hammer through the air.\n"+
  "Blacksmith shouts: Stay back!\n");
  if(i == 1) tell_room(environment(this_object()),
  "Blacksmith screams for help!\n");
  if(i == 2) tell_room(environment(this_object()),
  "Syrian Blacksmith tells you: Help me, Please!\n");
  if(i == 3) tell_room(environment(this_object()),
  "The Blacksmith stumbles backwards.\n"+
  "Blacksmith shouts: Get away from me, monster!\n");
  if(i == 4) tell_room(environment(this_object()),
  "The Blacksmith backs up slowly.\n");
  if(i == 5) tell_room(environment(this_object()),
  "Blacksmith tries to cower behind a rock.\n");

  if(i == 6) tell_room(environment(this_object()),
  "Blacksmith says: I cannot believe I have gotten lost!\n");
  if(i == 7) tell_room(environment(this_object()),
  "Blacksmith scratches his head.\n");
  if(i == 8) tell_room(environment(this_object()),
  "Syrian Blacksmith puts his head in his hands.\n");
  if(i == 9) tell_room(environment(this_object()),
  "Blacksmith asks: Do you know how to get to Tilgaard?\n");
  if(i == 10) tell_room(environment(this_object()),
  "The Blacksmith looks around and shivers slightly.\n");
  if(i == 11) tell_room(environment(this_object()),
  "Blacksmith says: Do You know where we are?\n");

  if(i == 12) tell_room(environment(this_object()),
  "Blacksmith yells: Yeah!  Get 'im "+ME+"!\n");
  if(i == 13) tell_room(environment(this_object()),
  "Blacksmith cowers behind a rock.\n");
  if(i == 14) tell_room(environment(this_object()),
  "The Syrian Blacksmith cheers you on.\n");
  if(i == 15) tell_room(environment(this_object()),
  "Blacksmith says: Kill that damnable beast!\n");
  if(i == 16) tell_room(environment(this_object()),
  "Blacksmith shouts: Wham!  Wham!  Hit 'im again, "+ME+"!\n");
  if(i == 17) tell_room(environment(this_object()),
  "Syrian Blacksmith stays carefully away from the fighting.\n");

  call_out("this_chat", 5+random(15));
  return 1;
}

do_savior(ob) {
  call_out("thank", 3, ob);
  return 1;
}

thank(ob) {
  if(ob && present(ob, environment(this_object())) && ob->is_player()) {
    tell_room(environment(ob), "\n");
    tell_room(environment(ob),
    "The Syrian Blacksmith comes up and bows before "+IT+".\n"+
    "Blacksmith says: Thank you, noble one.  You have saved my life!\n"+
    "Blacksmith says: Take this, as a symbol of my appreciation.\n");
    tell_room(environment(ob),
    "Syrian Blacksmith gives something to "+IT+".\n\n");
    move_object(clone_object("players/pavlik/items/ilstkarn/syrian_gem"), ob);
  }
  return 1;
}

