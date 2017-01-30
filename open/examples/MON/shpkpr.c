/*
File: shpkpr.c
Author: Feldegast @ nirvana
Date: ?/?/?
      2/14/01 Comments added
Description:
  A simple shopkeeper who sells armor and weapons at the coliseum.
*/
#define ARM_PATH "/players/feldegast/equip/"
#define WEP_PATH "/players/feldegast/wep/"
#include "/players/feldegast/defines.h"

/* Physical Characteristics */
id(str) {
  return str=="vendor" ||
         str=="merchant" ||
         str=="shopkeeper";
}

short() {
  return "A shopkeeper";
}

long() {
  write(
    "A tall merchant standing behind a wooden counter.\n"+
    "You can 'ask' him for a list of what he sells.\n"
  );
}

/* Add verbs */
init() {
  add_action("cmd_menu","ask");
  add_action("cmd_menu","list");
  add_action("cmd_buy","buy");
  add_action("cmd_buy","purchase");
  add_action("cmd_read","read");
}

cmd_menu() {
  write("The vendor sells the following:\n\n"+
        "              1. A leather gauntlet        75 coins\n"+
        "              2. A pair of boots          100 coins\n"+
        "              3. A green cloak            100 coins\n"+
        "              4. A crystal amulet         100 coins\n"+
        "              5. A plumed helmet          125 coins\n"+
        "              6. A steel shield           300 coins\n"+
        "              7. A suit of scale mail     900 coins\n"+
        "              8. Set of armor (all)      1800 coins\n"+
        "              9. Quarterstaff            1000 coins\n"+
        "             10. Halberd                 3000 coins\n"+
        "             11. Backpack                 800 coins\n"+
        "             12. Lamp                     200 coins\n"+
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
    case "gauntlet":
      value=75;
      file=ARM_PATH+"gauntlet.c";
      break;
    case "2":
    case "boots":
      value=100;
      file=ARM_PATH+"boots.c";
      break;
    case "3":
    case "cloak":
      value=100;
      file=ARM_PATH+"cloak.c";
      break;
    case "4":
    case "amulet":
      value=100;
      file=ARM_PATH+"amulet.c";
      break;
    case "5":
    case "helmet":
    case "helm":
      value=125;
      file=ARM_PATH+"helmet.c";
      break;
    case "6":
    case "shield":
      value=300;
      file=ARM_PATH+"shield.c";
      break;
    case "7":
    case "mail":
    case "armor":
      value=900;
      file=ARM_PATH+"mail.c";
      break;
    case "8":
    case "all": /* Special case for buying a full set of armor. */
      value=1800;
      break;
    case "9":
    case "staff":
    case "quarterstaff":
      value=1000;
      file=WEP_PATH+"staff.c";
      break;
    case "10":
    case "halberd":
      value=3000;
      file=WEP_PATH+"halberd.c";
      break;
    case "11":
    case "backpack":
      value=800;
      file=ARM_PATH+"backpack.c";
      break;
    case "12":
    case "lamp":
      value=200;
      file="/players/feldegast/obj/lamp.c";
      break;
    default:
      write("The shopkeeper says: I don't sell that.\n");
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
    move_object(ob,TP);
    write("You buy "+ob->short()+" for "+value+" coins.\n");
    say(TPN+" buys "+ob->short()+".\n");
    return 1;
  }

  else { /* Buy a full set of armor. */
    if(!this_player()->add_weight(11)) {
      write("You cannot carry that much!\n");
      return 1;
    }
    this_player()->add_money(-value);
    move_object(clone_object(ARM_PATH+"gauntlet"),TP);
    move_object(clone_object(ARM_PATH+"boots"),TP);
    move_object(clone_object(ARM_PATH+"cloak"),TP);
    move_object(clone_object(ARM_PATH+"amulet"),TP);
    move_object(clone_object(ARM_PATH+"helmet"),TP);
    move_object(clone_object(ARM_PATH+"shield"),TP);
    move_object(clone_object(ARM_PATH+"mail"),TP);
    write("You buy a full set of armor for "+value+" coins.\n");
    say(TPN+" buys a full set of armor.\n");
    return 1;
  }
}

cmd_read(str) {
  notify_fail("Read what?\n");
  if(str!="sign") return 0;
  menu();
  return 1;
}
