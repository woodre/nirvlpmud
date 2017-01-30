#include "/players/chip/ansi.h"
inherit "obj/monster.c";
#define POS query_possessive()

static int done3n, dtwo3n;
static string hit3;
static string part3;
static int done1n, dtwo1n;
static string hit1;
static string part1;
static int done2n, dtwo2n;
static string part2n;
static defense_bonus;
string shapetype;
int saved_money;
int sp,mp;
object webbed;
object remember;
int hyper_mode;
int bdelay;
string symb_name;
int base_wc,base_ac;
object challenger;
object sponsor;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_name("symbiote");
set_race("symbiote");
set_level(20);
set_al(0);

set_hp(3000);
set_wc(1);
set_ac(1);

set_wc_bonus(95); /* upped from 90 so the fight is more worth it for the upgrades the guild is recieving -Chip(4-17-09) */
set_ac_bonus(20); /* upped from 15 so the fight is more worth it for the upgrades the guild is recieving -Chip(4-17-09) */

set_heart_beat(1);
mp = 300;
sp = 600;
set_dead_ob(this_object());
  message_hit=({
      ""+HIR+"D E M O L I S H E D"+NORM+"", " with a blur of "+HIK+"violence"+NORM+"",
      ""+RED+"eviscerated"+NORM+"", "'s body into a "+RED+"bloody mess"+NORM+"", 
      ""+HIW+"gored"+NORM+"", " with an "+WHT+"onslaught"+NORM+" of "+BLK+"destruction"+NORM+"",
      ""+HIW+"disemboweled"+NORM+""," and they "+HIR+"bleed profusely"+NORM+"",
      ""+RED+"slung"+NORM+""," to the ground, smashing "+HIW+"bones"+NORM+"",
      ""+HIW+"smashed"+NORM+""," with a "+HIW+"bone "+BLK+"crushing"+NORM+" sound",
      "hit"," very hard",
      "hit"+NORM+""," hard",
      "hit"+NORM+"","",
      "grazed"+NORM+"","", 
      "tickled"+NORM+""," in the stomach",
      });
       
}

set_saved_money(int i){ saved_money = i; }
query_saved_money(){ return saved_money; }

webslam(i){
int damage;
if(i){
damage = random(55) + 10; /*upped this from random(45) + 10 for more challenge, since the guild is getting power upgrades. no guts, no glory! -Chip(4-16-09)*/
}
else damage = random(25) + 10; /*upped this from random(15) + 10 for more challenge, since the guild is getting power upgrades. no guts, no glory! -Chip(4-16-09)*/

tell_room(environment(),
"A spray of "+HIW+"silky webs"+NORM+" ejects from "+capitalize(symb_name)+"'s palms.\n"+ 
"The "+HIW+"webs"+NORM+" hit "+attacker_ob->query_name()+" in the chest, giving "+capitalize(symb_name)+" control of the fight.\n");
if(damage > 33){
tell_room(environment(),
capitalize(symb_name)+" slams "+attacker_ob->query_name()+" into the ground "+HIR+"C R U S H I N G"+NORM+" bones.\n");
}
else if(damage > 28){
tell_room(environment(),
capitalize(symb_name)+" spins "+attacker_ob->query_name()+" about "+HIR+"dislocating"+NORM+" some joints.\n");
}
else if(damage > 20){
tell_room(environment(),
capitalize(symb_name)+" lifts "+attacker_ob->query_name()+" into the air, "+RED+"dropping"+NORM+" them on their head.\n");
}
else if(damage > 15){
tell_room(environment(),
capitalize(symb_name)+" tosses "+attacker_ob->query_name()+" through the air, and they land with a soft thump.\n");
}
else if(damage > 10){
tell_room(environment(),
capitalize(symb_name)+" flips "+attacker_ob->query_name()+", sending them half way across the room.\n");
}
else{
tell_room(environment(),
capitalize(symb_name)+" slings "+attacker_ob->query_name()+", a short distance. They land on their feet.\n");
}
attacker_ob->hit_player(damage);

}

