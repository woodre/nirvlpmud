/* this weapon is held by the Archangel of Death in the Ruins area. The mob is not overly easy
   since it heals itself in combat and is otherwise tough. The weapon itself has a second attack
   ability which can also heal for half the damage done. The drawbacks are as follows:
   1. No shield while wielding the gloves, shields are immediately destroyed when worn.
   2. the glove has a chance to do damage to the player if they are not in combat
   3. wielding the wep will do 25 damage to the player.
   I hope you find this weapon to be unique and interesting.
   Added Bounty reward 6-18-99 Maledicta     */
   

#include "/players/maledicta/ansi.h"
#define USER environment(this_object())
inherit "obj/weapon.c";
int collect;
string str;
reset(arg){
  ::reset(arg);
  if (arg) return;
set_collect(random(3000) + 4000);
set_name("gloves");
set_alt_name("glove");
set_alias("death");
set_long(
  "   Looking at these gloves you see that they are made from\n"+
  "some type of heavy metal, although you are not sure what\n"+
  "type it might be. The long slender fingers are tipped with\n"+
  "cruel razor sharp blades, the knuckles covered with long\n"+
  "spikes.  You feel a terrible power eminating from its cool\n"+
  "surface, giving you a feeling of dread and awe at the same\n"+
  "time.  Even though they are items to be worn, you feel that\n"+
  "you should 'wield' them instead.\n");

set_type("knife"); 
set_class(800);
set_weight(4);
set_value(1000);
set_wield_func(this_object());
set_hit_func(this_object());
set_message_hit(({BOLD+BLK+"Destroyed"+NORM," with the force of Death",BOLD+BLK+"Slammed"+NORM,
         " to the ground",BOLD+BLK+"Punched"+NORM," with unmatched fury",
         BOLD+BLK+"Smacked"+NORM," with a solid hit",BOLD+BLK+"Hit"+NORM," with some force",
         BOLD+BLK+"Backhanded"+NORM,"",BOLD+BLK+"grazed"+NORM," with a glancing blow"}));
set_save_flag(1);
}
set_collect(int n){ collect = n; }
query_collect(){ return collect; }
init(){
   ::init();
   add_action("collect_reward", "collect");
   }	
short(){
	if(this_object()->query_wielded()){
	return "Glove of "+BOLD+""+BLK+"Life Stealing"+NORM+" [left]  (wielded)\n"+
               "Glove of "+BOLD+""+BLK+"Life Stealing"+NORM+" [right] (wielded)"; }
        else { return "Glove of "+BOLD+""+BLK+"Life Stealing"+NORM+" [left] \n"+
                      "Glove of "+BOLD+""+BLK+"Life Stealing"+NORM+" [right]"; }       	
}
two_handed(){ return 1; } 

id(str) {
  if(previous_object()) {
  if(!test_my_wear(previous_object())) {
    return str == "glove" || str == "gloves" ||
    str == "notarmor";
     }
   }
  return str == "glove" || str == "gloves"; 
}

test_my_wear(ob) {
  string atype;
  if(!this_object()->query_wielded()) return 1;
  if(!USER) return;
  atype = ob->query_type();
  if(!atype) return;
  
    if(atype == "shield") return 0;
    
  else return 1; }


  	 	
/* randomly has an 8% chance of causing 10 damage to the player every 15 hb's if they
   are not in combat */
void
hurt_me() {
    if (environment() && living(environment()) && (random(100) < 8) &&
        environment(this_object())->query_attack() == 0) {
	tell_object(environment(), 
	""+HIR+"You feel an intense pain as the gloves feed from your lifeforce!"+NORM+"\n"+
	"A voice screams into your head: DO NOT STAND AROUND! FIGHT!\n");
	environment(this_object())->add_hit_point(-10);
        remove_call_out("hurt_me");
	call_out("hurt_me", 15);
    }
    remove_call_out("hurt_me");
    call_out("hurt_me", 15);
}

no_wield(){
	 object shield;
 object ob;	
 ob = first_inventory(USER);
 shield = present("shield", environment());
 if(environment() && living(environment())) { 
  while(ob){
     string arm;
     int worn;
     arm = call_other(ob, "query_type");
     worn = call_other(ob, "query_worn");
 if(arm == "shield" && worn){
 	tell_object(USER,
 	"You cannot wield the gloves while using a shield.\n"); 
        return 1; 
        }
        ob = next_inventory(ob);
        }
  return 0;}
}

 mixed
 wield(mixed str) {
if(no_wield()) return 1; 
if(objectp(str)){
 	   
 call_out("hurt_me", 15);
 write(""+BOLD+""+RED+"");
 write("You place the gloves onto your hands and feel a terrible pain as they feed from\n"+
       "your life force!");
 write(""+NORM+"\n");      
 write("A voice screams into your head: FEED ME!!!\n");
 USER->add_hit_point(-25);
  return 1;
   }
 return ::wield(str);
}


un_wield() {
    if (wielded)
        wielded = 0;
wielded_by = 0;
remove_call_out("hurt_me");

return 1;
}

stopwield() {
    if (environment() != this_player()) return 0;
   remove_call_out("hurt_me");
   call_other(this_player(), "stop_wielding");
   wielded = 0;
   wielded_by = 0;
   return 1;
}


/* When weapon hit is called has a 25% chance of going off. If it does, has the same effect
   as a second attack- damage range: 0-26. Will also heal for 1/2 the damage done. */ 
weapon_hit(attacker){
int num;
int W;
string *mess;
W = random(900);
if(W >= 16)  {
      num=random(27);
      if(num < 1) {
         write("You missed.\n");
         say(wielded_by->query_name()+" missed.\n");
         return 0;
      }
      mess=query_message_hit(num + 3);

      write("You "+mess[1]+" "+attacker->query_name()+mess[0]+".\n");
      say(wielded_by->query_name()+" "+mess[1]+" "+attacker->query_name()+mess[0]+".\n");
      
      if((attacker->query_hp() - 10) > num){ 
      	attacker->hit_player(num);
if(random(100) < USER->query_attrib("ste")){ 
write(
HIM+"You grasp your opponent with both gloves and feel a rush of power!"+NORM+"\n\n");
        USER->add_hit_point(random(4) + 1);
        }
        return 0;
     }
if(random(100) < USER->query_attrib("ste")){ 
write(
HIM+"You grasp your opponent with both gloves and feel a rush of power!"+NORM+"\n\n");
        USER->add_hit_point(random(4) + 1);      
         }
        }
     } 
      
set_short(sh) { short_desc = sh; }

collect_reward(string str){
  int coins;
      if(!str){ write("What?\n"); return 1; }
      if(str == "bounty"){
      if(!present("eghyron", environment(this_player()))){
		write("What?\n");
		return 1;
	}
	coins = this_object()->query_collect();
	this_player()->add_money(coins);
	write("Eghyron congratulates you.\n");
	write("He says: You defeated the Archangel of Death, VERY impressive!\n");
	write("He hands you "+coins+" coins for your most excellent work!\n");
	destruct(this_object());
	return 1;
     }
     write("What?\n");
     return 1;
}   