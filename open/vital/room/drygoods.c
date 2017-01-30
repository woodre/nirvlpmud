/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   1/4/01            */
/*    Realm:      Spaceport         */
/************************************/

#include "/players/vital/closed/headers/vital.h"     /*color header */
#include "/players/vital/dest/include/dest.h"  /*area header */

inherit "room/room";
object guard;

reset(arg) {
  if(!present("trooper",TO)) {
    guard = CO(NPC+"dtroops.c");
    MO(guard,TO);
  }
  if(!present("shopkeeper",TO)) {
    guard = CO(NPC+"shopkeep.c");
    MO(guard,TO);
  }
  if(!arg) {

set_light(1);

short_desc = "Drygoods Store";
long_desc =
  "  The Acadie Drygoods Store\n\
Welcome to the Drygoods Store. Here and there are various and sundry \n\
items. This shop is where all the greatest items are provided for the \n\
people of Acadie. The shelves are short and the room looks like it is \n\
used regularly. The clothing in the bins looks like it has been looked \n\
through. There is a counter along the back wall. The light is provided \n\
by small globes along the ceiling.\n ";

items = ({
  "store",
  "This is a rather old-fashioned looking store",
  "clothing",
  "The clothing here is designed to help you in your adventures",
  "here",
  "This is the best shop for expensive trinkets",
  "items",
  "There are camping, clothing and other things here",
  "taxes",
  "You are outraged at the rising inflation endemic in the world",
  "bins",
  "These small, wooden cubby holes store most all the clothing in the store",
  "nirvana",
  "From a shuttle it is said you can see the whole mud",
  "light",
  "You will go blind if you look at these "+BOLD+WHT+"bright"+NORM+YEL+" lights"+NORM,
  "globes",
  "You will go blind if you look at these "+BOLD+WHT+"bright"+NORM+YEL+" lights"+NORM,
  "people",
  "The colonists who settled here on Acadie are a hardy bunch of people",
  "shelves",
  "These are short, squat wooden shelves that have small bins built into them",
  "merchandise",
  "Everything here is of the highest quality",
  "future",
  "Everyone always wants to look into the future",
  "shuttle",
  "The standard rho-field transportation vessel used at the N.U.T.S. Their\n\
arrivals and departures are recorded on the display",
  "sign",
  "If you \'read\' the sign, you might learn more",
  "counter",
  "A wide, "+BOLD+RED+"oak"+NORM+" counter where the merchandise is purchased"
});

dest_dir = ({
    ACADIE+"room/sidewalk3.c","out"
  });

  }
}

object item;
int value;

init() {
  ::init();
  add_action("search_me","search");
  add_action("read_sign","read");
  add_action("buy_me","buy");
}

read_sign(str) {
  if(!str) {
    notify_fail("What are you trying to read?\n");
    return 0;
  }
  else if(str == "sign") {
    write("     Buy Now And Save ! ! !\n\n");
    write("  Jumpsuit         760 coins \n\n");
    write("  Muk-luks          90 coins \n\n");
    write("  Belt              45 coins \n\n");
    write("  Stocking Cap     200 coins \n\n");
    write("  Hockey Gloves     65 coins \n\n");
    write("  Down Jacket      170 coins \n\n");
    write("  Sunglasses       135 coins \n\n");
    write("  Other survival gear can be \n");
    write("  special ordered from Vital \n");
  }
  return 1;
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else write("You search the "+str+" but find nothing.\n");
  return 1;
}

make_jumpsuit() {
    item = CO("/obj/armor.c");
    item->set_name("jumpsuit");
    item->set_alias("suit");
    item->set_short("All-purpose Jumpsuit");
    item->set_long("This all-purpose jumpsuit is designed to protect \npeople from the general elements of the world as they travel. \nThe fabric is a light, synthetic blend that offers \nprotection from the elements.\n");
    item->set_value(500+random(185));
    item->set_weight(1);
    item->set_ac(2);
    item->set_type("armor");
    return item;
}