heart_beat(){
::heart_beat();
 
 if(!challenger){ destruct(this_object()); return; }



if(attacker_ob && !remember){
   remember = attacker_ob;
   }

if(!attacker_ob && remember){
   attacker_ob = remember;
   }

weapon_class = base_wc;
armor_class = base_ac;

if(sp < 599) sp += 2;

if(sp > 15 && attacker_ob){
 if(sp > 50){
  webslam(1);
  sp -= 50;
  }
else webslam();
  sp -= 15;
  }
if(random(100) < 50 && sp > 20 && attacker_ob && !webbed){
   tell_object(attacker_ob,
   BOLD+"\n\n"+capitalize(symb_name)+" stretches out it's symbiotic hand...\n"+
   "A "+WHT+"sticky webbing"+NORM+" sprays from it and covers you from head to toe!"+NORM+"\n\n");
   webbed = attacker_ob;
   sp -= 20;
   }
if(sp > 50 && !hyper_mode && attacker_ob){
   hyper_mode += 30;
   tell_room(environment(), 
"\n"+capitalize(symb_name)+" yells...\n\n\n"+
HIY+"     <<<==--**<<< "+NORM+RED+"H Y P E R M O D E"+NORM+HIY+" >>>**--==>>>     "+NORM+"\n\n\n");
   sp -= 50;
   }

if(attacker_ob){
 weapon_class += proficiency_hit();
 armor_class += venom_defense();
 }
}
short(){ if(symb_name) return BOLD+capitalize(symb_name)+"   ("+NORM+HIR+" Symbiote "+NORM+BOLD+")"+NORM;
         return BOLD+"A Symbiote"+NORM; 
       }

long(){
     write(
"  Separated from you, its host, "+BOLD+""+capitalize(symb_name)+""+NORM+" is fighting\n"+
"for its freedom. It is a wavering form of a being that does\n"+
"posess all of the same abilities as it did before its recent\n"+
"separation.\n");
 return 1;
 }

  


set_wc(int i){ if(!base_wc) base_wc = i; weapon_class = i; }
set_ac(int i){ if(!base_ac) base_ac = i; armor_class = i; }


set_symb_name(str){ symb_name = str; }
query_symb_name(){ return symb_name; }


slamtwo(){
int damageone;

if(random(100) < 60){
tell_object(attacker_ob,
"<"+HIR+"slam"+NORM+"> "+capitalize(symb_name)+" slams their weapon across your midsection0.\n"+
"You scream as you feel your ribs break and your organs rupture!\n");
damageone = 10;
}
else{
tell_object(attacker_ob,
capitalize(symb_name)+" grabs you by the leg.\n"+
"You see a blur as your are spun around in the air.\n"+
"You are tossed like a ragdoll right into a wall!\n");
damageone = 15;
}

return damageone;
 }


bitetwo(){
int damageone;

random_part2n();

tell_object(attacker_ob,
"<"+HIR+"bite"+NORM+"> "+capitalize(symb_name)+"'s mouth opens wide and leaps. Flesh is ripped from the bone.\n");
dtwo2n = 3;
 
damageone = done2n + dtwo2n;
if(hit_point < 900){
hit_point += random(2)+4;
}   
return damageone;
}


clawstwo(){
int damageone;

random_part1n();
random_hit1n();

tell_object(attacker_ob,
"<"+HIR+"claw"+NORM+"> "+capitalize(symb_name)+" "+hit1+" you in the "+part1+".\n");
damageone = done1n + dtwo1n;
return damageone;
}      


kicktwo(){
int damageone;


random_part32n();
random_hit32n();

tell_object(attacker_ob,
"<"+HIR+"kick"+NORM+"> "+capitalize(symb_name)+" "+hit3+"'s you in the "+part3+".\n");
damageone = done3n + dtwo3n;

return damageone;
 }      
    


  
random_hit32n(){
switch(random(5) + 1){
case 4..5:
   hit3 = "slam";
   dtwo3n = 5;
  break;
case 1..3:
   hit3 = "kick";
   dtwo3n = 2;
  break;
default:
   hit3 = "kick";
   dtwo3n = 2;
  break;          
  }
}
random_part32n(){
switch(random(20) + 1){
case 19..20:
  part3 = "face";
  done3n = 5;
 break;
case 17..18:
  part3 = "chest";
  done3n = 3;
 break;
case 11..16:
  part3 = "arm";
  done3n = 1;
 break;
case 6..10:
  part3 = "leg";
  done3n = 1;
 break;
case 1..5:
  part3 = "hand";
  done3n = 1;
 break;
default:
  part3 = "hand";
  done3n = 0;
 break;
   }
  } 
    


  
random_hit1n(){
switch(random(10) + 1){
case 8..10:
   hit1 = "ripped";
   dtwo1n = 5;
  break;
case 5..7:
   hit1 = "slashed";
   dtwo1n = 3;
  break;
case 1..4:
   hit1 = "grazed";
   dtwo1n = 1;
  break;
default:
   hit1 = "miss";
   dtwo1n = 0;
  break;          
  }
}

