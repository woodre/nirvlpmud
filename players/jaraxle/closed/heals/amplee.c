/* Approved by Maledicta, [5/24/02] */

/* Heal that includes 2 types. stuff, and soak. Heals for 50 
hit points and spell points at 4 stuff, 4 soak. 3 uses. 
Cost is figured by toxamount(8)*3 = 24 divided by a heal total of 150
Total is 2700. */

#include "/players/jaraxle/define.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "fruit" || str == "amplee" || str == "amplee fruit"; }
short(){ return BLK+BOLD+"Amp"+NORM+BOLD+"lee"+NORM+" fruit "+BLK+BOLD+"("+NORM+BOLD+uses+BLK+BOLD+")"+NORM; }
long(){
   write(
      "  "+BLK+BOLD+"Amp"+NORM+BOLD+"lee"+NORM+" fruit is legendary for its healing\n"+
      "power and exquisite taste.\n"+
      "There are "+BLK+BOLD+"("+NORM+BOLD+uses+BLK+BOLD+")"+NORM+" bites left.\n"); }

query_value(){ return (uses * 900); }
query_save_flag(){ return 1; }
query_weight(){ return 1; }
get(){ return 1; }

reset(arg){
   if(arg) return;
   uses = 3;      
}

init(){
   add_action("eat_fruit", "eat");
   add_action("eat_fruit", "bite");
}

eat_fruit(str){
   if(!id(str)){ notify_fail("Eat what?\n"); return 0; }
   if(!str){ notify_fail("Eat what?\n"); return 0; }
   
   if(!call_other(this_player(),"eat_food", 4) ||
         !call_other(this_player(),"drink_soft", 4)) return 0;
   write("You take a bite of the juicy "+BLK+BOLD+"Amp"+NORM+BOLD+"lee"+NORM+" fruit.\n");
   say(NAME+" takes a bite of "+BLK+BOLD+"Amp"+NORM+BOLD+"lee"+NORM+" fruit.\n");
   
   call_other(this_player(),"add_hit_point",50);
   call_other(this_player(),"add_spell_point",50);
   call_other(this_player(),"recalc_carry");
   this_player()->print_monitor();
   uses -= 1;
   write("The fruit has "+BLK+BOLD+"("+NORM+BOLD+uses+BLK+BOLD+")"+NORM+" bites left.\n");
   if(!uses){
      write("You take the last bite out of the "+BLK+BOLD+"Amp"+NORM+BOLD+"lee"+NORM+" fruit.\n");
      this_object()->set_weight(0);
      call_other(this_player(), "recalc_carry");
      destruct(this_object());
      return 1; }
   return 1; }

is_heal() { return 1; }

query_charges() { return uses; }
