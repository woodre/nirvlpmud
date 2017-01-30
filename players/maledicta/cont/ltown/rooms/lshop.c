#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object item;
int cost;
string what;
object owner;
reset(arg) {
if(!present("clerk_owner")){
	owner = clone_object("/players/maledicta/cont/ltown/mobs/store_owner.c");
	move_object(owner, this_object());
	}

  if(arg) return;
set_light(1);

short_desc = "Terk'ula Equipment Store";
long_desc =
"  This is a small equipment store.  It is made of wood and mud\n"+
"like most of the buildings here. Lining the walls are racks of\n"+
"equipment. A small counter stands at the back of the room, with\n"+
"a large sign on the wall.\n";

items = ({
 "walls",
 "Wooden walls with mud filling the gaps",
 "racks",
 "Large wooden racks that hold equipment",
 "counter",
 "A wooden counter",
 "sign",
 "A large sign that you can 'read'",
 });

dest_dir = ({
  "/players/maledicta/cont/ltown/rooms/l2.c","out",
});

}

init(){
    ::init();	
   add_action("browse_it", "read");
   add_action("purchase_it","purchase");
   
}
	  


browse_it(str){
if(!str){
write("read what?\n");
return 1;
}
if(str != "sign"){
write("Read what?\n");
return 1;
}
write(
"    +------------- Equipment Store -------------+\n"+
"    |  1. bag(small)...................50 coins |\n"+
"    |  2. bag(large)..................150 coins |\n"+
"    |  3. torch........................50 coins |\n"+
"    |  4. 10' pole.....................80 coins |\n"+
"    |  5. Colored Charcoal............100 coins |\n"+
"    |  6. Healing Herbs..............1800 coins |\n"+
"    +-------------------------------------------+\n"+
"     To buy something, purchase #\n");
return 1;
} 


purchase_it(string str){
 if(!present("clerk_owner", this_object())){
 	write("You don't see the Merchant here.\n");
 	return 1;
 	}
if(!str){ write("Usage: purchase 1-6.\n"); return 1; }
	if(str == "1"){
	  cost = 50;
	  item = clone_object("/players/maledicta/cont/ltown/objects/sbag.c");
	  what = "bag";
	  }
	else if(str == "2"){
	  cost = 150;
	  item = clone_object("/players/maledicta/cont/ltown/objects/lbag.c");
	  what = "bag";
	  }
	else if(str == "3"){
	  cost = 50;
	  item = clone_object("/obj/torch.c");
	  item->set_name("torch");
	  item->set_fuel(10000);
	  item->set_long_lit(
	  "A wooden torch with steel bindings. It is lit.\n");
	  item->set_long_unlit(
	  "A wooden torch with steel bindings. It is not lit.\n");
	  what = "torch";
	  }  
	else if(str == "4"){
	  cost = 80;
	  item = clone_object("/players/maledicta/cont/ltown/objects/tenfoot.c");
	  what = "10' pole";
	  }
	else if(str == "5"){
	  cost = 100;
	  item = clone_object("/players/maledicta/cont/ltown/objects/chalk.c");
	  what = "colored charcoal";
	  }
	else if(str == "6"){
	  cost = 1800;
	  item = clone_object("/players/maledicta/cont/ltown/objects/herbs.c");
	  what = "healing herb";
	  }
	else{
	  write("The merchant says: I'm sorry, we don't carry that.\n");
	  return 1;
	}	
	
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("Merchant says: I'm sorry, but you don't have enough coins for that.\n");
    return 1;
     }	   	
 if(!this_player()->add_weight(item->query_weight())) {
    write("The Merchant says: It doesn't look like you can carry that.\n");
    destruct(item);
    return 1; }			
 write("The Merchant thanks you as you pay "+cost+" coins for a "+what+".\n");
 say(tp->query_name() + " purchases a "+what+".\n");
 move_object(item,this_player());
 tp->add_money(-cost);
 return 1;
}        
