/* A series of weapons made to use charges 'clips' that can be bought in the town
   of Derellia IV. It is a high ticket item that costs 50000 coins, with each clip
   selling for 1500, and lasting 500 rounds. Special damage depends on charges
   existing in the item and can do random(6)+8 damage on a 30% chance, or do 5
   on a 60% chance(NOTE: Both cannot go off at the same time.).  Each special
   will eat up more charges, 3 additional for the larger, and 1 for the smaller.
   With its extreme cost and need for charges I have made it saveable. */

#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

int shots,loaded;
string shot_mess;

reset(arg){
  ::reset(arg);
  if (arg) return;

set_long(
  "   This is a standard issue military blaster pistol. It's short barrel and\n"+
  "body is made of a lightweight steel, with the grip made of a dark polished\n"+
  "wood. A metal sight runs the length of the pistol's frame, allowing for\n"+
  "greater accuracy. A small opening is located in the grip for an energy clip.\n");

set_type("gun");

set_weight(1);
set_value(1000);
set_hit_func(this_object());
}

query_save_flag(){ return 0; }

weapon_class(){
	if(shots){
		return 16;
	}
	else{
	return 5;
   }
}	

id(str){
return str == "gun" ||
       str == "blaster" ||
       str == "pistol"  || 
       str == "blaster_weapon_derellia" ||
       str == "gun_pistol_object";
       }	


short(){
shots();	
if(wielded){	
   return "a blaster pistol ["+BOLD+""+HIY+"ammo: "+shot_mess+""+NORM+"] (wielded)"; 	
   }
else{
   return "a blaster pistol ["+BOLD+""+HIY+"ammo: "+shot_mess+""+NORM+"]"; 	
   }
}

two_handed(){ return 1; }

shots(){
if(shots >= 500){
	shot_mess = "full charge";
}
else if(shots >= 350){
	shot_mess = "good charge";
}
else if(shots >= 200){
	shot_mess = "half charge";
}
else if(shots >= 100){			
        shot_mess = "low charge";
}
else if(shots >= 1){
	shot_mess = "dangerously low charge";
}
else{
	shot_mess = "no charge";
  }
}	                      
query_shots(){ return shots; }

weapon_hit(attacker){
int damage;

damage = random(8)+6;

shots -= 1;
if(shots <= 0){
write("Having run out of ammo you start to bash your opponent with the pommel of your pistol!\n");
}	
if(shots < 0) shots = 0;
if(!shots && loaded){
write(""+HIY+"<<<<<WARNING: Your clip has run out!>>>>>"+NORM+"\n");	
set_message_hit(({"massacre"," to small fragments","smashed",
                  " with a bone crushing sound","hit"," very hard","hit"," hard","hit","",
                  "grazed","","tickled"," in the stomach"}));	
call_other(environment(), "stop_wielding", this_object());
call_other(environment(), "wield", this_object(), 1);
loaded = 0;
    }
if(shots && random(100) < 20){
write(
"\tYou take aim on your opponent and...\n\n\n"+
"\t                          "+HIY+"BLAST"+NORM+"\n\n"+	
"\t             "+attacker->query_name()+" with a direct shot!\n\n");
shots -= 3;
return damage;
   }
if(shots && random(100) < 30){
write(
"You fire at "+attacker->query_name()+", the blaster round slamming into them!\n");
shots -= 1;
return 5;	
   }
return 0;
}
load_it(){
if(wielded){
write("You grab a clip and load the blaster pistol.\n");
this_object()->set_message_hit(({
	          HIY+"Crippled"+NORM, " with a direct laser shot",
                  HIY+"Blasted"+NORM, " in the torso",
                  HIY+"Blasted"+NORM, " with a searing white hot laser shot",
                  HIY+"Seared"+NORM, " with a direct hit",
                  HIY+"Hit"+NORM, " with a blaster round",
                  HIY+"Hit"+NORM, "", 
                  HIY+"Singed"+NORM, " with a glancing shot"
                  }));
    
    shots = 500;
    loaded = 1;
    call_other(environment(), "stop_wielding", this_object());
    call_other(environment(), "wield", this_object(), 1);
    return 1;
    }
write("You must be wielding it!\n");
return 1;
}

fix_weapon(){
write("You cannot fix your weapon with this method, it is too high tech.\n");
return 1;
}

set_hits(){
write("The item cannot be fixed in this manner!\n");
return 1;
}
set_misses(){
write("The item cannot be fixed in this manner!\n");
return 1;
}		
blaster_fix(){
  if (!broke) {
  write("weapon fixed.\n");	
  hits = 0;
  misses = 0;	
     return 1;  
   }
  broke = 0;
  misses = misses/2;
  set_class(3*class_of_weapon);
  hits = hits/3;
  write("The weapon has been fixed.\n");
  return 1;
}

	