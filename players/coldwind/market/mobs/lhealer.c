/*
File: shpkpr.c
Author: Feldegast @ nirvana
Date: ?/?/?
      2/14/01 Comments added
Description:
  A simple shopkeeper who sells armor and weapons at the coliseum.
*/
#define ARM_PATH "/players/coldwind/market/items/"
#include "/players/coldwind/define.h"
/* Physical Characteristics */
id(str) {
  return str=="kassam" ||
         str=="merchant" ||
         str=="shopkeeper";
}

short() {
  return "Kassam, the merchant";
}

long() {
  write(
    "A tall man wears a simple white galabia. Kassam deiced to sell the most\n"+
    "favored food in bulk to be able to compete with the other shops in \n"+
	"the area. You can 'ask' him for a list of what he sells.\n");
}

/* Add verbs */
init() {
  add_action("cmd_menu","ask");
  add_action("cmd_menu","list");
  add_action("cmd_buy","buy");
  add_action("cmd_pur","purchase");
  
}

cmd_menu() {
  write("Kassam sells the following food in bulk:\n\n"+
        "   1. Cuctus root (HP)              4400 coins\n"+
        "   2. Small bag of garlic (SP)      3200 coins\n"+
        "   3. A bunch of brown leaves       3200 coins\n"+
        "   4. A bunch of green leaves       5000 coins\n"+
        "   5. A bunch of red leaves         7100 coins\n"+
        "   ===========================================\n"+
		"     You can also 'purchase' a light basket   \n"+
		"        here to put your food in for          \n"+
		"            1700 gold coins only!             \n"+
		"   ===========================================\n"+ 
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
    case "root":
      value=4400;
      file=ARM_PATH+"lroot.c";

      break;
    case "2":
    case "garlic":
      value=3200;
      file=ARM_PATH+"lgarlic.c";
      break;
    case "3":
    case "brown leaves":
      value=3200;
      file=ARM_PATH+"lbleaf.c";
      break;
    case "4":
    case "green leaves":
      value=5000;
      file=ARM_PATH+"lleaf.c";
      break;
    case "5":
    case "red leaves":
      value=7100;
      file=ARM_PATH+"lrleaf.c";
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
  
  if(!present("basket", this_player())) { 
  write("You will need to purchase a basket to put your supplies in!\n"); 
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
    move_object(ob,present("basket",tp));

    write("You buy "+ob->short()+" for "+value+" coins.\n");
    say(tpn+" buys "+ob->short()+".\n");
    return 1;
  }
}
cmd_pur(str){

if (!str) {
       write("you can only purchase a basket\n");
       return 1;
	   }
      if (str == "basket") {
	  this_player()->add_money(-1700);
    move_object("/players/coldwind/market/items/basket.c",tp);
    write("You buy a light basket for 1700 coins.\n");
    say(tpn+" buys a light basket.\n");
    return 1;
  }
  }