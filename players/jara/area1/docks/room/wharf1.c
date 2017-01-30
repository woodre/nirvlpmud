/* The Wharf Tavern, Created <5/2/00> by Jara */

#include "/players/jara/misc/ansi.h"
#include "defs.h"
inherit "room/room";

int peeps;

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="The Wharf Tavern";
  long_desc=
    "  The interior of The Wharf Tavern is a warm refuge from the salty\n"+
    "winds of the sea. A bar against the north wall spans the entire width\n"+
    "of the tavern, and several tables stand in the room. Behind the bar, a\n"+
    "row of kegs with small metal taps line the wall. The fireplace, built\n"+
    "into the eastern wall, has a dimly burning fire within, and a small\n"+
    "pile of logs have been placed to one side. A door in the southern wall\n"+
    "leads out to the boardwalk, and a menu hangs behind the bar.\n";
  items=({
    "menu",
    "*"+YEL+"----------------------------------------"+NORM+"*\n"+
    "*                                        *\n"+
    "*                                        *\n"+
    "*     A mug of ale              50 c     *\n"+
    "*     A shot of whiskey        150 c     *\n"+
    "*     Amelia's Rum Balls       250 c     *\n"+
    "*                                        *\n"+
    "*                                        *\n"+
    "*"+YEL+"----------------------------------------"+NORM+"*\n"+
    "      You can 'order' your pleasure",
    "bar",
    "Carved from a single log, the bar has been well crafted and polished to a\n"+
    "shine",
    "tables",
    "Wooden tables, lit by candles",
    "taps",
    "Silver in color, the metal taps have a handle and a spout. The taps are built\n"+
    "in the base of each keg",
    "kegs",
    "Massive wooden barrels with small metal taps extending from the base",
    "fireplace",
    "A brick fireplace with a small fire burning. A pile of ashes have been pushed\n"+
    "to either side of the fire",
    "fire",
    "A small, cheerfully burning fire",
    "logs",
    "The logs are round and freshly cut",
    "door",
    "A wooden door with a small, glass pane window. A curtain covers the window" });
  dest_dir=({
    PATH+"walk2","out" });
  if(!present("amelia")) {
    ob=clone_object("/players/jara/area1/docks/mon/amelia.c");
    move_object(ob,this_object());
  }
}

void init() {
  ::init();

  add_action("order","order");
  add_action("order","buy");
  peeps++;
  if(find_call_out("emotes") == -1)
    call_out("emotes",40+random(15));
}

void exit() {
  peeps--;
  if(peeps <= 0)
    while(remove_call_out("emotes") != -1) ;
}

void emotes() {
  object ob,next;
  string msg;

  switch(random(2)) {
    case 0: msg="The fire crackles.\n"; break;
    case 1: msg="The fire burns warmly...\n"; break;

  }
  tell_room(this_object(),msg);
  call_out("emotes",20+random(40));
}

order(str) {
  string name, short_desc, mess;
  int value, cost, strength, heal;

    if (str == "ale") {
    mess = "You order a mug of ale and drink it down";
    heal = 5;
    value = 50;
    strength = 14;
  }

    else if (str == "whiskey") {
    mess = "You order a shot of whiskey. The whiskey burns as you drink it";
    heal = 10;
    value = 150;
    strength = 10;
  }

    else if (str == "ball") {
    mess = "You order a rum ball. The sweet candy tastes of rum";
    heal = 20;
    value = 250;
    strength = 12;
  }
else {
    write("The barmaid smiles and says, 'What do you want to order?'\n");
  return 1;
  }
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
  return 1;
  }
    cost = value;
  if (strength > (call_other(this_player(), "query_level") + 2)) {
  if (strength > (call_other(this_player(), "query_level") + 5)) {
    say(call_other(this_player(), "query_name", 0) + " orders a " +
    str + ", and immediately throws up.\n");
    write("You order a " + str + ", try to drink it, and throw up.\n"); }
  else {
  say(call_other(this_player(), "query_name", 0) + " orders a " +
    str + ", and throws it up all over you!\n");
  write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
  }
  call_other(this_player(), "add_money", - cost);
  return 1;
 }
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("The barmaid smiles and says, 'I think you've had enough.'\n");
    say(call_other(this_player(), "query_name", 0) + " asks for a " +
    str + " but the barmaid refuses.\n");
  return 1;
  }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
