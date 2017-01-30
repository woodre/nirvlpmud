/*  Added the ability to 'haggle'.  What this does is takes the players
    intelligence vs. the intelligence of the shopkeeper, randomizes them
    both, and if the player scores higher can get the item for cheaper. 
    If lower, will get the item for higher. Normal purchasing is still
    available. */

#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object item;
int cost, mage;
string what;
object owner;
reset(arg) {
if(!present("Zed")){
	mage = clone_object("/players/dusan/town/mobs/mage.c");
	move_object(mage, this_object());
}

  if(arg) return;
set_light(1);

short_desc = "A small stone tower";
long_desc =
"  This is the home of the town hedge mage. It is cramped dusty and \n"+
"the walls are covered in bookshelves with various books, tomes, and\n"+
"the random spell component.  In the center of this room is a table \n"+
"with items that look like they are displayed for sale. To the south\n"+
"leads back to the town's main road.\n";

items = ({
  "walls",
  "Dusty stone walls that make up the tower",
  "bookshelves",
  "Wooden shelves that are crammed full of tomes, books and seemingly random items",
  "books",
  "There are all kinds of books everything from a spinless old journal to large ornate leather bound tomes",
  "table",
  "A massive table made from an unidentifiable wood. All sorts of strange items are\n"+
  "'display'ed across it.",
  "items",
  "Various items 'display'ed on the table",
  "road",
  "The black mud trail to the south",
  "walls",
  "The walls are made of a dark grey stone and are covered with shelves",
});

dest_dir = ({
  "/players/dusan/town/rooms/twn7.c","out",
});

}

init(){
    ::init();	
   add_action("browse_it", "display");
   add_action("purchase_it","buy");
}

	  


browse_it(){
write(
"          The mage points to a sign and says: This is what I have to sell\n"+
"          - 1. Healing Salve (3)....................780 -\n"+
"          - 2. Poultice(3).....................1200 -\n"+
"          - 3. Herbal Remedy(3)..........1200 -\n"+
"          - 4. Incense of Meditation(1)...........900 -\n"+
"          You may buy #.   \n");
 return 1;
} 


purchase_it(string str){
	if(!str){ write("Usage: buy 1-4.\n"); return 1; }
	if(str == "1"){
	  cost = 780;
	  item = clone_object("/players/dusan/town/items/hsalve.c");
	  what = "healing salve";
	  }
	else if(str == "2"){
	  cost = 1200;
	  item = clone_object("/players/dusan/town/items/poultice.c");
	  what = "poultice";
	  }
	else if(str == "3"){
	  cost = 780;
	  item = clone_object("/players/dusan/town/items/remedy.c");
	  what = "remedy";
	  }
	else if(str == "4"){
	  cost = 1900;
	  item = clone_object("/players/dusan/town/items/incense.c");
	  what = "incense";
	  }

	else{
	  write("Zed looks at you like you are an idiot.\n");
	  return 1;
	}	
	
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("Zed says: Don't waste my time come back when you have money you bum.\n");
    return 1;
     }	   	
 if(!this_player()->add_weight(item->query_weight())) {
    write("Zed says: It doesn't look like you can carry that.\n");
    destruct(item);
     return 1; }			
  write("Zed thanks you as you pay "+cost+" coins for a "+what+".\n");
 say(tp->query_name() + " purchases a "+what+".\n");
 move_object(item,this_player());
 tp->add_money(-cost);
 return 1;
} 

       
