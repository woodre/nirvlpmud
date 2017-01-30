#include "../define.h"

inherit ROOM;

#define tp this_player()

object owner;

string what;

int cost, haggle, owner_int;

object item;



reset(arg) {

if(!present("weapon_owner")){

	owner = clone_object("/players/jaraxle/ares/mobs/weapon_owner.c");

	move_object(owner, this_object());

	}

  if(arg) return;

   set_light(1);

   set_short("The Crown Defender [Weaponsmith]");

   set_long(

"  You find yourself in a large weapons store. The walls are covered\n"+

"with shelves and racks, each holding finely crafted items. You feel as\n"+

"as though you might be able to 'browse' the selection. A doorway leads\n"+

"out to the street.\n");

   add_item(

      "walls",

      "Stone walls that have numerous shelves and racks against them");

   add_item(

      "shelves",

      "Made of wood, these shelves hold numerous weapons for sell");

   add_item(

      "racks",

      "Made of wood, these racks hold numerous weapons for sell");

   add_item(

      "items",

      "Finely crafted weapons that line the walls on shelves and racks");

   add_item(

      "sign",

      "A sign that you can read");

   add_item(

      "desk",

      "A small desk that is used to conduct business");

   add_item(

      "doorway",

      "A doorway that leads out to the street");

   add_item(

      "street",

      "A stone road that winds through town");

    add_exit(ROOMS+"city18", "out"); 

}

init(){

    ::init();	

   add_action("browse_it", "browse");

   add_action("purchase_it","purchase");

   }



browse_it(){

  write(

  "\n"+

  "   .___________ [ New Are's Weapon Shop ] ___________.\n"+

  "   | TYPE:            COST:       TYPE:      COST:   |\n"+

  "   |  BattleAxe       2400        Bolts(50)   100    |\n"+

  "   |  Blackjack        300        Arrows(50)   50    |\n"+

  "   |  Club             700                           |\n"+

  "   |  Crossbow        5000                           |\n"+

  "   |  Dagger           100                           |\n"+

  "   |  Falchion        1000                           |\n"+

  "   |  Greatsword      2200                           |\n"+

  "   |  Longbow         3000                           |\n"+

  "   |  Longsword       1000                           |\n"+

  "   |  Mace            1200                           |\n"+

  "   |  Pike            2300                           |\n"+

  "   |  Quarterstaff    1000                           |\n"+

  "   |  Rapier          1000                           |\n"+

  "   |  Scimitar        1200                           |\n"+

  "   |  Scythe          1900                           |\n"+

  "   |  Shortbow        2400                           |\n"+

  "   |  Shortsword       800                           |\n"+

  "   |  Trident         1800                           |\n"+

  "   |  Warhammer       2000                           |\n"+

  "   ._________________________________________________.\n");

write("     To buy a weapon, '"+HIW+"purchase <name>"+NORM+"'\n");

  return 1;

}



