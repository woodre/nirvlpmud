/* i <3 forbin */
inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define SHADOW_PENALTY 25
object victim, forbin_sucks;
int zeus_juice, boobah;

reset(arg){
  if(arg) return;

  zeus_juice = 990;
  set_short(HIW+"Siphon Stone"+NORM);
  set_long(
"This small pale stone is very smooth, as though it has been out in\n"+
"the weather for many centuries.  It is small and flat and has\n"+
"an intricate design carved into its surface.  Staring at the\n"+
"design you become aware of the fact that light distorts around\n"+
"the stone, causing shadows to constantly appear and disappear.\n"+
HIW+"This magical stone has a");
  set_weight(1);
  set_value(275);
  call_out("zeusex", 34);
}

id(str){ return str == "stone" || str == "siphon stone"
  || str == "zeus_siphon_stone"; }

short(){
  ::short();
  if(this_player()->query_level() >= 21)
    return short_desc+" ["+RED+zeus_juice+NORM+"]";
  else if(zeus_juice < 300)
    return short_desc;
  else if(zeus_juice < 600)
    return short_desc + " ["+RED+"powerful"+NORM+"]";
  else if(zeus_juice < 900)
    return short_desc + " ["+RED+"insatiable"+NORM+"]";
  else if(zeus_juice >= 900)
    return short_desc + " ["+HIR+"godly"+NORM+"]";
}

long(){
  ::long();
  if(zeus_juice < 300)
    write(" hunger for energy.\n"+NORM);
  else if(zeus_juice < 600)
    write(" powerful hunger for energy.\n"+NORM);
  else if(zeus_juice < 900)
    write("n insatiable hunger for energy.\n"+NORM);
  else if(zeus_juice >= 900)
    write(" godly hunger for energy.\n"+NORM);
}

query_value(){ return (value + zeus_juice); }

feed_me_zeus_juice(){ if(zeus_juice < 990) zeus_juice++; }
qzj(){ return (zeus_juice / 90); }

drain_sps(object beh){
  if(!random(3))
    tell_object(beh, "The "+short_desc+" feeds on your strength.\n");
  boobah = (SHADOW_PENALTY + (zeus_juice / 23)
    + ((victim->query_extra_level() + 10) / 10));
  if(beh->query_spell_point() > boobah)
    beh->add_sp(-boobah);
}


zeusex(){
  if(environment())
    victim = environment();
  else
    return;
  if(victim && environment(victim))
  {
    if(environment(victim)->is_player())
      victim = environment(victim);
  }
  if(victim->is_player() && victim->query_guild_name() == "fallen"
    && !victim->query_attack())
  {
    forbin_sucks = victim;
    drain_sps(victim);
  }
  else if(forbin_sucks && environment(forbin_sucks) &&
    victim != forbin_sucks)
    if(present(forbin_sucks, victim) || 
      (environment(victim) &&
      environment(forbin_sucks) == environment(victim)) ||
      (environment(victim) && environment(environment(victim)) &&
      environment(forbin_sucks) == environment(environment(victim)))) 
      drain_sps(forbin_sucks);
  return (call_out("zeusex", 34+random(29)));
}

generic_object(){ return 1; }

restore_thing(str){
  restore_object(str);
  return 1;
}

save_thing(str){
  save_object(str);
  return 1;
}

locker_arg(){ return "" + zeus_juice; }

locker_init(arg){  zeus_juice = atoi(arg);  }


