

#include "/players/maledicta/ansi.h"
inherit "obj/weapon";
#include "/players/maledicta/include/setwc.h"
int shots,loaded;
string shot_mess;

reset(arg){
  ::reset(arg);
  if (arg) return;

set_long(
"  This is a snub nosed blaster rifle. Its total length is around 3 feet,\n"+
"its steel body painted a dark black. The stock is an extendable steel\n"+
"tube curved and coated for comfort and durability. The barrel is about\n"+
"one foot in length, a grip lining its underside for more accurate aiming.\n"+
"A slot located near the front and under the barrel is used for the loading\n"+
"of energy clips.\n");   


set_type("gun");

set_weight(3);
set_value(1000);
set_hit_func(this_object());
}
two_handed(){ return 1; }

query_save_flag(){ return 0; }

weapon_class(){
	if(shots){
		return 16;
	}
	else{
	return 6;
   }
}	

id(str){
return str == "blaster" ||
       str == "rifle"  || 
       str == "blaster_weapon_derellia" ||
       str == "gun_rifle_object" ||
       str == "gun";
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
if(shots >= 1000){
	shot_mess = "full charge";
}
else if(shots >= 650){
	shot_mess = "good charge";
}
else if(shots >= 400){
	shot_mess = "half charge";
}
else if(shots >= 200){			
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
int attacks;
int how_hard;
attacks = random(5)+1;
damage = 0;
how_hard = random(10)+1;
shots -= 1;

switch(how_hard){
  case 10:
     damage = random(6) + 4;
   break;
  case 7..9:
     damage = random(5) + 4;
   break;
  case 4..6:
     damage = random(4) + 4;
   break;
  case 1..3:
     damage = 4;
   break;
  default:
     damage = 2;
   break;
}	

if(shots <= 0){
write("Having run out of ammo you start to bash your opponent with the stock of your rifle!\n");
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
if(shots && random(100) < 25){
while(attacks){
  if(shots < 5){
  write("Your gun is too low on energy!\n");
  return 0;
  }

 write(""+HIR+"<<<<+>>>>"+NORM+" You fire a barrage of shots at "+attacker->query_name()+"!\n");
 shots -= 4;
 damage += 4;
 attacks --;
  }

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
write("You grab a clip and load the blaster rifle.\n");
this_object()->set_message_hit(({
	          HIR+"Crippled"+NORM, " with a direct laser shot",
                  HIR+"Blasted"+NORM, " in the torso",
                  HIR+"Struck"+NORM, " with a searing white hot laser shot",
                  HIR+"Seared"+NORM, " with a direct hit",
                  HIR+"Hit"+NORM, " with a blaster round",
                  HIR+"Hit"+NORM, "", 
                  HIR+"Singed"+NORM, " with a glancing shot"
                  }));
    
    shots = 1000;
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

