static string part,hit,type;
static int done,dtwo,total_dmg;
#define ATTMW USER->query_attack()
#define ATTMN ATTMW->query_name()

martial_arts(){

random_part();
random_hit();
random_type();

if(random(100) < ((query_skill("martial_arts")*5)+20)){
tell_object(USER,
""+HIR+"-<>-"+NORM+" ");	
tell_object(USER,
"You "+hit+" "+ATTMN+" in the "+part+" with a "+type+"!\n");
	
tell_object(ATTMW,
USER->query_name()+" "+hit+" you in the "+part+" with a "+type+"!\n");

total_dmg = done + dtwo;
ATTMW->heal_self(-(total_dmg));
      }
else{ 

tell_object(ATTMW,
USER->query_name()+" misses you with a "+type+".\n");

tell_object(USER,
""+HIR+"-<>-"+NORM+" You miss "+ATTMN+" with a "+type+".\n");
  }
}

random_type(){
switch(random(20) + 1){	
case 19..100:
   type = "flying side-kick";
   break;
case 17..18:
   type = "roundhouse kick";
   break;
case 15..16:
   type = "double quick-kick";
   break;
case 13..14:
   type = "roundhouse punch";
   break;
case 11..12:
   type = "quick jab";
   break;
case 9..10:
   type = "whirling knee slam";
   break;
case 7..8:
   type = "graceful sweep kick";
   break;
case 5..6:
   type = "rolling side kick";
   break;
case 3..4:
   type = "backhanded swing";
   break;
case 1..2:
   type = "twisting elbow-slam";
   break;
default:
   type = "quick jab";
   break;
  }
 }                             

  
random_hit(){
switch(random(20) + 1){
case 19..100:
   hit = "Pulverized";
   dtwo = 5;
  break;
case 16..18:
   hit = "Smashed";
   dtwo = 4;
  break;
case 12..15:
   hit = "Bashed";
   dtwo = 3;
  break;
case 7..11:
   hit = "Hit";
   dtwo = 2;
  break;
case 1..6:
   hit = "Grazed";
   dtwo = 1;
  break;
default:
   hit = "miss";
   dtwo = 0;
  break;          
  }
}
random_part(){
switch(random(20) + 1){
case 19..100:
  part = "head";
  done = 4;
 break;
case 18:
  part = "chest";
  done = 4;
 break;
case 17:
  part = "back";
  done = 3;
 break;
case 16:
  part = "face";
  done = 2;
 break;
case 15:
  part = "arm";
  done = 2;
 break;
case 14:
  part = "leg";
  done = 2;
 break;
case 13:
  part = "kneecap";
  done = 3;
 break;
case 12:
  part = "hand";
  done = 1;
 break;
case 11:
  part = "foot";
  done = 1;
 break; 
case 10:
  part = "ankle";
  done = 2;
 break;
case 9:
  part = "shoulder";
  done = 2;
 break;
case 8:
  part = "wrist";
  done = 1;
 break;
case 7:
  part = "stomach";
  done = 3;
 break;
case 6:
  part = "groin";
  done = 3;
 break;
case 5:
  part = "neck";
  done = 3;
 break;
case 4: 
  part = "jaw";
  done = 3;
 break;
case 3:
  part = "forearm";
  done = 2;
 break;
case 2:
  part = "back of the head";
  done = 4;
 break;
case 1:
  part = "forehead";
  done = 3;
 break;
default:
  part = "finger";
  done = 1;
 break;
 }
} 