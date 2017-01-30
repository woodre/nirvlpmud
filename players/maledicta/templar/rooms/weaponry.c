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
if(!present("weapon_owner")){
	owner = clone_object("/players/maledicta/templar/mobs/weapon_owner.c");
	move_object(owner, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "Templar Weaponsmith "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  This is the Templar weaponry shop.  Lining the walls are racks\n"+
"of finely crafted weaponry. You feel as though it would be alright\n"+
"to 'browse' the shop. A small door leads west into the hallway.\n";
items = ({
  "walls",
  "White stone walls that are covered with shelves and racks",
  "racks",
  "Made of steel, each carry the heavier pieces of armor that is\n"+
  "available",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/courtyard.c","west",
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
  "     1. "+BOLD+"Broadsword...............................1200"+NORM+"  \n"+
  "     2. "+BOLD+"GreatAxe.................................1400"+NORM+"  \n"+
  "     3. "+BOLD+"WarHammer................................1000"+NORM+"  \n"+
  "     4. "+BOLD+"Mace......................................850"+NORM+"  \n"+
  "     5. "+BOLD+"Pike.....................................2500"+NORM+"  \n"+
  "     6. "+BOLD+"Knife.....................................400"+NORM+"  \n"+ 
  "     [ Alliance provided weapons ]\n"+
  "     7. "+HIW+"Crystal Bardsword (fire)................10000"+NORM+"  \n"+
  "     8. "+HIW+"Crystal Bardsword (opera)...............10000"+NORM+"  \n"+
  "     9. "+HIW+"Crystal Bardsword (darkfire)............10000"+NORM+"  \n"+
  "    10. "+HIW+"Crystal Bardsword (xmas)................10000"+NORM+"  \n"+
  "     ________________________________________________________  \n"+
  "     You may '"+BOLD+"purchase #"+NORM+"'                                      \n");
  return 1;
}

purchase_it(string str){
	int purchase;
	purchase = str;
	if(!present("KnightInvite", this_player())){
		write("Only knights may purchase here!\n");
		return 1;
	}
 if(!present("weapon_owner", this_object())){
 	write("You don't see the weaponsmith here.\n");
 	return 1;
 	}
	if(!purchase){ write("Usage: purchase 1-7.\n"); return 1; }
	if(purchase == "1"){
	  cost = 1200;
	  item = clone_object("/players/maledicta/templar/items/sword.c");
	  what = "sword";
	  }
	else if(purchase == "2"){
	  cost = 1400;
	  item = clone_object("/players/maledicta/templar/items/axe.c");
	  what = "battle axe";
	  }
	else if(purchase == "3"){
	  cost = 1000;
	  item = clone_object("/players/maledicta/templar/items/hammer.c");
	  what = "hammer";
	  }
	else if(purchase == "4"){
	  cost = 850;
	  item = clone_object("/players/maledicta/templar/items/mace.c");
	  what = "mace";
	  }
	else if(purchase == "5"){
	  cost = 2500;
	  item = clone_object("/players/maledicta/templar/items/pike2.c");
	  what = "pike";
	  }
	else if(purchase == "6"){
	  cost = 400;
	  item = clone_object("/players/maledicta/templar/items/knife.c");
	  what = "knife";
	  }
	else if(purchase == "7"){
	  cost = 10000;
	  item = clone_object("/players/maledicta/templar/items/bardsword.c");
	  what = "bardsword";
	  }
	else if(purchase == "8"){
	  cost = 10000;
	  item = clone_object("/players/maledicta/templar/items/bardsword2.c");
	  what = "bardsword";
	  }
	else if(purchase == "9"){
	  cost = 10000;
	  item = clone_object("/players/maledicta/templar/items/bardswordb.c");
	  what = "bardsword";
	  }
    else if(purchase == "10"){
	  cost = 10000;
	  item = clone_object("/players/maledicta/templar/items/bardswordxs.c");
	  what = "bardsword";
	  }
	else{
	  write("The Weaponsmith says: I'm sorry, we don't carry that.\n");
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

 		