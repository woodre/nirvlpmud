#include "def.h"
#include "cost.h"
string cast_bless;
string min_bless;                               
                               
  /* power includes */

#include "power/need.h"
#include "power/holy_blessing.h"
#include "power/help.h"
#include "power/titler.h"
#include "power/check.h"
#include "power/history.h"
#include "power/heal.h"
#include "power/peace.h"
#include "power/fortify.h" 
#include "power/mystic_transfer.h" 
#include "power/cure.h"
#include "power/defend.h"
#include "power/shield.h"
#include "power/reduce.h"
#include "power/mass_heal.h"
#include "power/simulcrum.h" 
#include "power/potion.h"
#include "power/reinstate.h" 
#include "power/regenerate.h"
#include "power/cove.h"
#include "power/full_heal.h" 
#include "power/haven.h" 
#include "power/salve.h" 
#include "power/grant.h" 
#include "power/healing_spring.h"
#include "power/bless.h"
#include "power/robe_of_healing.h"


reset(arg) {
if(ep) { destruct(TO); return 1; }
  min_bless = ({"GUILDDAEM"});
  if(arg) return;
  LLL = LVL = LVV = 0;
  cast_bless = ({"GUILDDAEM"});
  reset_m();
}

resurrect(int lvl,int pi,string who) {
  object targ;
  object ob;
  int xg;
  if(!who) { write("Who do you wish to resurrect?\n"); return 1; }
  if(!(targ=present(who,etp))) { write("That person is not here!\n"); return 1; }
  if(targ == tp) { write("You may not cast this on yourself!\n"); return 1; }
  if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
  if(!targ->query_ghost()) { write("That person is not a ghost!\n"); return 1; }
  if(targ->query_level() > 19)  { write("You can not cast on a wiz!\n"); return 1; }
  if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
  if(resurrect_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
  if(resurrect_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
  if(resurrect_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
  if(resurrect_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
  if(present("healer_rez_object", targ)) { write("That person is already being resurrected.\n"); return 1; }
  
  tp->add_spell_point(-resurrect_var[1]);
  tp->add_hit_point(-resurrect_var[2]);
  if(hob) tp->add_xp(-resurrect_var[3]); else tp->add_exp(-resurrect_var[3]);
  tp->add_money(-resurrect_var[4]);  
  if(!check(lvl,pi,resurrect_var[6],resurrect_var[7],resurrect_var[8])) { 
    write("Your Resurrection fails!\n");
    return 1; 
  }
  write("Pointing your staff at "+capitalize(targ->query_real_name())+", you intone the Prayer of Resurrection.\n");
  say(tp->query_name()+" points the Staff of Healing at a ghost and intones.\n");
  tell_room(etp,"A globe of light appears and surrounds "+capitalize((string)targ->query_real_name())+"'s ghost.\n", ({targ}));
  tell_object(targ,"A globe of light appears and surrounds you.\n");
  ob = clone_object("/" + root + "obj/res_ob");
  move_object(ob, targ);
  ob->start_res(tp, targ, lvl);
  return 1;  
}

add_res_exp(user, str) {
  if(present("mythos_healer",user))        
    user->add_xp(str * 10);
  else
    user->add_exp(str * 10);
}

