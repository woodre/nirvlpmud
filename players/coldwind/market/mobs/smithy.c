/*
File: shpkpr.c
Author: Feldegast @ nirvana
Date: ?/?/?
      2/14/01 Comments added
Description:
  A simple shopkeeper who sells armor and weapons at the coliseum.
*/
#define ARM_PATH "/players/coldwind/market/weapons/"
#include "/players/coldwind/define.h"
/* Physical Characteristics */
id(str) {
  return str=="smithy" ||
         str=="helal" ||
         str=="shopkeeper";
}

short() {
  return "Helal, the smithy";
}

long() {
  write(
    "An old smithy stands in his sweat working with a heavy hammer.\n"+
    "You can 'ask' him for a list of what he sells.\n");
}

/* Add verbs */
init() {
  add_action("cmd_menu","ask");
  add_action("cmd_menu","list");
  add_action("cmd_buy","buy");
  add_action("cmd_buy","purchase");
}

cmd_menu() {
  write("The shopkeeper sells the following:\n\n"+
        "              1. A wooden stick             1600 coins\n"+
        "              2. A bow and fire arrows      3000 coins\n"+
        "              3. A dark dagger              5000 coins\n"+
        "              4. Husam the boardsword      10000 coins\n"+
        ""
  );
  return 1;
}

/* The buy command */
cmd_buy(str) {
  object ob;
  string file;
  int value;
 
  if (!str) {
    write("The shopkeeper asks: What do you want to buy?\n");
    return 1;
  }

  switch(str) {
    case "1":
    case "stick":
      value=1600;
      file=ARM_PATH+"stick.c";
      break;
    case "2":
    case "bow":
      value=3000;
      file=ARM_PATH+"bow.c";
      break;
    case "3":
    case "dagger":
      value=5000;
      file=ARM_PATH+"dagger.c";
      break;
    case "4":
    case "husam":
	case "broadsword":
	case "sword":
      value=10000;
      file=ARM_PATH+"sword.c";
      break;
    default:
      write("The shopkeeper says: Sorry, i'm afraid we don't carry that.\n");
      return 1;
      break;
  }
  if(this_player()->query_money() < value) {
    write("You don't have enough money.\n");
    return 1;
  }

  /* If there's no file, then the player is buying a full set of armor. */
  if(file) { 
    ob=clone_object(file);
    if(!this_player()->add_weight( ob->query_weight() )) {
      destruct(ob);
      return 1;
    }
    this_player()->add_money(-value);
    move_object(ob,tp);
    write("You buy "+ob->short()+" for "+value+" coins.\n");
    say(tpn+" buys "+ob->short()+".\n");
    return 1;
  }
}
