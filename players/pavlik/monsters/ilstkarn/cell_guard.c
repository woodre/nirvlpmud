inherit "/obj/monster";

int i;
string my_name;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  i = random(5);
  if(i == 0) { my_name = "Pirthund"; }
  else if(i == 1) { my_name = "Drummak"; }
  else if(i == 2) { my_name = "Homnd"; }
  else if(i == 3) { my_name = "Fortcks"; }
  else if(i == 4) { my_name = "Rak"; }

  set_name(my_name);
  set_alias(lower_case(my_name));
  set_short(my_name);
  set_long(
  my_name+" is one of the shady characters assigned to guard the\n"+
  "prisoners of the dungeon.  "+my_name+" spends most of his time\n"+
  "beating the helpless prisoners senseless.  His clothes are stained\n"+
  "and dirty, but he doesn't seem to notice.  "+my_name+" rips a large\n"+
  "scrap of meat from a chicken leg and chews it nosily.\n");
  set_race("human");
  set_gender("male");
  set_level(17+random(2));
  set_hp(350+random(200));
  set_wc(20+random(10));
  set_ac(12+random(4));
  set_al(-(100+random(900)));
  set_aggressive(0);
  set_chat_chance(30);
  set_a_chat_chance(30);
  load_chat(my_name+" tears a scrap of meat from the chicken leg.\n");
  load_chat(my_name+" belches loudly and then laughs.\n");
  load_chat(my_name+" leans forward and spits.\n");
  load_chat(my_name+" sizes you up.\n");
  load_chat(my_name+" chews noisily.\n");
  load_chat(my_name+" says: Why 'ont we go beat us a'nthr pris'ner?\n");
  load_chat(my_name+" says: Heheh, You 'ear that pris'ner wail like a baby?\n");
  load_a_chat(my_name+" says: Take that, gawddamnit!\n");
  load_a_chat(my_name+" says: Hey!  You ain't supposed to hit back!\n");
  load_a_chat(my_name+" tears a scrap of meat from the chicken leg.\n");
  load_a_chat(my_name+" chews noisily.\n");
  load_a_chat(my_name+" says: You gonnas get it fer that one!\n");
  load_a_chat(my_name+" beats you senseless!\n");
  load_a_chat(my_name+" calls for help!\n");
  load_a_chat(my_name+" punches you in the stomach.\n");
  move_object(clone_object("players/pavlik/items/heals/chicken_leg"),
  this_object());
  money = 400+random(400);
}

id(str) {
  return str == my_name || str == lower_case(my_name) || str == "guard" ||
  str == "cell_guard" || str == "ilstkarn_monster";
}

init() {
  ::init();
  if(this_player()->is_player())
    call_out("swear", 3, this_player());
}

swear(ob) {
  if(!present(ob, environment(this_object()))) {
    return 1;
  }
  if(ob->query_alignment() < -150) {
    tell_object(ob,
    my_name+" says: Let's go kill us sum Whelps!  Har!\n");
  }
  else if(!query_attack()) {
    tell_object(ob,
    my_name+" looks at you and decides you need to be killed.\n");
    this_object()->attack_object(ob);
    ob->attack_object(this_object());
  }
  return 1;
}

