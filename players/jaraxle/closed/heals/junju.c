/* Approved by Maledicta, [5/24/02] */

/* Heal that includes 2 types. stuff, and soak. Heals for 50 
hit points at 4 stuff, 4 soak. 3 uses. 
Cost is figured by toxamount(8)*3 = 24 divided by a heal total of 150
Total is 2400 minus 33% (about 2/3) for healing
only one type = 1800. rounded up for a cost of: 1800 coins. 600 per
dose. */

#include "/players/jaraxle/define.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "fruit" || str == "junju" || str == "junju fruit"; }
short(){ return HIG+"Jun"+HIY+"ju"+NORM+" fruit "+HIG+"("+HIY+uses+HIG+")"+NORM; }
long(){
   write(
      "  The "+HIG+"Jun"+HIY+"ju"+NORM+" fruit is small, and round.  The fruit\n"+
      "has a crispy yet thin "+HIY+"yellow"+NORM+" skin.  Inside the\n"+
      ""+HIG+"green"+NORM+" texture is very sweet.\n"+
      "There are "+HIG+"("+HIY+uses+HIG+")"+NORM+" bites left.\n"); }

query_value(){ return (uses * 600); }
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
   write("You take a bite of the juicy "+HIG+"Jun"+HIY+"ju"+NORM+" fruit.\n");
   say(NAME+" takes a bite of "+HIG+"Jun"+HIY+"ju"+NORM+" fruit.\n");
   
   call_other(this_player(),"add_hit_point",50);
   call_other(this_player(),"recalc_carry");
   write(HIG+"\tHP"+HIY+"("+NORM+HP+HIY+"/"+NORM+MHP+HIY+") "+HIG+"SP"+HIY+"("+NORM+SP+HIY+"/"+NORM+MSP+HIY+")\n"+NORM);
   uses -= 1;
   write("The fruit has "+HIG+"("+HIY+uses+HIG+")"+NORM+" bites left.\n");
   if(!uses){
      write("You take the last bite out of the "+HIG+"Jun"+HIY+"ju"+NORM+" fruit.\n");
      this_object()->set_weight(0);
      call_other(this_player(), "recalc_carry");
      destruct(this_object());
      return 1; }
   return 1; }

is_heal() { return 1; }

query_charges() { return uses; }
