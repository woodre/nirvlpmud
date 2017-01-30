#pragma strong_types

inherit "room/room";

int helped;

void populate();

void reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_short("A small dirty cell");
  set_long("In a small dirty cell.\n");
  dest_dir = ({ "players/kantele/dungeon_corridor", "north" });
}

void populate() {
  object solar;
  
  helped = 0;
  if (!solar && !present("solar")) {
    solar  = clone_object("obj/monster");
    solar->set_name("solar");
    solar->set_level(19);
    solar->set_short("A beautiful Solar is here");
    solar->set_al(300);
    solar->set_wc(30);
    solar->set_ac(16);
    solar->set_chance(30);
    solar->set_spell_mess1("The Solar throws a fireball");
    solar->set_spell_mess2("You are hit by a fireball");
    solar->set_spell_dam(40);
    solar->set_dead_ob(this_object());
    move_object(solar,  this_object());
    move_object(clone_object("players/kantele/shackles"), solar);
  }
}

void init() {
  ::init();
  add_action("open_shackles", "open");
  add_action("gate_check", "north");
}

status open_shackles(string str) {
  object bag, money;
  
  if (str != "shackles")
    return 0;
  if (!helped && present("solar")) {
    write("You open the shackles on the Solar.\n"+
          "The Solar thanks you.\n"+
          "The Solar drops a bag.\n");
    destruct(present("solar"));
    destruct(present("shackles"));
    write("The Solar disappears in a puff of smoke!\n");
    helped = 1;
    bag = clone_object("obj/bag");
    money = clone_object("obj/money");
    money->set_money(random(2500));
    move_object(money, bag);
    move_object(bag, this_object());
    return 1;
  }
  return 0;
}

status gate_check() {
  if ("players/kantele/guard_room"->query_gate1()) {
    write("A heavy steel celldoor blocks you way.\n");
    return 1;
  }
  this_player()->move_player("north#players/kantele/dungeon_corridor");
  return 1;
}

status monster_died(object ob) {
  write("The Solar explodes, sending a cascade of sparkles falling down.\n");
  destruct(present("corpse"));
  destruct(present("shackles"));
  return 1; /* Rumplemintz */
}
