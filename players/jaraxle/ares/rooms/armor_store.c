#include "../define.h"

inherit ROOM;

#define tp this_player()



object owner;

string what;

int woot;

int cost, haggle, owner_int;

object item;

int *stock;



reset(arg) {

if(!present("armor_owner")){

	owner = clone_object("/players/jaraxle/ares/mobs/armor_owner.c");

	move_object(owner, this_object());

	}

  if(arg) return;

   set_light(1);

   set_short("The Emperor's Shield [Armorer]");

   set_long(

"  This is a large armor shop. The walls are lined with shelves and\n"+

"racks, each holding finely crafted items.  A small desk stands\n"+

"against the far wall of the shop. You can 'browse' the stores\n"+

"selection at any time.  A doorway leads out to the street.\n");

   add_item(

      "walls",

      "Stone walls that have numerous shelves and racks against them");

   add_item(

      "shelves",

      "Made of wood, these shelves hold numerous types of armor for sell");

   add_item(

      "racks",

      "Made of wood, these racks hold numerous types of armor for sell");

   add_item(

      "items",

      "Finely crafted armors that line the walls on shelves and racks");

   add_item(

      "desk",

      "A small desk that is used to conduct business");

   add_item(

      "doorway",

      "A doorway that leads out to the street");

   add_item(

      "street",

      "A stone road that winds through town");

   add_exit(ROOMS+"city15", "out"); 

   stock = ({random(10),random(6),random(2),random(8),random(3),random(10),random(9),

              random(5),random(3),random(10),random(8),random(5),random(4),random(2),

              random(10),random(9),random(8),random(5),random(3),random(2),});

}

init(){

    ::init();	

   add_action("browse_it", "browse");

   add_action("purchase_it","purchase");

   }



browse_it(){

  write(

  "\n"+

  "   .___________ [ The Emperor's Shield ] ____________.\n"+

  "   | #  TYPE:                      COST:    STOCK:   |\n"+

  "   | 1  Leather Gloves              100       "+stock[0]+"      |\n"+

  "   | 2  Chain Gloves                250       "+stock[1]+"      |\n"+

  "   | 3  Platemail Gloves            500       "+stock[2]+"      |\n"+

  "   | 4  Leather Boots               120       "+stock[3]+"      |\n"+

  "   | 5  Platemail Boots             500       "+stock[4]+"      |\n"+

  "   | 6  Mask                         50       "+stock[5]+"      |\n"+

  "   | 7  Helm                        200       "+stock[6]+"      |\n"+

  "   | 8  Full Helm                   350       "+stock[7]+"      |\n"+

  "   | 9  Great Helm                  500       "+stock[8]+"      |\n"+

  "   | 10 Buckler Shield              150       "+stock[9]+"      |\n"+

  "   | 11 Small Shield                250       "+stock[10]+"      |\n"+

  "   | 12 Large Shield                500       "+stock[11]+"      |\n"+

  "   | 13 Kite Shield                 550       "+stock[12]+"      |\n"+

  "   | 14 Tower Shield                800       "+stock[13]+"      |\n"+

  "   | 15 Leather Armor               800       "+stock[14]+"      |\n"+

  "   | 16 Studded Leather Armor      1000       "+stock[15]+"      |\n"+

  "   | 17 Chain Mail                 2000       "+stock[16]+"      |\n"+

  "   | 18 Breast Plate               2200       "+stock[17]+"      |\n"+

  "   | 19 PlateMail Armor            3800       "+stock[18]+"      |\n"+

  "   | 20 Field Plate Armor          7000       "+stock[19]+"      |\n"+

  "   ._________________________________________________.\n"+

  "   'purchase #' to buy a piece of armor. \n");

  return 1;

}



