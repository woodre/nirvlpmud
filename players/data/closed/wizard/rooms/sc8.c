#include "../define.h"
inherit ROOM;
#define tp this_player()
object owner;
string what;
int cost, haggle, owner_int;
object item;

reset(arg) {
if(!present("warrior_smith")){
	owner = clone_object("/players/maledicta/closed/w/mobs/smith.c");
	move_object(owner, this_object());
	}
  if(arg) return;
   set_light(1);
   set_short("Hall of the Warriors");
   set_long(
"    You find yourself in a quiet room that is crammed full of bits\n"+
"and pieces of equipment.  Amid the clutter is a small table that\n"+
"appears to be mostly clean. Towards the back of the room there is\n"+
"an open archway with a warm glow flowing from it. A door leads back\n"+
"out to the hall.\n");
   add_property("NT");
   add_smell("main", 
   "You smell sulfur and heat on the air as it flows by you");
   add_listen("main",
   "You listen carefully and hear far away through the arch the sound\n"+
   "of rythmic pounding");
   add_item(
      "equipment",
      "Pieces of weapons and armor that are scattered about");
   add_item(
      "clutter",
      "A jumble of of equipment that is spread about the room");
   add_item(
      "archway",
      "An archway that leads deep under ground. Torch light seems\n"+
      "to peek out from it");
   add_item(
      "door",
      "The door leading back out to the hall");
   add_item(
      ({"glow","light","torchlight"}),
      "A warm glow that lights the way further down the tunnel");
   add_item(
      "hall",
      "The outer hallway");
   add_exit(ROOMS+"sc6", "out"); 
   }

init(){
    ::init();	
   add_action("browse_it", "ask");
   add_action("purchase_it","purchase");
   }

browse_it(str){
if(!str){ write("ask who what?\n"); return 1; }
if(!present("warrior_smith", this_object())){ 
  write("You don't see anyone to ask.\n");
  return 1;
  }

if(str == "smith about wares" || str == "lartok about wares" || str == "about wares"){
 write(
  "The smith nods and shows you what he has, \n"+
  " 1) Torch..........................50 coins\n"+                      
  " 2) Belt of tiny daggers (40).....400 coins\n"+
  " 3) tiny dagger....................25 coins\n"+
  " 4) round shield..................125 coins\n"+
  " 5) small helm....................100 coins\n"+
  " 6) sap............................80 coins\n"+
  " 7) chainmail.....................400 coins\n"+
  " 8) breastplate...................550 coins\n"+
  " 9) bandages.......................80 coins\n"+
  "10) first aid kit.................120 coins\n"+
  " Just 'purchase #' if you want something.\n");
return 1;
}
write("The Smith looks at you and shrugs.\n");
return 1;
}



purchase_it(string str){
	int purchase;
	purchase = str;
 if(!present("warrior_smith", this_object())){
 	write("You don't see anyone here.\n");
 	return 1;
 	}
	if(!purchase){ write("purchase \n"); return 1; }
	if(purchase == "1"){
	  cost = 50;
	  item = clone_object("/obj/torch.c");
     item->set_fuel(1800);
     item->set_name("torch");
     item->set_short("a torch");
     item->set_long_lit(
     "This is a small wooden torch. It is currently lit and\n"+
     "can be 'extinguish'ed.\n");
     item->set_long_unlit(
     "This is a small wooden torch. It is currently unlit. You\n"+
     "can 'light' it.\n");
     item->set_weight(1);
	  }
	else if(purchase == "2"){
	  cost = 400;
	  item = clone_object("/players/maledicta/closed/w/items/belt.c");
     item->set_ammo(40); 
     }
   else if(purchase == "3"){
	  cost = 25;
	  item = clone_object("/players/maledicta/closed/w/items/tdagger.c"); 
     }
	else if(purchase == "4"){
	  cost = 125;
     item = clone_object("/players/maledicta/closed/w/items/shield.c");
	  }
	else if(purchase == "5"){ 
        cost = 100;
        item = clone_object("/players/maledicta/closed/w/items/helm.c");
	  }
	else if(purchase == "6"){
	  cost = 80;
	  item = clone_object("/players/maledicta/closed/w/items/sap.c");
	  }
	else if(purchase == "7"){
	  cost = 400;
        item = clone_object("/players/maledicta/closed/w/items/chainmail.c");	
        }
   else if(purchase == "8"){
	  cost = 550;
	  item = clone_object("/players/maledicta/closed/w/items/bplate.c");
	  }
  else if(purchase == "9"){
	  cost = 80;
	  item = clone_object("/players/maledicta/closed/w/items/first_aid_bandages.c");
	  }
  else if(purchase == "10"){
	  cost = 120;
	  item = clone_object("/players/maledicta/closed/w/items/first_aid_kit.c");
	  }

  else{
	  write("The smith says: I'm sorry, we don't carry that.\n");
	  return 1;
        }	
	
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("The smith says: You don't have enough coins.\n");
    return 1;
     }	   	
 if(!this_player()->add_weight(item->query_weight())) {
    write("The Smith says: You don't look like you can carry that.\n");
    destruct(item);
    return 1; }			
 write("You pay the Smith "+cost+" coins.\n");
 move_object(item,this_player());
 tp->add_money(-(cost));
 return 1;
}   

okay_follow() { return 1; }
query_no_fight() { return 1; }
