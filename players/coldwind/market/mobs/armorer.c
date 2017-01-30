/*
File: shpkpr.c
Author: Feldegast @ nirvana
Date: ?/?/?
      2/14/01 Comments added
Description:
  A simple shopkeeper who sells armor and weapons at the coliseum.
*/
#define ARM_PATH "/players/coldwind/market/armor/"
#include "/players/coldwind/define.h"
/* Physical Characteristics */
id(str) {
  return str=="armorer" ||
         str=="shehab" ||
         str=="shopkeeper";
}

short() {
  return "Shehab, the armorer";
}

long() {
  write(
    "An old merchant stands behind a simple wooden counter.\n"+
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
  write("The armorer sells the following:\n\n"+
        "              1. A ruby jeweled ring       100 coins\n"+
        "              2. A pair of wide boots       75 coins\n"+
        "              3. A blue cloak              100 coins\n"+
        "              4. An emerald talisman       100 coins\n"+
        "              5. An arabian white aama     150 coins\n"+
        "              6. A steel buckler           200 coins\n"+
        "              7. A suit of dark chainmail 1000 coins\n"+
        "              8. A full armor set         1700 coins\n"+
        "              9. Light basket             1800 coins\n"+
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
    case "ring":
      value=100;
      file=ARM_PATH+"ring.c";
      break;
    case "2":
    case "boots":
      value=75;
      file=ARM_PATH+"boots.c";
      break;
    case "3":
    case "cloak":
      value=100;
      file=ARM_PATH+"cloak.c";
      break;
    case "4":
    case "talisman":
      value=100;
      file=ARM_PATH+"amulet.c";
      break;
    case "5":
    case "helmet":
    case "aama":
      value=150;
      file=ARM_PATH+"helmet.c";
      break;
    case "6":
    case "shield":
	case "buckler":
      value=200;
      file=ARM_PATH+"shield.c";
      break;
    case "7":
    case "mail":
	case "chainmail":
    case "armor":
      value=1000;
      file=ARM_PATH+"armor.c";
      break;
    case "8":
    case "all": /* Special case for buying a full set of armor. */
      value=1700;
      break;
    case "9":
    case "basket":
      value=1800;
      file="/players/coldwind/market/misc/basket.c";
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

  else { /* Buy a full set of armor. */
    if(!this_player()->add_weight(11)) {
      write("You cannot carry that much!\n");
      return 1;
    }
    this_player()->add_money(-value);
    move_object(clone_object(ARM_PATH+"ring"),tp);
    move_object(clone_object(ARM_PATH+"boots"),tp);
    move_object(clone_object(ARM_PATH+"cloak"),tp);
    move_object(clone_object(ARM_PATH+"amulet"),tp);
    move_object(clone_object(ARM_PATH+"helmet"),tp);
    move_object(clone_object(ARM_PATH+"shield"),tp);
    move_object(clone_object(ARM_PATH+"armor"),tp);
    write("You buy a full set of armor for "+value+" coins.\n");
    say(tpn+" buys a full set of armor.\n");
    return 1;
  }
}