random_part1n(){
switch(random(20) + 1){
case 19..20:
  part1 = "face";
  done1n = 5;
 break;
case 15..18:
  part1 = "chest";
  done1n = 3;
 break;
case 13..14:
  part1 = "arm";
  done1n = 1;
 break;
case 8..12:
  part1 = "leg";
  done1n = 1;
 break;
case 1..7:
  part1 = "hand";
  done1n = 1;
 break;
default:
  part1 = "hand";
  done1n = 1;
 break;
   }
  } 

  
random_part2n(){
switch(random(20) + 1){
case 19..20:
  part2n = "face";
  done2n = 5;
 break;
case 16..18:
  part2n = "chest";
  done2n = 5;
 break;
case 11..15:
  part2n = "arm";
  done2n = 3;
 break;
case 6..10:
  part2n = "leg";
  done2n = 3;
 break;
case 1..5:
  part2n = "hand";
  done2n = 1;
 break;
default:
  part2n = "hand";
  done2n = 1;
 break;
   }
  }

venom_defense(){
	int def;
	def = random(120);
	defense_bonus = 0;
	if(!attacker_ob) return 0;
	if(def > 85){
		tell_room(environment(),
			"Tendrils reach out from "+capitalize(symb_name)+".\n"+
			""+attacker_ob->query_name()+" fights for control of "+attacker_ob->POS+" weapon.\n"+
		""+attacker_ob->query_name()+" is slowly overtaken.\n");
		defense_bonus = 14;
	}
	else if(def > 64){
		tell_room(environment(),
			capitalize(symb_name)+" headbutts the on coming attack.\n"+
			capitalize(symb_name)+" screeches in ecstasy.\n"+
		""+attacker_ob->query_name()+" cringes.\n");
		defense_bonus = 7;
		
	}
	else if(def > 55){
		tell_room(environment(),
		capitalize(symb_name)+" smacks the attack aside.\n");
		defense_bonus = 5;
		
	}
	else if(def > 35){
		tell_room(environment(),
		capitalize(symb_name)+" tenses up absorbing most of the impact.\n");
		defense_bonus = 3;
		
	}
	else if(def > 5){
		tell_room(environment(),
		capitalize(symb_name)+" leaps aside.\n");
		defense_bonus = 1;
	}
    defense_bonus += 9;
	return defense_bonus;
}


proficiency_hit(ob){

string mess1,mess11,mess2,mess22;
int base;
int dam1, dam2, dam3, dam4;
int rand1, rand2, rand3, rand4;
int weptype;
int damage_bonus;
dam1 = 0;
dam2 = 0;
dam3 = 0;
dam4 = 0;
rand1 = random(100);
rand2 = random(100);
rand3 = random(100);
rand4 = random(100);
weptype = random(4);
base = random(21);	
if(base < 16) base = 16;


if(!weptype){
switch(random(10)){
case 7..100:
mess1 = "slash";
mess11 = "slashes";
break;
case 4..6:
mess1 = "stab";
mess11 = "stabs";
break;
case 1..3:
mess1 = "slice";
mess11 = "slices";
break;
default:
mess1 = "stab";
mess11 = "stabs";
break;
 } 
}
else if(weptype == 1){
switch(random(10)){
case 7..100:
mess1 = "smash";
mess11 = "smashes";
break;
case 4..6:
mess1 = "slam";
mess11 = "slams";
break;
case 1..3:
mess1 = "hit";
mess11 = "hits";
break;
default:
mess1 = "hit";
mess11 = "hits";
break;
 } 
}
else if(weptype == 2){
switch(random(10)){
case 7..100:
mess1 = "stab";
mess11 = "stabs";
break;
case 4..6:
mess1 = "impale";
mess11 = "impales";
break;
case 1..3:
mess1 = "thrust";
mess11 = "impales";
break;
default:
mess1 = "impale";
mess11 = "impales";
break;
 } 
}
else if(weptype == 3){
switch(random(10)){
case 7..100:
mess1 = "chop";
mess11 = "chops";
break;
case 4..6:
mess1 = "cleave";
mess11 = "cleaves";
break;
case 1..3:
mess1 = "slash";
mess11 = "slashes";
break;
default:
mess1 = "slash";
mess11 = "slashes";
break;
 } 
}


switch(random(10)){
case 7..100:
mess2 = "chest";
break;
case 4..6:
mess2 = "arm";
break;
case 1..3:
mess2 = "leg";
break;
default:
mess2 = "arm";
break;
 } 

if(weptype == 0) shapetype = "Sword";
else if(weptype == 1) shapetype = "Maul";
else if(weptype == 2) shapetype = "Spear";
else if(weptype == 3) shapetype = "Axe";

if(mess1 && mess2 && attacker_ob){
 tell_room(environment(),
 query_name()+" "+mess11+" "+attacker_ob->query_name()+" in the "+mess2+" with his "+shapetype+" arm!\n");
 base += random(5) + 10;
 }


if(rand1 < 21){
  dam1 = slamtwo();
   }
else if(rand1 < 45){
  dam1 = bitetwo();
   }
else if(rand1 < 50){
  dam1 = kicktwo();
   }
else if(rand1 < 70){
  dam1 = clawstwo();
  }

if(rand2 < 45){
  dam2 = bitetwo();
   }
else if(rand2 < 55){
  dam2 = kicktwo();
   }
 else if(rand2 < 75){
  dam2 = clawstwo();
  }
 else{ dam2 = 0; }

if(hyper_mode){
if(rand3 < 30){
  dam3 = slamtwo();
   }
else if(rand3 < 60){
  dam3 = bitetwo();
   }
else if(rand3 < 80){
  dam3 = kicktwo();
   }
else if(rand3 < 95){
  dam3 = clawstwo();
  }	  

if(rand4 < 30){
  dam4 = slamtwo();
  }
else if(rand4 < 60){
  dam4 = clawstwo();
  }	
else if(rand4 < 80){
  dam4 = bitetwo();
   }
else if(rand4 < 95){
  dam4 = kicktwo();
   }
base += 10; 
} 		
damage_bonus = dam1 + dam2 + dam3 + dam4;

if(webbed && !present(webbed, environment())){
   webbed = 0;
   }
if(webbed && present(webbed, environment())){
   base += random(20) + 9;
   tell_object(webbed,
   HIR+"You struggle in the webbing!"+NORM+"\n");  
   }
 if(damage_bonus > 0){
 
   base += damage_bonus;
  }
 return base;	
}


