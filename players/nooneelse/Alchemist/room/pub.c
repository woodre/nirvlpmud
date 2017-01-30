/*
  alchemist_pub.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "room/room";
inherit "/players/nooneelse/Alchemist/room/rooms.c";

object trashcan, ob, drink, food, bartender, towel;
string str, str2, name, booze_short_desc, food_short_desc, mess;
int value, cost, strength, heal, weight;

init() {
  ::init();

  add_action("read_sign",      "read");
  add_action("leave_here",     "east");
  add_action("order",          "order");
  add_action("order",          "buy");
  add_action("kill_bartender", "kill");
  add_action("kill_bartender", "hit");
  add_action("kill_bartender", "slap");
  add_action("kill_bartender", "kick");
  add_action("kill_bartender", "spit");
}

read_sign(str) {
  if (!str) return;
  str2=0;
  sscanf(str, "at %s", str2);
  if (str=="sign" || str2=="sign") {
    command("look at sign", this_player());
    return 1;
  }
}

leave_here() {
  drink=0;
  if (has_drink(this_player())) {
    tell_object(this_player(), "You are not allowed to leave with drinks!\n");
    return 1;
  }
  food=0;
  if (has_food(this_player())) {
    tell_object(this_player(), "You are not allowed to leave with food!\n");
    return 1;
  }
  return;
}

order(str) {
  if (!str) {
    write("What'll you have friend?\n");
    return 1;
  }
  if (str=="beer"   || str=="tequila"  || str=="boilermaker") order_booze(str);
  if (str=="grapes" || str=="cheese"   || str=="lobster") order_food(str);
/*  if (str=="coffee" || str=="espresso" || str=="potion") order_sober(str);*/
  if (str=="coffee" || str=="espresso") order_sober(str);
  return 1;
}

