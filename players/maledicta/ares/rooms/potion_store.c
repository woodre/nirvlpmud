#include "../define.h"
inherit ROOM;
#define tp this_player()
object owner;
string what;
int cost, haggle, owner_int;
object item;

reset(arg) {
if(!present("gratilda_witch")){
	owner = clone_object("/players/maledicta/ares/mobs/potion_owner.c");
	move_object(owner, this_object());
	}
  if(arg) return;
   set_light(1);
   set_short("an old house");
   set_long(
"  You stand within a large room that smells vaguely of death and\n"+
"flowers. Looking around you see numerous things hanging from the\n"+
"ceiling, all of which are dead or rotting. There are several small\n"+
"shelves that hold books and jars of materials. Small candles give\n"+
"a little light to this dark place. The only door is the one that\n"+
"you entered through.\n");
   add_smell("main", 
   "You get a mixed sense as you take a deep breath of rotting corpse\n"+
   "and springtime flowers");
   add_item(
      "ceiling",
      "A low ceiling with numerous things hanging from it");
   add_item(
      "things",
      "Anything from dead birds to dried weeds");
   add_item(
      "shelves",
      "Small shelves that hold books and jars");
   add_item(
      "books",
      "Old books that look ready to fall apart just by your glance alone");
   add_item(
      "jars",
      "Several jars of varying size that hold a cloudy fluid which obscures\n"+
      "the things inside");
   add_item(
      "materials",
      "Various organic or semi organic materials");
   add_item(
      "candles",
      "They give light to this dark place");
   add_item(
      "door",
      "A small door that leads out into the street");
   add_exit(ROOMS+"city12", "out"); 
}
init(){
    ::init();	
   add_action("browse_it", "ask");
   add_action("purchase_it","purchase");
   }

browse_it(str){
if(!str){ write("ask what?\n"); return 1; }
if(!present("gratilda_witch", this_object())){ 
  write("You don't see anyone to ask.\n");
  return 1;
  }

if(str == "about wares"){
 write(
  "Gratilda cackles and shouts, \n"+
  " I can sell ya any of these potions, now listen carefully!\n"+
  "   Salve           1800\n"+
  "   Curing          1000\n"+
  "   Healing          800\n"+  
  "   Mana             800\n"+
  "   Regeneration    3000\n"+
 /* "   Endurance        500\n"+ */
  "   Vision          1000\n"+
 /* "   Smoke            500\n"+ */
  "   Infravision     1000\n"+
  " Just 'purchase' what ya want!\n"+
  " Or, 'ask about' a potion! (example: ask about curing)\n");  
return 1;
}
if(str == "about salve"){
  write(
 "Gratilda stares at you and says, \n"+
 "\"Why it'll fix ya up mighty quick!\"\n");
  return 1;
 }
if(str == "about curing"){
 write(
 "Gratilda stares at you and says, \n"+
 "\"Why that potion will take poison right outta yer body!\n"+
 " Mighty helpful if yer walkin the woods in summer!\"\n");
 return 1;
 }
if(str == "about healing"){
 write(
 "Gratilda stares at you and says, \n"+
 "\"If yer hurt this potion will heal ya right up!\"\n");
 return 1;
 }
if(str == "about infravision"){
  write(
 "Gratilda stares at you and says, \n"+
 "\"Lets ya see when its dark outside!\"\n");
 return 1;
 }
if(str == "about mana"){
  write(
 "Gratilda stares at you and says, \n"+
 "\"Mages just eat that un right up!\"\n");
 return 1;
 }
if(str == "about regeneration"){
  write(
 "Gratilda stares at you and says, \n"+
 "\"Thats alot like that healing one, only it takes longer!\"\n");
 return 1;
 }
/*
if(str == "about endurance"){
  write(
 "Gratilda stares at you and says, \n"+
 "\"When yer out walkin all over that there countryside, it'll let ya\n"+
 " Git further!\"\n");
 return 1;
 }
*/
if(str == "about vision"){
   write(
 "Gratilda stares at you and says, \n"+
 "\"I use that potion tuh spy on dem neighbors!\"\n");
 return 1;
 }
if(str == "about smoke"){
   write(
 "Gratilda stares at you and says, \n"+
 "\"I accidently made that'n an thought I caught me house on fer!\"\n");
 return 1; 
 }
write("Gratilda looks at you funny and shrugs.\n");
return 1;
}



purchase_it(string str){
	int purchase;
	purchase = str;
 if(!present("gratilda_witch", this_object())){
 	write("You don't see anyone here.\n");
 	return 1;
 	}
	if(!purchase){ write("purchase <potion>\n"); return 1; }
   if(purchase == "salve"){
     cost = 1800;
     item = clone_object("/players/fred/tcity/"+purchase+".c");
     }
	else if(purchase == "curing"){
	  cost = 1000;
	  item = clone_object("/players/maledicta/ares/potions/"+purchase+".c");
	  }
	else if(purchase == "healing"){
	  cost = 800;
	  item = clone_object("/players/maledicta/ares/potions/"+purchase+".c"); 
        }
   else if(purchase == "infravision"){
	  cost = 1000;
	  item = clone_object("/players/maledicta/ares/potions/"+purchase+".c"); 
        }
	else if(purchase == "mana"){
	  cost = 800;
        item = clone_object("/players/maledicta/ares/potions/"+purchase+".c");
	  }
	else if(purchase == "regeneration"){ 
        cost = 3000;
        item = clone_object("/players/maledicta/ares/potions/"+purchase+".c");
	  }
 /*
	else if(purchase == "endurance"){
	  cost = 500;
	  item = clone_object("/players/maledicta/ares/potions/"+purchase+".c");
	  }
  */
	else if(purchase == "vision"){
	  cost = 1000;
        item = clone_object("/players/maledicta/ares/potions/"+purchase+".c");	
        }
  /*
	else if(purchase == "smoke"){
	  cost = 500;
        item = clone_object("/players/maledicta/ares/potions/"+purchase+".c");	
        }
  */
	else{
	  write("The store owner says: I'm sorry, we don't carry that.\n");
	  return 1;
        }	
	
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("Gratilda asks: Where be yer coins young one?\n");
    return 1;
     }	   	
 if(!this_player()->add_weight(item->query_weight())) {
    write("Gratilda says: Lighten yer load greedy guts!\n");
    destruct(item);
    return 1; }			
 write("You pay Gratilda "+cost+" coins and receive a Potion of "+capitalize(purchase)+".\n");
 say(tp->query_name() + " purchases a Potion of "+capitalize(purchase)+".\n");
 move_object(item,this_player());
 tp->add_money(-(cost));
 return 1;
}   

