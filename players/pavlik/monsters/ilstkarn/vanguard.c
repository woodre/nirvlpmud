inherit "/obj/monster";

int i;
string my_name;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  i = random(5);
  if(i == 0) { my_name = "Ghot"; }
  else if(i == 1) { my_name = "Ascedo"; }
  else if(i == 2) { my_name = "Herklai"; }
  else if(i == 3) { my_name = "Vyccera"; }
  else if(i == 4) { my_name = "Nanok"; }

  set_name(my_name);
  set_alias(lower_case(my_name));
  set_short(my_name+" the Vanguard");
  if(random(2)==0) set_long(
  my_name+" the Vanguard is one of the irreputable mercenaries that wanders\n"+
  "the Ilstkarken mountains in search of Jondalar.  The Vanguard swears endlessly\n"+
  "as he searches for the elusive ranger.\n"+
  my_name+" scowls menacingly.\n");
  else set_long(
  my_name+" is a ruthless bandit that preys on the helpless travelers of these\n"+
  "mountains.  The dangerous rogue snarls at you and thinks fondly of plunging\n"+
  "his sword between your shoulder blades.  You would be wise to watch your\n"+
  " possesions carefully around him.\n");
  set_race("human");
  if(i < 3) set_gender("male"); else set_gender("female");
  set_level(16+random(3));
  set_hp(300+random(200));
  set_ac(12+random(4));
  set_al(-(100+random(900)));
  set_aggressive(0);
  set_dead_ob(this_object());
  move_object(clone_object("players/pavlik/weapons/ilstkarn/vanguard_sword"), this_object());
  init_command("wield sword");
  set_wc(21+random(10));
  money = 300+random(400);
}

id(str) {
  return str == my_name || str == lower_case(my_name) || str == "vanguard" ||
  str == "guard" || str == "ilstkarn_monster";
}

query_attrib(str) { return 20+random(15); }

init() {
  ::init();
  if(this_player()->is_player() && !query_attack())
    call_out("swear", 3, this_player());
}

swear(ob) {
  if(!present(ob, environment(this_object()))) {
    return 1;
  }
  if(ob->query_alignment() < -150) {
    tell_object(ob,
    my_name+" looks at you and scowls.\n"+
    my_name+" says: Ya seen an Elf 'round here?\n");
  }
  else {
    tell_object(ob,
    my_name+" looks at you and decides you need to be killed.\n");
    this_object()->attack_object(ob);
    ob->attack_object(this_object());
  }
  return 1;
}

monster_died() {
  int tres;
  object ob;

  tres = random(6);
  ob = present("corpse", environment(this_object()));

  if(tres == 0)
    move_object(clone_object("players/pavlik/items/wand_of_healing"), ob);
  else if(tres == 1)
    move_object(clone_object("players/pavlik/items/evil_potion"), ob);
  else if(tres == 2)
    move_object(clone_object("players/pavlik/armor/thief_boots"), ob);
  else if(tres == 3)
    move_object(clone_object("players/pavlik/items/green_potion.c"), ob);

  if(tres != 4) {
    tell_room(environment(), "The black blade crumbles to dust.\n");
    destruct(present("sword", ob));
  }

  return 0;
}

