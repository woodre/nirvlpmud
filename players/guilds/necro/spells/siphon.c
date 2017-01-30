#include "../defs.h"
/* Guild Level 5 - 
  */
cmd(str) {
int dam, spoints;
object ob, target;
string msg,msg2;

dam = 20;
ob = GOB;
    if(!GOB->checklev(5,10) ) return 1;
    if(!str){
      notify_fail("Who would you like to siphon?\n");
      return 0;
    }
    if(!find_player(str)){
      notify_fail("You can not find that person to siphon.\n");
      return 0;
    }
    target = find_player(str);
    if(environment(target) != environment(this_player()) ){
      write(target->query_name()+" is not here for you to siphon.\n");
      return 1;
    }
    if(!present(GUILD_ID,target)){
      write("You may not siphon from non guild members.\n");
      return 1;
    }
    if(tp->query_attack()){
      write("You can not concentrate enough to siphon while fighting.\n");
      return 1;
    }
    
  msg = MAG+"You concentrate as black tenticles crawl down your leg and across to "+target->query_name()+".\n"+
        "They enter "+target->query_possessive()+" through the chest as the being to pump energy into you.\n"+
        OFF+BOLD+"Suddenly"+OFF+MAG+" a warping pain races through you as the tenticles draw back.\n"+OFF;
  msg2 = MAG+"You see the black tenticles suround you and enter your soul.  Suddenly you feel\n"+
         "a twisting deep inside you as you are drained of your energy.\n"+OFF;
  if(BLOODMOON) {
    msg += ROD+"The Bloodmoon increases the power of your spell.\n";
    dam -= 1; 
  }
  if(GRAVESITE) {
    msg += ROD+"The Graveyard increases the power of your spell.\n";
    dam -= 1; 
  }
  write(msg);
  say("You sense something odd happening.\n");
  tell_object(target,msg2);
  spoints = target->query_sp();
  target->add_spell_point(-spoints);
  tp->add_hit_point(-dam);
  tp->add_spell_point(spoints);
  ob->add_val(1);
  ob->save_me();
  return 1; 
}
