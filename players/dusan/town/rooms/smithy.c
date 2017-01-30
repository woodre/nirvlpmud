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
   add_action("examine_it", "examine");
   add_action("purchase_it","buy");
}

	  


browse_it(){
write(
"          The mage points to a sign and says: This is what I have to sell\n"+
"          @- 1. Helmet...............................180 -@\n"+
"          @- 2. Shield...............................200 -@\n"+
"          @- 3. Longsword...........................1200 -@\n"+
"          @- 4. Mace................................1200 -@\n"+
"          You may buy #.   \n");
 return 1;
} 


purchase_it(string str){
	if(!str){ write("Usage: buy 1-8.\n"); return 1; }
	if(str == "1"){
	  cost = 180;
	  item = clone_object("/players/dusan/town/armors/helmet.c");
	  what = "helmet";
	  }
	else if(str == "2"){
	  cost = 200;
	  item = clone_object("/players/dusan/town/armors/shield.c");
	  what = "shield";
	  }
	else if(str == "3"){
	  cost = 1200;
	  item = clone_object("/players/dusan/town/weapons/longsword.c");
	  what = "longsword";
	  }
	else if(str == "4"){
	  cost = 1200;
	  item = clone_object("/players/dusan/town/weapons/mace.c");
	  what = "mace";
	  }

	else{
	  write("Alan asks you : What do you want?\n");
	  return 1;
	}	
	
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("Alan says: You dont have enough gold for that item.\n");
    return 1;
     }	   	
 if(!this_player()->add_weight(item->query_weight())) {
    write("Alan says: This looks a little too heavy for you.\n");
    destruct(item);
     return 1; }			
  write("Alan hands you as you pay "+cost+" coins for a "+what+".\n");
 say(tp->query_name() + " purchases a "+what+".\n");
 move_object(item,this_player());
 tp->add_money(-cost);
 return 1;
} 

       
