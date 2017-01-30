#pragma strong_types

#include "/obj/door.h"
#define MUST_STAY_WITH_DRINKS

inherit "room/room";

void
reset(status arg) {
  object drunk, key_ob, amulet;
  
  if (!present("drunkard")) {
    drunk = clone_object("obj/monster");
    drunk->set_name("drunkard");
    drunk->set_short("The drunkard");
    drunk->set_level(14);
    drunk->set_hp(150);
    drunk->set_wc(12);
    drunk->set_ac(5);
    drunk->set_al(20);
    drunk->load_chat(13,({
      "The drunkard says:  I've schlayed many dragonsch in my life!\n",
      "The drunkard says:  I'm a great dragonschlayer!\n",
      "The drunkard says:  I know of a big dragon in the mountainsch "+
      "nearby.\nI'm gonna kill him today, but I muscht have another beer "+
      "first.\n" }));
    drunk->load_a_chat(40, ({
      "The drunkard says:  Schtop that!\n",
      "The drunkard says:  What do you think you're doing?\n",
      "The drunkard holds the beer in one hand while he tries to hit you \n"+
      "with his other hand.\n" }));
    amulet = clone_object("obj/armor");
    amulet->set_name("amulet");
    amulet->set_short("A small amulet");
    amulet->set_long("It is a beautiful stone in a necklace.\n");
    amulet->set_value(100);
    amulet->set_type("amulet");
    move_object(amulet, drunk);
    move_object(drunk, this_object());
    if (!present("key", drunk)) {
/* Macro is crap! - doing the better way - Rumplemintz
      MAKE_KEY(key_ob, "big", "auxd") */
      key_ob = clone_object("obj/key");
      key_ob->set_type("bronze");
      key_ob->set_code("auxd");
      move_object(key_ob, drunk);
    }
  }
  if (arg)
    return;
  set_light(1);
  short_desc = "The inn Laughing Horse";
  long_desc =
"You are in the inn Laughing Horse.\n" +
"You can order drinks here.\n\n" +
"     A large beer                    : 12 coins\n" +
"     Whiskey on the rocks            : 50 coins\n" +
"     The doctor's special mixture    : 150 coins\n\n"+
#if 0 /* Rumplemintz - this looks funny */
"The only obvious exit is to " + "west" + ".\n\n";
#else
"\n\n";
#endif
  dest_dir = ({
    "players/angmar/fairyland/road2", "west"
  });
}  

string realm() { return ("NT"); }

void
init() {
  room::init();
  add_action("west", "west");
  add_action("order", "order");
  add_action("order", "buy");
}

status
has_drink(object obj) {
  status drink;
  object ob;

  ob = first_inventory(obj);
  while(ob) {
    if (ob->id("drk2"))
      drink = 1;
    if (ob->can_put_and_get()) {
      if (has_drink(ob))
        drink = 1;
    }
    ob = next_inventory(ob);
  }
  return drink;
}

status
west() {
  if (has_drink(this_player())) {
    tell_object(this_player(), "You are not allowed to leave with drinks!\n");
    return 1;
  }
  return 0;
}

status
order(string str) {
  object drink;
  string name, short_desc, mess;
  int value, cost, strength, heal;

  if (!str) {
    write("Order what ?\n");
    return 1;
  }
  if (str == "beer") {
    name = str;
    short_desc = "A large beer";
    mess = "Wow, best beer you've ever tasted";
    heal = 0;
    value = 12;
    strength = 2;
  }
  else if (str == "whisky" || str == "whiskey") {
    name = "whiskey";
    short_desc = "A whiskey on the rocks";
    mess = "Steam comes out of your ears";
    heal = 10;
    value = 50;
    strength = 8;
  } else if (str == "mixture" || str == "special") {
    name = "mixture";
    short_desc = "Doctor's special mixture";
    mess = "Your guts catch fire";
    heal = 25;
    value = 150;
    strength = 12;
  } else {
    write("What ?\n");
    return 1;
  }
  if (this_player()->query_money() < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  drink = clone_object("obj/drink");
  if (!this_player()->add_weight(drink->query_weight())) {
    write("You can't carry more.\n");
    destruct(drink);
    return 1;
  }
  if (!drink->set_value(name+"#"+short_desc+"#"+mess+"#"+heal+"#"+value+"#"+
                        strength)) {
    write("Error in creating drink.\n");
    destruct(drink);
    return 1;
  }
  drink->set_pub();
  move_object(drink, this_player());
  this_player()->add_money(-value);
  write("You pay " + value + " for a " + name + ".\n");
  say(this_player()->query_name()+" orders a "+name+ ".\n");
  return 1;
}
