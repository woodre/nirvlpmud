

#include "/players/maledicta/ansi.h"
#define USER environment()
inherit "obj/weapon";
int shots,loaded;
string shot_mess;

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("pistol");
set_type("gun");
set_class(1);
set_weight(1);
set_value(1000);
set_hit_func(this_object());
}

query_save_flag(){ return 0; }

id(str){
return str == "blaster" ||
       str == "pistol"  || 
       str == "blaster_weapon_derellia" ||
       str == "gun_pistol_object" ||
       str == "gun";
       }	

long(){
write(
  "   This is a standard issue military blaster pistol. It's short barrel and\n"+
  "body is made of a lightweight steel, with the grip made of a dark polished\n"+
  "wood. A metal sight runs the length of the pistol's frame, allowing for\n"+
  "greater accuracy. A small opening is located in the grip for an energy clip.\n");
return 1;
}

short(){
shots();	
if(wielded){	
   return "Blaster Pistol ["+HIY+"ammo: "+shot_mess+""+NORM+"] (wielded)"; 	
   }
else{
   return "Blaster Pistol ["+HIY+"ammo: "+shot_mess+""+NORM+"]"; 	
   }
}

shots(){
if(shots >= 50){
	shot_mess = "full charge";
}
else if(shots >= 30){
	shot_mess = "good charge";
}
else if(shots >= 25){
	shot_mess = "half charge";
}
else if(shots >= 15){			
        shot_mess = "low charge";
}
else if(shots >= 5){
	shot_mess = "dangerously low charge";
}
else{
	shot_mess = "no charge";
  }
}	                      
query_shots(){ return shots; }

blaster_fix(){
  if (!broke) {
  write("weapon fixed.\n");	
  hits = 0;
  misses = 0;	
     return 1;
   }
  broke = 0;
  misses = misses/2;
  hits = hits/3;
  write("The weapon has been fixed.\n");
  return 1;
  }

	

load_it(){
if(wielded){
write("You grab a clip and load the blaster pistol.\n");
set_message_hit(({
	          HIY+"Crippled"+NORM, " with a direct laser shot",
                  HIY+"Blasted"+NORM, " in the torso",
                  HIY+"Struck"+NORM, " with a searing white hot laser shot",
                  HIY+"Seared"+NORM, " with a direct hit",
                  HIY+"Hit"+NORM, " with a blaster round",
                  HIY+"Hit"+NORM, "", 
                  HIY+"Singed"+NORM, " with a glancing shot"
                  }));
    
    shots = 50;
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


weapon_hit(attacker){
 int dam;

 if(check_attackers()){
  tell_object(USER,
  "You swing the Blaster Pistol butt first as you fight your opponent hand-to-hand.\n");
  return random(3) + 1;
  }

 if(!shots){
  set_message_hit(({"massacre"," to small fragments","smashed",
                  " with a bone crushing sound","hit"," very hard","hit"," hard","hit","",
                  "grazed","","tickled"," in the stomach"}));	
  tell_object(environment(), 
  "Your Blaster Pistol is out of ammo! You start bashing your opponent with its\n"+
  "grip!\n");
  return random(3) + 1;
  }
 shots -= 1;
 dam = random(4) + 18;
 if(random(500) < USER->query_attrib("ste")){
  tell_object(USER,
  HIY+"["+NORM+BOLD+"C R I T I C A L"+NORM+HIY+"]"+NORM);
  dam += random(7);
  }
 return dam;
 }

check_attackers(){
object ob;
 ob = first_inventory(environment(USER));
  while(ob) {
    if(ob->query_attack() == USER){ return 1; }
     ob = next_inventory(ob);
    }
 return 0;
 }

