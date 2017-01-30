#include <ansi.h>
inherit "/obj/monster";
#define IT capitalize(obj->query_name())

reset(arg) {
  ::reset(arg);
  if(arg) {
    return;
  }
  set_name("Great Shark");
  set_alias("great shark");
  set_short("Great Shark");
  set_long(
  "The Great Shark is perhaps the most deadly predator to swim\n"+
  "the waters.  The monster's huge jaws are capable of swallowing\n"+
  "a human being in a single bite!  The Great Shark is usually docile,\n"+
  "unless it is provoked ... or hungry.\n");
  set_race("shark");
  set_level(25);
  set_hp(850);
  set_ac(20);
  set_wc(30+random(15));
  set_al(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(40);
  set_a_chat_chance(40);
  load_chat("The Great Shark swims dangerously close to you.\n");
  load_chat("Great Shark swims lazily through the waters.\n");
  load_chat("A school of colorful fish swim in front of you.\n");
  load_chat("Bubbles squiggle past you as they float upwords.\n");
  load_chat("The Great Shark looks at you curiously.\n");
  load_chat("A Beautiful Angelfish swims past you.\n");
  load_chat("Great Shark wanders aimlessly through the water.\n");
  load_a_chat("The Great Shark snaps his jaws at you!\n");
  load_a_chat("A school of colorful fish swim in front of you.\n");
  load_a_chat("Great Shark tears at you with his sharp teeth!\n");
  load_a_chat("Great Shark tries to bite you in half!\n");
  load_a_chat("Bubbles squiggle past you as they float upwords.\n");
  load_a_chat("The Great Shark tries to devour you!\n");
  call_out("go_move", 20);
  message_hit = ({
    "nearly DEVOURS", " in a single bite",
    "snaps its huge jaws down on", "",
    "bashes", " with a swing of its heavy tail",
    "nearly amputates a limb from", "",
    "gashes", " with its huge teeth",
    "gnaws on", "",
    "nicks", "",
  });
  enable_commands();
}

id(str) {
  return str == "shark" || str == "great shark" || str == "great_shark" ||
  str == "ilstkarn_monster";
}

init() {
  ::init();
  if(this_player()->is_player()) {
    if(!this_object()->query_attack() && !random(5)) {
      call_out("kill_it", 5, this_player());
    }
  }
}

kill_it(ob) {
  if(ob && present(ob, environment(this_object()))) {
    this_object()->attack_object(ob);
  }
  return 1;
}

go_move() {
  int i;

  if(this_object()->query_attack() && !random(4)) {
    devour();
    return 1;
  }

  i = random(4);
  if(i==0) command("north");
  if(i==1) command("south");
  if(i==2) command("east");
  if(i==3) command("west");
  call_out("go_move", 30+random(60));
  return 1;
}

devour() {
  object obj;

  obj = this_object()->query_attack();

  if(!obj || !present(obj, environment(this_object()))) {
    return 1;
  }

  tell_room(environment(obj),
  "\n"+
  HIY+"     The Great Shark DEVOURS "+IT+" with one swift bite!\n"+NORM+
  "\n");
  move_object(obj, "players/pavlik/ilstkarn/shark_belly");
  return 1;
}

monster_died() {
  object ob;
  int i;

  ob = clone_object("players/pavlik/items/ilstkarn/eaten_corpse");

  i = random(5);
  if(i==0) move_object(clone_object("players/pavlik/items/blue_potion"), ob);
  if(i==1) move_object(clone_object("players/pavlik/items/clear_potion"), ob);
  if(i==2) move_object(clone_object("players/pavlik/items/red_potion"), ob);
  if(i==3) move_object(clone_object("players/pavlik/items/green_potion"), ob);
  if(i==4) move_object(clone_object("players/pavlik/items/black_potion"), ob);

  move_object(clone_object("players/pavlik/armor/rusty_plate"), ob);
  move_object(clone_object("obj/money"), ob);
  present("money", ob)->set_money(1000+random(2000));
  move_object(ob, present("corpse", environment(this_object())));

  ("players/pavlik/ilstkarn/shark_belly")->eject_all(environment(this_object()));

  if(this_player()->query_real_name())
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" killed the Great Shark. ["+ctime()+"]\n");

  return 0;
}

