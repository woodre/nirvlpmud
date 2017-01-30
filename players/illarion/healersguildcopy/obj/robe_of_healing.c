#include "../cost.h"
#include "../def.h"

#define FADE_MULT 10
#define CHARGE_MULT 5
int lev, pow, charges;

id(str) { return str == "robe" || str == "healing" || str == "robe_of_healing"; }

short() { return "Robe of Healing"; }

long() { 
         write("The robe glows with a gentle light\n"+
               "You feel safe and secure in this robe.\n"+
               "The following powers are conferred to you:\nNote: op means optional\n\n");
         if(cure_var[0] < lev + 1) write("  cure <who> : cures target who's aliments\n");           
         if(defend_var[0] < lev + 1) write("  defend <who> : raises target who's ac\n");
         if(heal_var[0] < lev + 1) write("  heal <who> : heals target who\n"+
                                        "     hp <who>: heals target who hp only\n"+
                                        "     sp <who>: heals target who sp only\n");  
         if(simulcrum_var[0] < lev + 1) write("  illusion <who> : creates an illusion of target who\n");              
         if(peace_var[0] < lev + 1)  write("  peace <op who> : peace\n");                             
         if(potion_var[0] < lev + 1) write("  potion : creates a potion of healing\n");  
         if(reduce_var[0] < lev + 1) write("  reduce <who> : reduces target who's stuff, soak, and intox\n"); 
         if(regenerate_var[0] < lev + 1) write("  regenerate <who> : raises heal rate of target who\n");  
         if(reinstate_var[0] < lev + 1) write("  reinstate <who> <what>: raises what stat of target who\n");            
         if(resurrect_var[0] < lev + 1) write("  resurrect <who> : brings target who to life\n");      
         if(shield_var[0] < lev + 1) write("  shield <who> : partially protects target who from damage\n");      
         
       }
       
set_level(a) { lev = a; charges = lev*CHARGE_MULT;  call_out("fade",lev * FADE_MULT);}
set_piety(a) { pow = a; }

drop() { return 1; }
get() { return 0; }

reset(arg) { if(arg) return; reset_m(); set_light(1); }

init() {
  if(tp == ep) {
    if(heal_var[0] < lev + 1) { add_action("heal","heal"); add_action("heal","chant"); }            
    if(peace_var[0] < lev + 1) add_action("peace","peace");             
    if(cure_var[0] < lev + 1) add_action("cure","cure");            
    if(defend_var[0] < lev + 1) add_action("defend","defend");          
    if(shield_var[0] < lev + 1) add_action("shield","shield");          
    if(reduce_var[0] < lev + 1) add_action("reduce","reduce");          
    if(resurrect_var[0] < lev + 1) add_action("resurrect","resurrect");       
    if(simulcrum_var[0] < lev + 1) add_action("simulcrum","illusion");       
    if(potion_var[0] < lev + 1) add_action("potion","potion");       
    if(reinstate_var[0] < lev + 1) add_action("reinstate","reinstate");       
    if(regenerate_var[0] < lev + 1) add_action("regenerate","regenerate"); 
  }
}

charge_check(int a) { 
  charges -= a;
  if(charges < 1) { tell_object(ep,"The Robe of Healing has no more charges.\n"); fade(); return 1; }
}
  

fade() {
if(!ep) return 1;
  tell_object(ep,"The Robe of Healing disappears.\n");
  destruct(TO);
return 1; }

query_save_flag() { return 1; }

static peace(str) { call_other(POWER,"peace",lev,pow,str); charge_check(peace_var[0]); return 1; }
static heal(str) {
  if(query_verb() == "hp" || query_verb() == "sp") {
    call_other(POWER,"heal",lev,pow,str,query_verb());
  } else call_other(POWER,"heal",lev,pow,str);
  charge_check(heal_var[0]);
return 1; }
static cure(str) { call_other(POWER,"cure",lev,pow,str); charge_check(cure_var[0]); return 1; }
static defend(str) { call_other(POWER,"defend",lev,pow,str); charge_check(defend_var[0]); return 1; }
static shield(str) { call_other(POWER,"shield",lev,pow,str); charge_check(shield_var[0]); return 1; }
static reduce(str) { call_other(POWER,"reduce",lev,pow,str); charge_check(reduce_var[0]); return 1; }
static resurrect(str) { call_other(POWER,"resurrect",lev,pow,str); charge_check(resurrect_var[0]); return 1; }
static simulcrum(str) { call_other(POWER,"simulcrum",lev,pow,str); charge_check(simulcrum_var[0]); return 1; }
static potion() { call_other(POWER,"potion",lev,pow); charge_check(potion_var[0]); return 1; }
static reinstate(str) { 
string boo,hoo;
   if(!str) { write("reinstate <who> <what>\n"); return 1; }
   if(sscanf(str,"%s %s",boo,hoo) != 2) { write("reinstate <who> <what>\n"); return 1; }
       call_other(POWER,"reinstate",lev,pow,boo,hoo); charge_check(reinstate_var[0]); return 1; }
static regenerate(str) { call_other(POWER,"regenerate",lev,pow,str); charge_check(regenerate_var[0]); return 1; }