purchase_it(string str){

	int purchase;

	purchase = str;

 if(!present("weapon_owner", this_object())){

 	write("You don't see the store owner here.\n");

 	return 1;

 	}

      item = clone_object("/players/jaraxle/weapon/weapon.c");

      item->set_save_flag(1);

	if(!purchase){ write("Usage: purchase <weapon>\n"); return 1; }

	if(purchase == "battleaxe"){

	  cost = 2400;

	  item->set_name("battleaxe");

        item->set_short("BattleAxe");

        item->set_long(

        "A large battleaxe with a well crafted steel head. The\n"+

        "haft is made from a strong oak and is polished to a\n"+

        "smooth sheen. A leather cord is wrapped around the end\n"+

        "to allow for a better grip on the weapon.\n");

        item->set_two_handed_wep(1);

        item->set_type("axe"); 

        item->set_class(18);

        item->set_weight(3);

        item->set_value(1200);

	  }

	else if(purchase == "blackjack"){

	  cost = 300;

	  item->set_name("blackjack");

item->set_short("BlackJack");

item->set_long(

"  This is a short clublike device that holds a solid\n"+

"metal object inside of a leather covering on one end,\n"+

"with a long flexible wooden handle and cord on the\n"+

"other. It can be used to strike someone and knock them\n"+

"unconscious if you know how.\n");

item->set_type("club"); 

item->set_class(11);

item->set_weight(1);

item->set_value(150);



        }

	else if(purchase == "club"){

	  cost = 700;

item->set_name("club");

item->set_short("Club");

item->set_long(

"  This is a long wooden club with several dangerous\n"+

"looking nails protruding from its tip.  It is made\n"+

"from oak and is somewhat heavy.\n");

item->set_type("club"); 

item->set_class(15);

item->set_weight(2);

item->set_value(350);



	  }

	else if(purchase == "crossbow"){ 

        cost = 5000;

        item = clone_object("/players/jaraxle/ares/weapons/crossbow.c");

	  }

	else if(purchase == "dagger"){

	  cost = 100;

item->set_name("dagger");

item->set_short("Dagger");

item->set_long(

"  This is a very small double bladed dagger that is\n"+

"probably most useful as a throwing weapon rather than\n"+

"a melee weapon. Its small handle is covered in a light\n"+

"leather and it seems very well balanced.\n");

item->set_type("knife"); 

item->set_class(12);

item->set_weight(1);

item->set_value(50);

	  }

	else if(purchase == "falchion"){

	  cost = 1000;

item->set_name("falchion");

item->set_short("Falchion");

item->set_long(

"  This sword has a long blade that is wide and curves\n"+

"backwards.  It is made of steel and has a simple hand\n"+

"guard over its leather wrapped handle.\n");

item->set_type("sword"); 

item->set_class(16);

item->set_weight(2);

item->set_value(500);

        }

   	else if(purchase == "greatsword"){

	  cost = 2200;

item->set_name("greatsword");

item->set_short("GreatSword");

item->set_long(

"  A large sword with a double edged blade, this weapon\n"+

"is capable of tearing through armor easily.  It has a\n"+

"heavy cross guard which will protect the hands and a\n"+

"leather wrapped handle which is oversized to help balance\n"+

"this large sword.\n");

item->set_type("sword"); 

item->set_two_handed_wep(1);

item->set_class(18);

item->set_weight(3);

item->set_value(1100);

        }

	else if(purchase == "longbow"){

	  cost = 3000;

        item = clone_object("/players/jaraxle/ares/weapons/longbow.c");	

        }

	else if(purchase == "longsword"){

	  cost = 1000;

item->set_name("longsword");

item->set_short("LongSword");

item->set_long(

"  This is a single handed steel bladed sword with\n"+

"double edges.  Its leather bound handle is protected\n"+

"slightly by a cross guard and the end is weighted by\n"+

"an iron ball.\n");

item->set_type("sword"); 

item->set_class(16);

item->set_weight(2);

item->set_value(500);       

        }

	else if(purchase == "mace"){

	  cost = 1200;

item->set_name("mace");

item->set_short("Mace");

item->set_long(

"  This is a 3' long weapon with a heavy spiked ball\n"+

"at its end. The haft is made of a sturdy wood with\n"+

"the handle wrapped in a thick leather.\n");

item->set_type("club"); 

item->set_class(16);

item->set_weight(2);

item->set_value(600);

        }

	else if(purchase == "pike"){

	  cost = 2300;

item->set_name("pike");

item->set_short("Pike");

item->set_long(

"  This is a very long polearm with a heavy steel\n"+

"edge at its tip.  The haft is made from a flexible\n"+

"wood and it seems to be of a sturdy construction.\n");

item->set_type("polearm"); 

item->set_two_handed_wep(1);

item->set_class(18);

item->set_weight(4);

item->set_value(1150);

        }

	else if(purchase == "quarterstaff"){

	  cost = 1000;

item->set_name("quarterstaff");

item->set_short("QuarterStaff");

item->set_long(

"  This long wooden staff is made from a sturdy oak and\n"+

"has numerous bands of steel weighing it down and giving\n"+

"it more power on its swing. It is of a solid construction.\n");

item->set_type("staff"); 

item->set_class(15);

item->set_weight(2);

item->set_two_handed_wep(1);

item->set_value(500);



        }

	else if(purchase == "rapier"){

	  cost = 1000;

item->set_name("rapier");

item->set_short("Rapier");

item->set_long(

"  This is a finely crafted steel sword with a slender\n"+

"blade extending from a steel hand guard.  The handle\n"+

"is covered with a thin leather and is comfortable when\n"+

"held.\n");

item->set_type("sword"); 

item->set_class(16);

item->set_weight(2);

item->set_value(500);

       

        }

	else if(purchase == "scimitar"){

	  cost = 1200;

item->set_name("scimitar");

item->set_short("Scimitar");

item->set_long(

"  This is a curving sword with a wide blade that\n"+

"sweeps back at a slight angle.  Its made of a\n"+

"strong steel and is lightweight. Its handle is\n"+

"protected by a wide crossguard and is covered with\n"+

"a thin layer of leather.\n");

item->set_type("sword"); 

item->set_class(16);

item->set_weight(2);

item->set_value(500);

       

        }

	else if(purchase == "scythe"){

	  cost = 1900;

item->set_name("scythe");

item->set_short("Scythe");

item->set_long(

"  This weapon has a long steel sweeping blade which\n"+

"extends out from the end of a curving wooden haft. It\n"+

"is a sturdy weapon that can be used for long sweeping\n"+

"attacks.\n");

item->set_type("polearm"); 

item->set_class(18);

item->set_weight(4);

item->set_value(950);

item->set_two_handed_wep(1);



        }

	else if(purchase == "shortbow"){

	  cost = 2400;

        item = clone_object("/players/jaraxle/ares/weapons/shortbow.c");	

        }

	else if(purchase == "shortsword"){

	  cost = 800;

item->set_name("shortsword");

item->set_short("ShortSword");

item->set_long(

"  This is a smaller version of the longsword, with\n"+

"a double edged design and small crossguard over its\n"+

"handle.  It is made for close quarters fighting and\n"+

"is often a good backup weapon during combat.\n");

item->set_type("sword"); 

item->set_class(15);

item->set_weight(1);

item->set_value(400);



        }

	else if(purchase == "trident"){

	  cost = 1800;

item->set_name("trident");

item->set_short("Trident");

item->set_long(

"  This is a long polearm weapon with a pointed\n"+

"item->set of three spikes jutting outward from its\n"+

"end. Its haft is made from a sturdy oak and is\n"+

"quite heavy.\n");

item->set_two_handed_wep(1);

item->set_type("polearm"); 

item->set_class(18);

item->set_weight(4);

item->set_value(900);

        }

	else if(purchase == "warhammer"){

	  cost = 2000;

item->set_name("warhammer");

item->set_short("WarHammer");

item->set_long(

"  This is a powerful steel warhammer. The head of this\n"+

"weapon is forged into a solid round block with a large\n"+

"spike jutting from the back. The haft is made from a\n"+

"strong oak wood and is wrapped in leather.\n");

item->set_type("club"); 

item->set_two_handed_wep(1);

item->set_class(18);

item->set_weight(4);

item->set_value(1000);

        }

	else if(purchase == "bolts"){

	  cost = 100;

        item = clone_object("/players/jaraxle/ares/weapons/bolts.c");	

        }

	else if(purchase == "arrows"){

	  cost = 50;

        item = clone_object("/players/jaraxle/ares/weapons/arrows.c");	

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

 write("You pay the store owner "+cost+" coins and receive a "+capitalize(purchase)+".\n");

 say(tp->query_name() + " purchases a "+capitalize(purchase)+".\n");

 move_object(item,this_player());

 tp->add_money(-(cost));

 return 1;

}   



