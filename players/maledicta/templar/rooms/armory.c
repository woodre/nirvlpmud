#include "/players/maledicta/ansi.h"

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
	owner = clone_object("/players/maledicta/templar/mobs/armor_owner.c");
	move_object(owner, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "Templar Armory "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  This is the castle armory. Adorning its stone walls are numerous\n"+
"rows of racks, each covered in armor of differing types. You feel as\n"+
"though it would be fine to 'browse'. To the east is the door leading\n"+
"to the hallway.\n";

items = ({
  "walls",
  "White stone walls that are covered with shelves and racks",
  "racks",
  "Made of steel, each carry the heavier pieces of armor that is\n"+
  "available",
  "sign", 
  "It looks as though you could 'read' it",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/courtyard.c","east",
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
  " You browse the store's selection....\n\n"+
  "     ________________________________________________________  \n"+
  "     ____Item________________________________________Cost____  \n"+
  "     1. "+BOLD+"A Great Helm......................................300"+NORM+"  \n"+
  "     2. "+BOLD+"Shield w/ Red Cross...............................600"+NORM+"  \n"+
  "     3. "+BOLD+"Squires Boots......................................50"+NORM+"  \n"+
  "     4. "+BOLD+"Squires Leather Armor.............................150"+NORM+"  \n"+
  "     5. "+BOLD+"Full PlateArmor..................................5000"+NORM+"\n"+
  "     ________________________________________________________  \n"+
  "     You may '"+BOLD+"purchase #"+NORM+"'                                      \n");
  return 1;
}

purchase_it(string str){
	int purchase;
	purchase = str;
 if(!present("KnightInvite", this_player())){
		write("Only knights are served here!\n");
		return 1;
	}
 if(!present("armor_owner", this_object())){
 	write("You don't see the armorer here.\n");
 	return 1;
 	}
	if(!purchase){ write("Usage: purchase 1-5.\n"); return 1; }
	if(purchase == "1"){
	  cost = 300;
	  item = clone_object("/players/maledicta/templar/items/helmet.c");
	  what = "great helm";
	  }
	else if(purchase == "2"){
	  cost = 600;
	  item = clone_object("/players/maledicta/templar/items/shield.c");
	  what = "Templar Shield";
	  }
	else if(purchase == "3"){
	  cost = 50;
	  item = clone_object("/players/maledicta/templar/items/sboots.c");
	  what = "pair squires boots";
	  }
	else if(purchase == "4"){
	  cost = 150;
	  item = clone_object("/players/maledicta/templar/items/larmor.c");
	  what = "suit of leather armor";
	  }
	else if(purchase == "5"){
          cost = 5000;
	  item = clone_object("/players/maledicta/templar/items/fullplate2.c");
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

 		
