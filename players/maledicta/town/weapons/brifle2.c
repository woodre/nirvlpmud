

#include "/players/maledicta/ansi.h"
#define USER environment()
inherit "obj/weapon";
int shots,loaded;
string shot_mess;

reset(arg){
  ::reset(arg);
  if (arg) return;



set_name("rifle");
set_type("gun");
set_class(1);
set_weight(3);
set_value(1000);
set_hit_func(this_object());
}
two_handed(){ return 1; }

query_save_flag(){ return 0; }

id(str){
return str == "blaster" ||
       str == "rifle"  || 
       str == "blaster_weapon_derellia" ||
       str == "gun_rifle_object" ||
       str == "gun";
       }	

long(){
write(
"  This is a snub nosed blaster rifle. Its total length is around 3 feet,\n"+
"its steel body painted a dark black. The stock is an extendable steel\n"+
"tube curved and coated for comfort and durability. The barrel is about\n"+
"one foot in length, a grip lining its underbelly for more accurate aiming.\n"+
"A slot located near the front and under the barrel is used for the loading\n"+
"of energy clips.\n");   
return 1;
}

short(){
shots();	
if(wielded){	
   return "Blaster Rifle ["+HIR+"ammo: "+shot_mess+""+NORM+"] (wielded)"; 	
   }
else{
   return "Blaster Rifle ["+HIR+"ammo: "+shot_mess+""+NORM+"]"; 	
   }
}

shots(){
if(shots >= 200){
	shot_mess = "full charge";
}
else if(shots >= 120){
	shot_mess = "good charge";
}
else if(shots >= 80){
	shot_mess = "half charge";
}
else if(shots >= 30){			
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
write("You grab a clip and load the blaster rifle.\n");
set_message_hit(({
	          HIR+"Crippled"+NORM, " with a direct laser shot",
                  HIR+"Blasted"+NORM, " in the torso",
                  HIR+"Struck"+NORM, " with a searing white hot laser shot",
                  HIR+"Seared"+NORM, " with a direct hit",
                  HIR+"Hit"+NORM, " with a blaster round",
                  HIR+"Hit"+NORM, "", 
                  HIR+"Singed"+NORM, " with a glancing shot"
                  }));
    
    shots = 200;
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
  "You swing the Blaster Rifle like a club as you fight your opponent hand-to-hand.\n");
  return random(4) + 2;
  }

 if(!shots){
  set_message_hit(({"massacre"," to small fragments","smashed",
                  " with a bone crushing sound","hit"," very hard","hit"," hard","hit","",
                  "grazed","","tickled"," in the stomach"}));	
  tell_object(environment(), 
  "Your Blaster Rifle is out of ammo! You start bashing your opponent with it\n"+
  "like a club!\n");
  return random(4) + 2;
  }
 shots -= 1;
 dam = random(8) + 18;
 if(random(500) < USER->query_attrib("ste")){
  tell_object(USER,
  HIR+"["+NORM+BOLD+"C R I T I C A L"+NORM+HIR+"]"+NORM);
  dam += random(10);
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

