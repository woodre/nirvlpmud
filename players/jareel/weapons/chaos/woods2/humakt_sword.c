/* Changed by Fred on 7.20.2010 because 
   like most of Jareel's stuff seems to
   be it's completly BS. An 87% chance of 
   an extra hit_player()?  A 12% chance of
   a hit_player(10+random(40))?  WTF.

   Initial testing dual wield before changes
   after 100 rounds vs ac 17 was:
   Total Dmg: 4385
   Avg. Dmg: 43.85
   Max. Dmg: 114

   After changes 100 rounds vs ac 17:
   Total Dmg: 2838
   Avg. Dmg: 28.38
   Max. Dmg: 68

   For comparison elemental weapons
   100 rounds vs ac 17:
   Total Dmg: 2933
   Avg. Dmg: 29.33
   Max. Dmg: 72
*/  

/* Wep Average with Charge activated
   Hits  Average  Max
   583    11.57   56

   Wep Average without charge activated
   Hits  Average  Max
   570     4.19   26                    */

#include "/players/jareel/define.h"
inherit "obj/weapon.c";
#define ATT USER->query_attack()
#define USER environment(this_object())
#define SPEED "Your motions blur with deadly speed and grace.\n"
#define RUSH "You slash your sword deep into your foe.\n"
#define SPEED1 environment()->query_name()+"'s form blurs with deadly speed and grace.\n"
int bladesharp;
int energize;
int MAGIC;

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("blackdeath, sword of truth");
   set_alias("blackdeath");
   set_type("sword");
   get_short();
   set_class(21);
   set_weight(2);
   set_value(8000);
   set_long(
      BOLD+"A 'Truesword' one of the deadliest weapons ever forged.  Bearing\n"+
      "the mark of the blacksmith Groum, it gleams in the light.  Blessed by\n"+
      "the god Humakt himself. Blackdeath will stike strait and true. \n");
   set_hit_func(this_object());
   message_hit = ({
     "cleave"," with a powerfull slash",
     "slash"," causing dreadful agony",
     "pierced"," with the sword's razor edge",
     "gash"," with a deadly grace",
     "impale"," with a vicious lunge",
     "prodded"," with gusto",
     "tickled"," with a weak slash" });

}

weapon_hit(attacker){
  int i;

  if(energize != 1) {
    return 0;   
  }

  i = random(8);
  if(i==7){
    if(!attacker) return 1;
   write(HIK+""+HIK+"Blackdeath"+NORM+" bites deep\n"+NORM);
   say(HIK+environment()->query_name()+"'s sword bites into his foe.\n"+NORM);
   attacker->hit_player(1+random(5), "other|physical");
  }

  if(i==6){
    if(!attacker) return 1;
   write(HIK+"Blackdeath cuts deep\n"+NORM);
   say(HIK+environment()->query_name()+"'s cuts deep.\n"+NORM);
   attacker->hit_player(1+random(4), "other|light"); /* changed from 6 to 4 - Fred */
  
  }

  if(i==5){
    if(!attacker) return 1;
   write(HIK+"The power of Truth burns deep as Blackdeath strikes...\n"+NORM);
   say(HIK+environment()->query_name()+"'s sword burns deed as it strikes.\n"+NORM);
   attacker->hit_player(1+random(4), "other|physical"); /* changed from 6 to 4 - Fred */
  
  }

  if(i==4){
    if(!attacker) return 1;
   write(HIK+SPEED+RUSH+SPEED+SPEED+RUSH+SPEED+NORM);
   say(SPEED1+SPEED1+SPEED1+NORM);
   /* Commented out complete BS - Fred
   attacker->hit_player(10+random(40), "other|physical");
   */
  }

  if(i==3){
    if(!attacker) return 1;
   write(HIK+"You slash your opponent.\n"+NORM);
   attacker->hit_player(1+random(4), "other|dark");
  
  }

  if(i==2){
    if(!attacker) return 1;
   write(RED+"You slash your foe with deadly grace.\n"+NORM);
   attacker->hit_player(5+random(3), "other|physical");
  }

  if(i==1){
    if(!attacker) return 1;
   write(HIK+"You hit your foe with a "+HIR+"C R I T I C A L"+NORM+HIK+"  strike!"+NORM+"\n");
   say(HIK+environment()->query_name()+"'s his his foe with a "+HIR+"C R I T I C A L"+NORM+" strike.\n"+NORM);
   attacker->hit_player(4+random(5), "other|Jareel"); /* changed from 11+r9 to 4+r5 */
  }
}

status wield(string str) {
   int x,s;

   if(!id(str)) return 0;

   if(environment()!=TP) return 0;

   if ((status)this_player()->query_pl_k() != 1) { write("Set your pk flag bitchboy.\nTil then use some other crappy ass weapon.\n");
     return 1; }


   if(present("notweapon",this_player())) {
      write("For some reason you are unable to wield this weapon.\n");
      return 1;
   }
   
   if (wielded) {
      write("You already wield it!\n");
      return 1;
   }
   
   wielded_by = this_player();
   call_other(this_player(), "wield", this_object(), silentwield);
   wielded = 1;
   
   return 1; 
}
   
init(){
   ::init();
   add_action("truecharge","truesword");
}
   
check_wielded(){

   if(this_player()->query_weapon() == this_object()){
     return 1; 
   }
   
   else {
     notify_fail(BOLD+"You must be wielding the scimitar.\n"+NORM);
     return 0;  
   }
}
   
check_magic(){
   int i;

   i = this_player()->query_attrib("int");
   if(i > 30) i = 30;
   if(i < 0) i = 0;
   return i; 
}

truecharge(){
   int time;

   MAGIC = check_magic();
   if(check_wielded() == 0) return 0;

   if(this_player()->query_spell_point() < 50){
     notify_fail(BOLD+"You lack the energy to charge "+HIK+"Blackdeath"+HIK+".\n"+NORM);
     return 0;  
   }

   this_player()->add_spell_point(-50);
   energize = 1;
   get_short();
   time = ((1500+random(1500))*MAGIC)/2; 
   call_out("remove_energy",time);
   write(HIG+"\nAn energy surge flows into the blade.....\n\n"+
   "        "+NORM+"\n");
   return 1;  
}
   
remove_energy(){
   write(HIG+"The energy fades from the sword....\n"+NORM);
   say(HIG+"The energy from the sword fades....\n"+NORM);
   energize = 0;
   get_short();
   return 1;  
}
   
get_short(){
   string str;
   str = ""+HIK+"Blackdeath"+NORM+", Broadsword of "+HIK+"Truth"+NORM+"";

   if(energize == 1){
     str += ""+HIK+"  ["+NORM+BOLD+"TrueSword "+HIK+"]"+NORM+"";
   }

   set_short(str);
}

query_wear(){ return 1; }
