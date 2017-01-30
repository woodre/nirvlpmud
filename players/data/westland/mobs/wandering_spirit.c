 /*

File: shpkpr.c

Author: Feldegast @ nirvana
Edited: Data
Edited: 11/03/2003

Date: ?/?/?

      2/14/01 Comments added

Description:

  A simple shopkeeper who sells armor and weapons at the coliseum.

*/
#include <ansi.h>
#define SHOP_PATH "/players/data/OUTERB/SHOP/"
#define TP this_player()
#define TPN TP->query_name()

/* Physical Characteristics */

id(str) {
return str=="vendor" ||
         str=="spirit" ||
         str=="shopkeeper";
}

short() {
  return "A Wandering Spirit";
}

long() {
  write(
    "A swaying spirit who appears in the form of a.\n"+
    "merchant. Perhaps you should 'ask' him for a list.\n");

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
  write("The Spirit can sell the following:\n\n"+

	    "				ARMORS				                \n"+

        "         1. A Wooden Shield...............200 coins\n"+        

        "         2. A Pair of Soft Boots..........300 coins\n"+        

        "         3. A Cracked Amulet..............200 coins\n"+        

        "         4. A Cracked Ring................200 coins\n"+           

        "         5. A Rusty Helmet................400 coins\n"+

        "         6. A Shroud......................300 coins\n"+

        "         7. Cracked Armor.................800 coins\n"+

        "         8. Set of armor (all)............1100 coins\n"+

	    "				WEAPONS				                 \n"+

	    "         9. Tooth............(knife)......500 coins\n"+

	    "				HEALS					            \n"+

	    "        10. Tepid Water......(soak).......350 coins\n"+

	    "	11. Box of Bugs......(food).......350 coins\n"+

        "	12. Spirits be Fouled(alcohol)...600 coins\n"+



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
    write("The spirit asks: What do you want to buy?\n");
    return 1;
  }

  switch(str) {

    case "1":
    case "shield":
      value=75;
      file=SHOP_PATH+"wooden_shield.c";
      break;

    case "2":
    case "boots":
    value=100;
    file=SHOP_PATH+"soft_boots.c";
    break;

    case "3":
    case "amulet":
    value=100;
    file=SHOP_PATH+"cracked_amulet.c";
    break;

    case "4":
    case "ring":
    value=100;
    file=SHOP_PATH+"cracked_ring.c";
    break;

    case "5":
    case "helmet":
    case "helm":
    value=125;
    file=SHOP_PATH+"rusty_helmet.c";
    break;

    case "6":
    case "shroud":
    value=300;
    file=SHOP_PATH+"shroud.c";
    break;

    case "7":
    case "cracked armor":
    case "armor":
    value=900;
    file=SHOP_PATH+"cracked_armor.c";
    break;

    case "8":
    case "all": /* For buying one of each armor. */
    value=1100;
    break;

    case "9":
    case "tooth":
    case "knife":
    case "dagger":
    value=1000;
    file=SHOP_PATH+"tooth.c";
    break;

    case "10":
    case "water":
    case "tepid water":
    value=750;
    file=SHOP_PATH+"tepid_water.c";
    break;

    case "11":
    case "box":
    case "bugs":
    case "box of bugs":
    value=750;
    file=SHOP_PATH+"box_of_bugs.c";
    break;

    case "12":
    case "spirit":
    case "bottle":
    case "bottle of spirits":
    case "spirits be fouled":
    case "wine":
    value=750;
    file=SHOP_PATH+"spirits_be_fouled.c";
    break;

    default:
    write("The spirit says: I don't have that to sell.\n");
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
    write("You cannot carry that much, get rid of something!\n");
    return 1;
    }

    this_player()->add_money(-value);
    move_object(clone_object(SHOP_PATH+"wooden_shield"),TP);
    move_object(clone_object(SHOP_PATH+"soft_boots"),TP);
    move_object(clone_object(SHOP_PATH+"cracked_amulet"),TP);
    move_object(clone_object(SHOP_PATH+"cracked_ring"),TP);
    move_object(clone_object(SHOP_PATH+"rusty_helmet"),TP);
    write("You buy a full set of armor for "+value+" coins.\n"+
          "Please choose a main armor from the selection\n"+
          "either a Shroud, or cracked armor.\n");

    say(TPN+" buys a full set of armor.\n");
    return 1;
  }
}

cmd_read(str) {
  notify_fail("Why don't you try to <ask> this time?\n");
  if(str!="sign") return 0;
  write(HIK+"	  Hello traveler from a far away place. I am the Wandering spirit\n"+
        "My job is to provide you with the means to wander through this part of the\n"+
		"boundary and stay alive. You may 'ask' me for a list of my wares, and\n"+
		"never fear for if you bring an appetite, I have some food stuffs for you.\n"+
		"I also suggest taking a light with you for the darkness is immense.\n"+NORM);
  return 1;
}

