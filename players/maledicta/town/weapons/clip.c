inherit "obj/treasure";
#include "/players/maledicta/ansi.h"

reset (arg) {
if(!arg){

  set_id("clip");
  set_short("a clip [Blaster Pistol]");
  set_long(
  "A large metal clip for a blaster pistol. It carries 50 rounds\n"+
  "of energy.\n"+
  "Usage: insert clip.\n"+
  "       force_insert clip.\n");
  set_weight(1);
  set_value(20);
    }
  }

  init(){
  ::init();
  add_action("insert_pistol", "insert");
  add_action("force_pistol", "force_insert");
}

force_pistol(string str){
object fgun;
fgun = present("gun_pistol_object", environment(this_object()));	
    if(!str){ write("insert what?\n"); return 1; }
    if(str == "clip"){
    	if(fgun){
    	fgun->load_it();
    	destruct(this_object());
    	return 1;	
        }
    write("You don't have a blaster pistol!\n");	
    return 1;
    }
return 0;
}

insert_pistol(string str){
object gun;
gun = present("gun_pistol_object", environment(this_object()));	
    if(!str){ write("insert what?\n"); return 1; }
    if(str == "clip"){
    	if(gun){
    	if(!gun->query_wielded()){
    	write("You must be wielding the blaster first!\n");
    	return 1;
    	}		
    	if(gun->query_shots() > 10){
    	write("Its already loaded!\n");
    	return 1;
    	  }		
    	gun->load_it();
    	destruct(this_object());
    	return 1;	
        }
    write("You don't have a blaster pistol!\n");	
    return 1;
    }
return 0;
}