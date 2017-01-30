#include "/players/jaraxle/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object owner;
string what;
int cost;
object item;


reset(arg) {
if(!present("armor_owner")){
	owner = clone_object("/players/jaraxle/templar/mobs/armor_owner.c");
	move_object(owner, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = HIW+"Armory ["+NORM+GRN+"Fortress Stone "+HIW+"]"+NORM+"";
long_desc =
"  The Armory is a large room, divided by a wooden counter that spans\n"+
"the width of the room. There are several polished suits of platemail\n"+
"on stands, as well as shields and weapons mounted upon the walls. A\n"+
"door leads further into the room, and numerous shelves and hooks hold\n"+
"gear within the storage room. There is a circular rug on the floor,\n"+
"and a window in the southern wall that overlooks the courtyard.\n";

items = ({
  "walls",
  "White stone walls that are covered with shelves and racks",
  "racks",
  "Made of steel, each carry the heavier pieces of armor that is\n"+
  "available",
  "sign", 
  "The sign reads: Feel free to "+GRN+"browse"+NORM+" our armors",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/hallway1.c","east",
});

}

init(){
    ::init();

   add_action("browse_it", "browse");
   add_action("purchase_it","purchase");
  this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }




browse_it(){
  write(
  "You browse the armory...\n\n"+
  "     ________________________________________________________  \n"+
  "     ____Item________________________________________Cost____  \n\n"+
  "     1. "+BOLD+"A Great Helm......................................300"+NORM+"  \n"+
  "     2. "+BOLD+"Shield w/ Red Cross...............................600"+NORM+"  \n"+
  "     3. "+BOLD+"Squires Boots......................................50"+NORM+"  \n"+
  "     4. "+BOLD+"Squires Leather Armor.............................150"+NORM+"  \n"+
  "     5. "+BOLD+"Full PlateArmor..................................5000"+NORM+"\n"+
  "     ________________________________________________________  \n\n"+
  "     You may '"+BOLD+"purchase #"+NORM+"'                                      \n");
  return 1;
}

purchase_it(string str){
	int purchase;
	purchase = str;
 if(!present("KnightInvite", this_player())){
		write("Only Knights are served here!\n");
		return 1;
	}
 if(!present("armor_owner", this_object())){
 	write("You don't see the armorer here.\n");
 	return 1;
 	}
	if(!purchase){ write("Usage: purchase 1-5.\n"); return 1; }
	if(purchase == "1"){
	  cost = 300;
	  item = clone_object("/players/jaraxle/templar/items/helmet.c");
	  what = "great helm";
	  }
	else if(purchase == "2"){
	  cost = 600;
	  item = clone_object("/players/jaraxle/templar/items/shield.c");
	  what = "Templar Shield";
	  }
	else if(purchase == "3"){
	  cost = 50;
	  item = clone_object("/players/jaraxle/templar/items/sboots.c");
	  what = "pair squires boots";
	  }
	else if(purchase == "4"){
	  cost = 150;
	  item = clone_object("/players/jaraxle/templar/items/larmor.c");
	  what = "suit of leather armor";
	  }
	else if(purchase == "5"){
          cost = 5000;
	  item = clone_object("/players/jaraxle/templar/items/fullplate2.c");
	  what = "suit of plate armor";
	  }
	
	else{
	  write("The smithy says: I'm sorry, we don't carry that.\n");
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
 write("You pay the store owner "+cost+" coins and receive a "+what+".\n");
 say(tp->query_name() + " purchases a "+what+".\n");
 move_object(item,this_player());
 tp->add_money(-(cost));
 return 1;
 }   

 		