/* -------------------------  booze --------------------------- */
order_booze(str) {
  if (str != "beer" && str != "tequila" && str != "boilermaker") {
    write("Sorry, we don't carry "+str+".\n");
    return 1;
  }
  if (str=="beer") {
    name="beer";
    booze_short_desc="a cold beer";
    mess="Yeah! Best beer you've ever tasted";
    heal=1;
    value=12;
    strength=2;
  }
  else
  if (str=="tequila") {
    name="tequila";
    booze_short_desc="a shot of tequila";
    mess="You shiver from the shock";
    heal=14;
    value=210;
    strength=8;
  }
  else
  if (str=="boilermaker") {
    name="boilermaker";
    booze_short_desc="a boilermaker";
    mess="Your guts catch fire and steam comes from your ears";
    heal=22;
    value=250;
    strength=12;
  }
  if (this_player()->query_money() < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  drink=clone_object("obj/drink");
  if (!this_player()->add_weight(drink->query_weight())) {
    write("You can't carry more.\n");
    destruct(drink);
    return 1;
  }
  if (!call_other(drink,"set_value",name+"#"+booze_short_desc+"#"+
      mess+"#"+heal+"#"+value+"#"+strength)) {
    write("Error in creating drink.\n");
    destruct(drink);
    return 1;
  }
  call_other(drink, "set_pub");
  move_object(drink, this_player());
  call_other(this_player(), "add_money", - value);
  write("You pay "+value+" for a "+name+".\n");
  say(this_player()->query_name()+" orders a "+name+".\n");
  return 1;
}

has_drink(obj) {
  status drink;
  object ob;
  ob=first_inventory(obj);
  while(ob) {
    if (call_other(ob, "id", "drk2")) drink=1;
    if (call_other(ob,"can_put_and_get")) { if (has_drink(ob)) drink=1; }
    ob=next_inventory(ob);
  }
  return drink;
}

/* -------------------  sober (coffee, espresso, etc) --------------------- */
order_sober(str) {
/*  if (str != "coffee" && str != "espresso" && str != "potion") {*/
  if (str != "coffee" && str != "espresso") {
    write("Sorry, we don't carry "+str+".\n");
    return 1;
  }
  if (str=="coffee") {
    name="coffee";
    booze_short_desc="a hot cup of coffee";
    mess="Ahhh!  Best coffee you've ever tasted";
    heal=0;
    value=80;
    strength=-4;
  }
  else
  if (str=="espresso") {
    name="espresso";
    booze_short_desc="a cup of espresso";
    mess="You shiver with delight at the taste";
    heal=0;
    value=120;
    strength=-6;
  }
/*
  else
  if (str=="potion") {
    name="potion";
    booze_short_desc="a healing potion";
    mess="You shiver and shake for a second";
    heal=200;
    value=10000;
    strength=0;
  }
*/
  if (this_player()->query_money() < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  drink=clone_object("obj/drink");
  if (!this_player()->add_weight(drink->query_weight())) {
    write("You can't carry more.\n");
    destruct(drink);
    return 1;
  }
  if (!call_other(drink,"set_value",name+"#"+booze_short_desc+"#"+mess+
      "#"+heal+"#"+value+"#"+strength)) {
    write("Error in creating drink.\n");
    destruct(drink);
    return 1;
  }
  call_other(drink, "set_pub");
  move_object(drink, this_player());
  call_other(this_player(), "add_money", - value);
  write("You pay "+value+" for a "+name+".\n");
  say(this_player()->query_name()+" orders a "+name+".\n");
  return 1;
}

/* -------------------------  food --------------------------- */
order_food(str) {
  if (str != "grapes" && str != "cheese" && str != "lobster") {
    write("Sorry, we don't carry "+str+".\n");
    return 1;
  }
  if (str=="grapes") {
    name="grapes";
    food_short_desc="a small bunch of chilled grapes";
    mess="Mmmm!  Those were sweet.\n";
    value=120;
    strength=2;
    weight=1;
  }
  else
  if (str=="cheese") {
    name="cheese";
    food_short_desc="a nice wedge of cheddar cheese";
    mess="Oh yes!  That hit the spot.\n";
    value=600;
    strength=10;
    weight=1;
  }
  else
  if (str=="lobster") {
    name="lobster";
    food_short_desc="a large rock lobster done to perfection";
    mess="Your tastebuds scream with pleasure!\n";
    value=1500;
    strength=25;
    weight=2;
  }
  if (this_player()->query_money() < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  food=clone_object("obj/food");
  food->set_name(name);
  food->set_alias("food");
  food->set_short(food_short_desc);
  food->set_value(value);
  food->set_weight(weight);
  food->set_strength(strength);
  food->set_eater_mess(mess);
  if (!this_player()->add_weight(food->query_weight())) {
    write("You can't carry more.\n");
    destruct(food);
    return 1;
  }
  move_object(food, this_player());
  call_other(this_player(), "add_money", - value);
  write("You pay "+value+" for a "+name+".\n");
  say(this_player()->query_name()+" orders a "+name+".\n");
  return 1;
}

has_food(obj) {
  status food;
  object ob;
  ob=first_inventory(obj);
  while(ob) {
    if (call_other(ob, "id", "food")) food=1;
    if (call_other(ob,"can_put_and_get")) { if (has_food(ob)) food=1; }
    ob=next_inventory(ob);
  }
  return food;
}

kill_bartender(str) {
  if (!str) return;
  if (str != "bartender" && str != "waiter") return;
  bartender=present("bartender");
  if(!bartender) {
    bartender=clone_object("obj/monster");
    bartender->set_name("bartender");
    bartender->set_level(14);
    bartender->set_hp(125);
    bartender->set_wc(10);
    bartender->set_ac(5);
    bartender->set_short("the bartender");
    bartender->set_al(0);
    bartender->load_a_chat(
        "The bartender says: I've had enough of this!  Get out!\n");
    bartender->load_a_chat(
        "The bartender says: I'm going to call the guard!\n");
    bartender->load_a_chat(
        "The bartender says: I'll clobber you!\n");
    bartender->load_a_chat("The bartender says: Knock it off bub!\n");
    bartender->load_a_chat(
        "The bartender says: What do you think you're doing?\n");
    bartender->load_a_chat(
        "The bartender holds a tequila bottle in one hand while he tries to\n"+
        "snap you with his towel.\n");
    bartender->set_a_chat_chance(40);
    towel=clone_object("obj/weapon");
    towel->set_name("towel");
    towel->set_class(5);
    towel->set_weight(1);
    towel->set_value(50);
    towel->set_short("a towel");
    towel->set_long("It is a dirty, damp towel.\n");
    move_object(towel,bartender);
    drink=clone_object("obj/drink");
    name="tequila";
    booze_short_desc="a shot of tequila";
    mess="You shiver from the shock";
    heal=10;
    value=50;
    strength=8;
    call_other(drink,"set_value",name+"#"+booze_short_desc+"#"+mess+"#"+
               heal+"#"+value+"#"+strength);
    move_object(drink, bartender);
    move_object(bartender,"players/nooneelse/restaurant");
    bartender->init_command("wield towel");
    bartender->init_command("drink tequila");
    bartender->attacked_by(this_player());
    return 1;
  }
  return;
}


reset(arg) {
  if (arg) return;

  set_light(1);
  no_castle_flag=1;
  short_desc=("Nooneelse's College Bar");
  long_desc=
    "This is a well lit, extremely comfortable, exclusive bar.\n"+
    "There is a well dressed, snooty waiter/bartender standing in a corner.\n"+
    "You notice that most of the light is provided by a sign on the wall.\n";
  items =
    ({
      "bartender", "He's standing there with a towel over his arm chewing "+
                   "gum, drinking from a\n"+
                   "bottle & looking bored.",
      "waiter", "He's standing there with a towel over his arm chewing gum, "+
                "drinking from a\n"+
                "bottle & looking bored.",
      "sign", "It's lights are so bright, tiey light up the entire room with "+
              "a soft glow.\n"+
              "A lighted sign reads:\n\n"+
              "\n"+
              "Welcome to the Rainbow Inn\n"+
              "\n"+
              "A bunch of grapes      120 coins\n"+
              "A piece of cheese      600 coins\n"+
              "Lobster                    1500 coins\n"+
              "\n"+
              "A cold beer                12 coins\n"+
              "A shot of tequila         210 coins\n"+
              "A boilermaker             250 coins\n"+
              "\n"+
              "A cup of coffee               80 coins\n"+
              "A cup of espresso         120 coins\n"+
              "\n"+
              "NOTICE:  Prices are subject to change\n"+
              "         without notice\n"+
              "\n",
    });
  dest_dir=
    ({
      ALCHEMIST_LOBBY, "east",
    });
/*
  if (!present("nooneelsetrashcan"))
    move_object(clone_object("players/nooneelse/obj/trashcan"), this_object());
  if (!present("poker machine"))
    move_object(clone_object("players/nooneelse/obj/poker_machine"),
                this_object());
*/
}