make_muk_luks() {
    item = CO("/obj/armor.c");
    item->set_name("mukluks");
    item->set_alias("muk-luks");
    item->set_short("A warm pair of muk-luks");
    item->set_long("These wonderful, warm, furry boots cover your feet.\n");
    item->set_value(50+random(50));
    item->set_weight(1);
    item->set_ac(1);
    item->set_type("boots");
    return item;
}

make_belt() {
    item = CO("/obj/armor.c");
    item->set_name("leather belt");
    item->set_alias("belt");
    item->set_short("A Leather Belt");
    item->set_long("This long, leather belt will help to keep your pants up, and your shirt-tail down.\n");
    item->set_value(45+random(5));
    item->set_weight(1);
    item->set_ac(1);
    item->set_type("shield");
    return item;
}

make_cap() {
    item = CO("/obj/armor.c");
    item->set_name("stocking cap");
    item->set_alias("cap");
    item->set_short("A warm Stocking Cap");
    item->set_long("This is a warm, woolen-blend stocking cap to keep your head warm.\n");
    item->set_value(175+random(50));
    item->set_weight(1);
    item->set_ac(1);
    item->set_type("helmet");
    return item;
}

make_gloves() {
    item = CO("/obj/armor.c");
    item->set_name("hockey gloves");
    item->set_alias("gloves");
    item->set_short("A pair of Hockey Gloves");
    item->set_long("These warm gloves also could provide you with protection.\n");
    item->set_value(55+random(30));
    item->set_weight(1);
    item->set_ac(1);
    item->set_type("ring");
    return item;
}

make_jacket() {
    item = CO("/obj/armor.c");
    item->set_name("down jacket");
    item->set_alias("jacket");
    item->set_short("A toasty Down Jacket");
    item->set_long("This coat is stuffed full of goose down and will keep you warm in the cooler temperatures.\n");
    item->set_value(125+random(50));
    item->set_weight(1);
    item->set_ac(1);
    item->set_type("misc");
    return item;
}

make_glasses() {
    item = CO("/obj/armor.c");
    item->set_name("sunglasses");
    item->set_alias("glasses");
    item->set_short("A pair of Sunglasses");
    item->set_long("These cool, black Oakleys will protect your sight.\n");
    item->set_value(120+random(50));
    item->set_weight(1);
    item->set_ac(1);
    item->set_type("amulet");
    return item;
}


buy_me(str) {
  if(!str) {
    read_sign("sign");
    notify_fail("What is it that you are trying to buy?\n");
    return 0;
  }
  else switch(str) {
    case "suit":
    case "jumpsuit":
      make_jumpsuit();
      value = 720+random(60);
      checks_and_balances(str);
     break;
    case "mukluks":
    case "muk-luks":
    case "boots":
    case "shoes":
      make_muk_luks();
      value = 60+random(50);
      checks_and_balances(str);
      break;
    case "belt":
      make_belt();
      value = 40+random(10);
      checks_and_balances(str);
      break;
    case "cap":
    case "stocking cap":
      make_cap();
      value = 190+random(35);
      checks_and_balances(str);
      break;
    case "gloves":
    case "hockey gloves":
      make_gloves();
      value = 40+random(10);
      checks_and_balances(str);
      break;
    case "jacket":
    case "down jacket":
    case "coat":
      make_jacket();
      value = 150+random(50);
      checks_and_balances(str);
      break;
    case "glasses":
    case "sunglasses":
    case "sun glasses":
      make_glasses();
      value = 40+random(10);
      checks_and_balances(str);
      break;
    default :
      write("You cannot buy "+str+" here. Mail Vital if you think you need it.\n");
  }
  return 1;
}

checks_and_balances(str) {
  if(TP->query_money() < value) {
    write("You don't have enough money to buy the "+str+".\n");
    return 1;
  }
  if(!TP->add_weight(item->query_weight())) {
    write("You are already carrying too much to carry the"+str+".\n");
    return 1;
  }
  MO(item,TP);
  TP->add_money(-value);
  write("You purchase the "+str+" for "+value+".\n");
  say(CTPN+" purchases "+str+".\n");
  return 1;
}