query_message_hit(tmp) {
  string *mess;

 if (tmp > 55) {
  mess = ({message_hit[1],message_hit[0]}); 
  }
  else if (tmp > 45){
  mess = ({message_hit[3],message_hit[2]});
  }
  else if (tmp > 35){
  mess = ({message_hit[5],message_hit[4]});
  }
  else if (tmp > 30) {
  mess = ({message_hit[7],message_hit[6]});
  }
  else if (tmp > 25) {
  mess = ({message_hit[9],message_hit[8]});
  }
  else if (tmp > 20) {
  mess = ({message_hit[11],message_hit[10]});
  }
  else if (tmp > 10) {
  mess = ({message_hit[13],message_hit[12]});
  }
  else if (tmp > 5) {
  mess = ({message_hit[15],message_hit[14]});
  }
  else if (tmp > 3) {
  mess = ({message_hit[17],message_hit[16]});
  }
  else if (tmp > 1) {
  mess = ({message_hit[19],message_hit[18]});
  }
  else if (tmp == 1){
  mess = ({message_hit[21],message_hit[20]});
  }
  
  return mess;
}


set_challenger(ob){ challenger = ob; }
query_challenger(){ return challenger; }

set_sponsor(ob){ sponsor = ob; }

monster_died(){
object woooo;
int x, y, z;
   if(!challenger)
   {
      write("Challenger not Found.  Please talk to Fred.\n");
      return;
   }
   if(!present(challenger, environment(this_object())))
   {
      write("Challenger not here.\n");
      return;
   }
   /*
   if(attacker_ob != challenger || alt_attacker_ob != challenger)
   {
      write("Challenger was not the attacker.\n");
      return;
   }
   */
   write_file("/players/chip/venom2/log/challenged!",
   challenger->query_name()+" defeated symbiote on "+ctime(time())+".\n");
   tell_object(challenger,
   "\n\n\n\nYou have dominated your Symbiote, and it now knows who the true slave is.\n\n\n\n"+
   "It bows its head in shame and reenters your body.\n"+
   "You are once again one with "+capitalize(symb_name)+"\n");                
woooo = clone_object("/players/chip/venom2/neo_venom.c");
woooo->set_stored_coins(saved_money);
woooo->set_venom_name(symb_name);

  /*  Set the players exp to their base lvl requirement.
      No brining free exp into the guild.
  */

   x = challenger->query_extra_level();
   y = challenger->query_exp();   

   z = call_other("/room/exlv_guild","get_next_exp",x-1);

   x = y-z;
 
   challenger->add_exp(-x);
 
   /*  End  */
 
   move_object(woooo, challenger);
   if(present("corpse", environment())){
    destruct(present("corpse", environment()));
    return 1;
    }
   return 1;
   }

remove_recruit_attempt()
{
  if(!(find_player(sponsor)))
  {
    write_file("/players/chip/venom2/log/sponsor",
      sponsor->query_name()+" not found.\n");
    return 1;
  }
  present("new_venom_object", find_player(sponsor))->add_recruit(-1);
  return 1;
}
