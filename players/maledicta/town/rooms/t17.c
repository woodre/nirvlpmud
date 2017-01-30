/*  Added the ability to 'haggle'.  What this does is takes the players
    intelligence vs. the intelligence of the shopkeeper, randomizes them
    both, and if the player scores higher can get the item for cheaper. 
    If lower, will get the item for higher. Normal purchasing is still
    available. */

#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define BLASTER present("blaster_weapon_derellia", this_player())
inherit "room/room";
object owner;
string what;
int cost, haggle, owner_int;
object item;

reset(arg) {
if(!present("weapon_owner")){
	owner = clone_object("/players/maledicta/town/mobs/weapon_owner.c");
	move_object(owner, this_object());
	}
owner_int = random(21);
if(owner_int < 10) owner_int = 10;

  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  This is a small weapons shop. Shelves and racks of guns and medieval\n"+
"style weapons line the stone walls. A beautiful oak counter can be seen\n"+
"at the back of the store, a small cash register sitting atop it. You\n"+
"feel that it would be ok to browse the store.\n";

items = ({
  "shelves",
  "Large wooden and metal shelves that cover the walls and the center of the\n"+
  "shops floor",
  "racks",
  "Lining the walls are several large racks made of wood. They have weapons\n"+
  "carefully laid out on them",
  "weapons",
  "You look at several of the medieval style weapons, although updated and\n"+
  "carrying a more deadly edge",
  "guns",
  "You see a large selection of guns and blasters",
  "counter",
  "A beautifully crafted counter that has seen many years of use",
  "register",
  "A small computer register for doing business",
   
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t16.c","out",
});

}
init(){
    ::init();	
   add_action("browse_it", "browse");
   add_action("purchase_it","purchase");
   add_action("haggle_it", "haggle");
   add_action("fix_blasters", "fix");
   this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	
   

browse_it(){
  write(
  "\n\n"+
  "\t   You browse the store's selection....\n\n"+
  "\t "+HIG+".............:"+NORM+"["+BOLD+""+BLK+"Derellia's Defense"+NORM+"]"+HIG+":.............\n"+
  "\t :                                              :\n"+
  "\t : "+NORM+"Items Available                        Cost  "+HIG+":\n"+
  "\t : "+NORM+"1. VibroSword__________________________1500  "+HIG+":\n"+
  "\t : "+NORM+"2. VibroAxe____________________________2200  "+HIG+":\n"+
  "\t : "+NORM+"3. BlasterPistol_______________________8000  "+HIG+":\n"+
  "\t : "+NORM+"4. BlasterRifle_______________________20000  "+HIG+":\n"+
  "\t : "+NORM+"5. Clip [blaster pistol]________________300  "+HIG+":\n"+
  "\t : "+NORM+"6. Clip [blaster rifle]_________________600  "+HIG+":\n"+
  "\t :..............................................:"+NORM+"\n"+
  "\t You may purchase # or haggle # over the price.                 \n"+
  "\t We can also 'fix' any hi-tech weapon we sell here,\n"+
  "\t Cost is 1000 coins.\n");
  return 1;
}


fix_blasters(string str){

if(!present("weapon_owner", this_object())){
write("You don't see the store owner anywhere around.\n");
return 1;
}	

if(!str){ write("fix what?\n"); return 1; }

if(this_player()->query_money() < 1000){ 
write("You don't have enough coins!\n");
return 1;
}
	
if(str == "gun" || str == "blaster" || str == "rifle" || str == "pistol"){

if(BLASTER){

if(BLASTER->query_wielded()){
	write("YOU MUST UNWIELD IT FIRST!\n");	
	return 1; }
	BLASTER->blaster_fix();
	write("You give the owner 1000 coins to fix your weapon.\n");
	write("The owner takes your weapon and repairs its wear.\n"+
	      "He then hands it back to you with a smile.\n");
	this_player()->add_money(-1000);
	return 1;
}      	
return 0;
}
return 0;
}

purchase_it(string str){
	int purchase;
	purchase = str;
 if(!present("weapon_owner", this_object())){
 	write("You don't see the store owner here.\n");
 	return 1;
 	}
	if(!purchase){ write("Usage: purchase 1-8.\n"); return 1; }
	if(purchase == "1"){
	  cost = 1500;
	  item = clone_object("/players/maledicta/town/weapons/vsword.c");
	  what = "vibro sword";
	  }
	else if(purchase == "2"){
	  cost = 2200;
	  item = clone_object("/players/maledicta/town/weapons/vaxe.c");
	  what = "vibro axe";
	  }
	else if(purchase == "3"){
	  cost = 8000;
	  item = clone_object("/players/maledicta/town/weapons/blaster2.c");
	  what = "blaster pistol";
	  }
	else if(purchase == "4"){
	  cost = 20000;
	  item = clone_object("/players/maledicta/town/weapons/brifle2.c");
	  what = "blaster rifle";
	  }
	  
	else if(purchase == "5"){
	  cost = 800;
	  item = clone_object("/players/maledicta/town/weapons/clip.c");
	  what = "clip";
	  }
	else if(purchase == "6"){
	  cost = 600;
	  item = clone_object("/players/maledicta/town/weapons/clipr.c");
	  what = "clip";	
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
 write("You pay the store owner "+cost+" coins and receive a "+what+".\n");
 say(tp->query_name() + " purchases a "+what+".\n");
 move_object(item,this_player());
 tp->add_money(-(cost));
 return 1;
}   

haggle_it(string str){
	int purchase;
	purchase = str;
 if(!present("weapon_owner", this_object())){
 	write("You don't see the store owner here.\n");
 	return 1;
 	}
	if(!purchase){ write("Usage: purchase 1-8.\n"); return 1; }
	if(purchase == "1"){
	  cost = 1500;
        haggle = 300;
	  item = clone_object("/players/maledicta/town/weapons/vsword.c");
	  what = "vibro sword";
	  }
	else if(purchase == "2"){
	  cost = 2200;
        haggle = 500;
	  item = clone_object("/players/maledicta/town/weapons/vaxe.c");
	  what = "vibro axe";
	  }
	else if(purchase == "3"){
	  cost = 8000;
     haggle = 2000;
	  item = clone_object("/players/maledicta/town/weapons/blaster2.c");
	  what = "blaster pistol";
	  }
	else if(purchase == "4"){
	  cost = 20000;
        haggle = 4000;
	  item = clone_object("/players/maledicta/town/weapons/brifle2.c");
	  what = "blaster rifle";
	  }
	else if(purchase == "5"){
	  cost = 800;
        haggle = 200;
	  item = clone_object("/players/maledicta/town/weapons/clip.c");
	  what = "clip";
	  }
	else if(purchase == "6"){
	  cost = 600;
        haggle = 150;
	  item = clone_object("/players/maledicta/town/weapons/clipr.c");
	  what = "clip";	
          }
        else{
	  write("The store owner says: I'm sorry, we don't carry that.\n");
	  return 1;
	}	
if (call_other(this_player(), "query_money", 0) < (cost + haggle)) {
    write("The store owner says: I'm sorry, but you don't have enough for that.\n");
    return 1;
     }

if(random(this_player()->query_attrib("int"))  > random(owner_int)){
    write(
    "Store Owner says: I suppose I could give it to you for that instead.\n");
    cost -= random(haggle);
    }
else{
    write(
    "Store Owner says: Sorry, the price just went up.\n");
    if(haggle < 1) haggle = 10;
    cost += random(haggle);
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
