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
  "/players/jaraxle/templar/rooms/courtyard.c","east",
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
	  item = clone_object("/playeÄÑÄ∂ÄÎÄ'ÄUÄèÄƒÄ‘ÄÄAÄqÄ†ÄÕÄ˝Ä'ÄZÄèÄ™Ä⁄ÄÄ ÄSÄåÄ∆ÄÄ?ÄfÄôÄßÄÌÄ$Ä^ÄpÄüÄŒÄÄ*Ä4ÄBÄPÄ _Ä!nÄû}Ä¬Ä—ÄÄ6ÄiÄöÄ‰Ä!ÄWÄõÄ±ÄﬁæÄıÄ"ÄÔ:ÄwÄ¢ÄG