purchase_it(string str){

	int purchase;

      item = 0;

      item = clone_object("/players/jaraxle/ares/armor/base_armor.c");

      item->set_save_flag(1);

	purchase = str;

 if(!present("armor_owner", this_object())){

 	write("You don't see the store owner here.\n");

 	return 1;

 	}

	if(!purchase){ write("Usage: purchase #\n"); return 1; }

	if(purchase == "1"){

        if(!stock[0]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 0;

        cost = 100;

        item->set_short("Leather Gloves");

        item->set_long(

        "This is a pair of tough leather gloves. They will resist\n"+

        "most types of minor damage.\n");

        item->set_weight(1);

        item->set_value(100);

        item->set_ac(1);

        item->set_type("ring");

        item->set_name("gloves");



	  }

	else if(purchase == "2"){

	  cost = 250;

        if(!stock[1]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 1;

        item->set_short("Chain Gloves");

        item->set_long(

        "These steel ring gloves are fashioned to resist most types\n"+

        "of melee damage. The palm of the glove is made from a tough\n"+

        "leather so as to allow for grasping and comfort.\n");

        item->set_weight(1);

        item->set_value(250);

        item->set_ac(1);

        item->set_type("ring");

        item->set_name("gloves");

        item->set_spec_perc(5);

        item->set_spec_amt(1);

        }

	else if(purchase == "3"){

	  cost = 500;

        if(!stock[2]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 2;

        item->set_short("Platemail Gloves");

        item->set_long(

        "This heavy set of gloves are made of thick plates of\n"+

        "overlapping steel. They are hinged around the fingers\n"+

        "and wrist, assisting in not restricting movement. The\n"+

        "palm is made of a tough leather to allow better grasping.\n");

        item->set_weight(2);

        item->set_value(500);

        item->set_ac(1);

        item->set_type("ring");

        item->set_name("gloves");

        item->set_spec_perc(15);

        item->set_spec_amt(1);

        }

	else if(purchase == "4"){ 

        cost = 120;

        if(!stock[3]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 3;

        item->set_short("Leather Boots");

        item->set_long(

        "This is a pair of tough leather boots. They are fashioned\n"+

        "from fine cowhide and are able to resist some damage.\n");

        item->set_weight(1);

        item->set_value(120);

        item->set_ac(1);

        item->set_type("boots");

        item->set_name("leather boots");

        }

	else if(purchase == "5"){

	  cost = 500;

        if(!stock[4]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 4;

        item->set_short("Platemail Boots");

        item->set_long(

        "This is a heavy set of plate boots. They are made of a thick\n"+

        "steel that overlap over the ankles and toes. They extend up\n"+

        "to the knee and protect the front of the leg. Leather straps\n"+

        "bind behind the knee and lower leg to secure it in place.\n");

        item->set_weight(2);

        item->set_value(500);

        item->set_ac(1);

        item->set_type("boots");

        item->set_name("platemail boots");

        item->set_spec_perc(20);

        item->set_spec_amt(1);

	  }

	else if(purchase == "6"){

	  cost = 50;

        if(!stock[5]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 5;

        item->set_short("Mask");

        item->set_long(

        "This mask is made of a combination of leather and steel, protecting\n"+

        "all of the vital and exposed areas of the head beneath steel, with\n"+

        "the leather extending down over the neck and back of the head. It is\n"+

        "comfortable to wear but lacks the protection of heavier armor.\n");

        item->set_weight(1);

        item->set_value(50);

        item->set_ac(0);

        item->set_type("helmet");

        item->set_name("mask");

        item->set_spec_perc(80);

        item->set_spec_amt(1);

        }

   	else if(purchase == "7"){

	  cost = 200;

        if(!stock[6]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 6;

        item->set_short("Helm");

        item->set_long(

        " This steel helm is constructed to protect all parts of the\n"+

        "head except the face. It is durable and capable of taking\n"+

        "damage well.\n");

        item->set_weight(1);

        item->set_value(200);

        item->set_ac(1);

        item->set_type("helmet");

        item->set_name("helm");

        }

	else if(purchase == "8"){

	  cost = 350;

        if(!stock[7]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 7;

        item->set_short("Fullhelm");

        item->set_long(

        "This helm provides protection to the face and head while\n"+

        "also remaining comfortable and allowing good vision. The\n"+

        "faceplate has 3 long lines to allow for vision with several\n"+

        "holes for breathing. The heavy steel construction gives\n"+

        "it a good durability against attacks.\n");

        item->set_weight(2);

        item->set_value(350);

        item->set_ac(1);

        item->set_type("helmet");

        item->set_name("fullhelm");

        item->set_spec_perc(10);

        item->set_spec_amt(1);

        }

	else if(purchase == "9"){

	  cost = 500;

        if(!stock[8]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 8;

        item->set_short("Greathelm");

        item->set_long(

        "This helm is made from a tough steel that extends down over\n"+

        "the face, head, and neck.  The visor is a single piece of\n"+

        "metal that is cut to allow for a good view. This helm can\n"+

        "endure considerable damage.\n");

        item->set_weight(2);

        item->set_value(500);

        item->set_ac(1);

        item->set_type("helmet");

        item->set_name("greathelm");

        item->set_spec_perc(20);

        item->set_spec_amt(1);

        }

	else if(purchase == "10"){

	  cost = 150;

        if(!stock[9]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 9;

        item->set_short("Buckler Shield");

        item->set_long(

        " This small shield fits over the arm of the user and helps\n"+

        "to provide protection versus minor attacks. It is a round\n"+

        "shield that is no more than 1 1/2' in diameter and is made\n"+

        "of a wood that is bound in steel.\n");

        item->set_weight(1);

        item->set_value(150);

        item->set_ac(1);

        item->set_type("shield");

        item->set_name("buckler");

        }

	else if(purchase == "11"){

	  cost = 250;

        if(!stock[10]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 10;

        item->set_short("Small Shield");

        item->set_long(

        " This round shield is made of a sturdy wood with a well\n"+

        "crafted steel edge formed around it. While protecting\n"+

        "the body from harm, it is still somewhat weak versus\n"+

        "powerful attacks.\n");

        item->set_weight(2);

        item->set_value(250);

        item->set_ac(1);

        item->set_type("shield");

        item->set_name("small shield");

        item->set_spec_perc(5);

        item->set_spec_amt(1);

        }

	else if(purchase == "12"){

	  cost = 500;

        if(!stock[11]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 11;

        item->set_short("Large Shield");

        item->set_long(

        "This shield resembles the small shield in its round\n"+

        "construction, but covers more protective space. It\n"+

        "is made of a durable wood with heavy steel binding\n"+

        "its frame. It is capable of resisting large amounts of\n"+

        "damage.\n");

        item->set_weight(3);

        item->set_value(500);

        item->set_ac(1);

        item->set_type("shield");

        item->set_name("large shield");

        item->set_spec_perc(20);

        item->set_spec_amt(1);

        }

	else if(purchase == "13"){

	  cost = 550;

        if(!stock[12]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 12;

        item->set_short("Kite Shield");

        item->set_long(

        "This all steel shield is shaped in the form of a V and\n"+

        "is considered the best form of melee shield, offering\n"+

        "protection and strike zones when fighting behind it.\n");

        item->set_weight(2);

        item->set_value(550);

        item->set_ac(1);

        item->set_type("shield");

        item->set_name("kite shield");

        item->set_spec_perc(15);

        item->set_spec_amt(1);

        }

	else if(purchase == "14"){

	  cost = 800;

        if(!stock[13]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 13;

        item->set_short("Tower Shield");

        item->set_long( 

        " This large shield protects over 3/4 of the body behind\n"+

        "a combination of wood and steel. It is very heavy and is\n"+

        "best used in military actions.\n");

        item->set_weight(4);

        item->set_value(800);

        item->set_ac(1);

        item->set_type("shield");

        item->set_name("tower shield");

        item->set_spec_perc(35);

        item->set_spec_amt(1);

        }

	else if(purchase == "15"){

	  cost = 800;

        if(!stock[14]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 14;

        item->set_short("Leather Armor");

        item->set_long(

        "This set of armor is made from a tough leather that has been\n"+

        "treated to resist damage against lesser attacks. It protects\n"+

        "the chest, back, upper arms, and stomach of the wearer.\n");

        item->set_weight(1);

        item->set_value(800);

        item->set_ac(2);

        item->set_type("armor");

        item->set_name("leather armor");

        }

	else if(purchase == "16"){

	  cost = 1000;

        if(!stock[15]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 15;

        item->set_short("Studded Leather Armor");

        item->set_long(

        "  Similar in design to leather armor, this set has several rows\n"+

        "of steel studs that are sewn into the chest and stomach sections\n"+

        "of the armor. They offer additional protection against minor\n"+

        "attacks.\n");

        item->set_weight(2);

        item->set_value(1000);

        item->set_ac(2);

        item->set_type("armor");

        item->set_name("studded armor");

        item->set_spec_perc(10);

        item->set_spec_amt(1);

        }

	else if(purchase == "17"){

	  cost = 2000;

        if(!stock[16]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 16;

        item->set_short("Chainmail Armor");

        item->set_long(

        "  This is a heavy set of chainmail armor. It is made of small\n"+

        "steel hoops that are placed together to form a defense against\n"+

        "some forms of attack. It protects the upper arms, torso, and\n"+

        "midsection of the wearer.\n");

        item->set_weight(2);

        item->set_value(1000);

        item->set_ac(2);

        item->set_type("armor");

        item->set_name("chainmail");

        item->set_spec_perc(80);

        item->set_spec_amt(1);

        }

	else if(purchase == "18"){

	  cost = 2200;

        if(!stock[17]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 17;

        item->set_short("Breastplate");

        item->set_long( 

        "  This is a heavy steel breastplate that protects the\n"+

        "torso and back of the wearer. It will resist heavy\n"+

        "damage to the torso area.\n");

        item->set_weight(1);

        item->set_value(1200);

        item->set_ac(3);

        item->set_type("armor");

        item->set_name("breastplate");

        }

	else if(purchase == "19"){

	  cost = 3800;

        if(!stock[18]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 18;

        item->set_short("Platemail Armor");

        item->set_long(

        "  This is a heavy set of plates that protect the upper part of\n"+

        "the body completely. It is made of a heavy steel plates that\n"+

        "overlap over the stomach, shoulders, and chest of the wearer.\n"+

        "It will protect against heavy damage.\n");

        item->set_weight(4);

        item->set_value(1400);

        item->set_ac(3);

        item->set_type("armor");

        item->set_name("platemail");

        item->set_spec_perc(80);

        item->set_spec_amt(1);

        }

	else if(purchase == "20"){

	  cost = 7000;

        if(!stock[19]){ write("Sold out.\n"); destruct(item); return 1; }

        else woot = 19;

        item->set_short("Field Plate Armor");

        item->set_long(

        "  This suit of armor protects the upper torso as well as the upper\n"+

        "legs and midsection of the wearer. It is made of heavy steel plates\n"+

        "that overlap over the critical areas of the body and extend outwards\n"+

        "to the extremities of the body. It will resist heavy damage.\n");

        item->set_weight(5);

         item->set_value(3500);

        item->set_ac(4);

        item->set_type("armor");

        item->set_name("field plate");

        item->set_spec_perc(10);

        item->set_spec_amt(1);

        }

	else{

	  write("The store owner says: I'm sorry, we don't carry that.\n");

	  return 1;

        }	

	

 if (call_other(this_player(), "query_money", 0) < cost) {

    write("The store owner says: I'm sorry, but you don't have enough for that.\n");

    return 1;

     }	   	

 if(!this_player()->add_weight(item->query_weight())) {

    write("The store owner says: It doesn't look like you can carry that.\n");

    destruct(item);

    return 1; }			

 write("You pay the store owner "+cost+" coins and receive a "+

       item->short()+".\n");

 say(tp->query_name() + " purchases a "+

     item->short()+".\n");

 stock[woot] -= 1;

 move_object(item,this_player());

 tp->add_money(-(cost));

 return 1;

}   



