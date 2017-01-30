/* i <3 forbin */
inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define SHADOW_PENALTY 25
object victim, forbin_sucks;
string *colors;
int zeus_juice, boobah, heat, q;

query_heat(){
  if(heat < 9)       /* cold */
    return 0;
  else if(heat < 21) /* cool */
    return 1;
  else if(heat < 36) /* warm */
    return 2;
  else if(heat < 48) /* hot */
    return 3;
  else               /* burning */
    return 4;
}

query_color(){
  return colors[query_heat()];
}

reset(arg){
  if(arg) return;

  zeus_juice = 0;                         /* saved usage counter of stone */
  heat = 0;                               /* temp usage counter of stone */
  colors = ({ HIW, HIC, RED, HIR, HIY }); /* heat colors */

  set_short("Siphon Stone");
  set_long(
"This small pale stone is very smooth, as though it has been out in\n"+
"the weather for many centuries.  It is small and flat and has\n"+
"an intricate design carved into its surface.  Staring at the\n"+
"design you become aware of the fact that light distorts around\n"+
"the stone, causing shadows to constantly appear and disappear.\n"+
"This magical stone has a");
  set_weight(1);
  set_value(275);
  call_out("zeusex", 34);
}

id(str){ return str == "stone" || str == "siphon stone"
  || str == "zeus_siphon_stone"; }

short(){
  ::short();
  if(this_player()->query_level() >= 21)
    return query_color()+short_desc+NORM+" ["+RED+zeus_juice+NORM+","+
    HIY+heat+NORM+"]";
  else if(zeus_juice < 300)
    return query_color()+short_desc+NORM;
  else if(zeus_juice < 600)
    return query_color()+short_desc+NORM+" ["+RED+"powerful"+NORM+"]";
  else if(zeus_juice < 900)
    return query_color()+short_desc+NORM+" ["+RED+"insatiable"+NORM+"]";
  else if(zeus_juice >= 900)
    return query_color()+short_desc+NORM+" ["+HIR+"godly"+NORM+"]";
}

long(){
  ::long();
  if(zeus_juice < 300)
    write(BOLD+BLK+" hunger"+NORM+" for energy and is ");
  else if(zeus_juice < 600)
    write(BOLD+BLK+" powerful hunger"+NORM+" for energy and is\n");
  else if(zeus_juice < 900)
    write("n"+BOLD+BLK+" insatiable hunger"+NORM+" for energy and is\n");
  else if(zeus_juice >= 900)
    write(BOLD+BLK+" godly hunger"+NORM+" for energy and is\n");
  if(query_heat() == 0)
    write(query_color()+"cold");
  else if(query_heat() == 1)
    write(query_color()+"cool");
  else if(query_heat() == 2)
    write(query_color()+"warm");
  else if(query_heat() == 3)
    write(query_color()+"hot");
  else if(query_heat() == 4)
    write(query_color()+"burning");
 write(NORM+" to the touch.\n");
}

query_value(){ return (value + zeus_juice); }

feed_me_zeus_juice(){  /* stone usage increments vars */
  if(zeus_juice < 990)
    zeus_juice++;
  if(heat < 64)
    heat += 3;
}

qzj(){ return (zeus_juice / (90 + heat)); }

/* Dmg done on call_out - drain sp always and hp based on heat
   Can do a max of 7 cycles of heat dmg at about 60-80 dmg a cycle */
drain_energy(object beh){
  {
     tell_object(beh, "The "+short_desc+" feeds on your strength");
    if(query_heat() >= 3)
      tell_object(beh, " and "+query_color()+"burns"+NORM+" your hands!\n");
    else
      tell_object(beh, ".\n");
  }
  if(beh->query_spell_point() > (boobah = (SHADOW_PENALTY + (zeus_juice / 23)
    + ((victim->query_extra_level() + 10) / 10))))
    beh->add_sp(-boobah);
  if(beh->query_hp() > (q = ((boobah / 3) + heat)))
    beh->add_hit_point(-q);
}


zeusex(){  /* call out checks */
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
    drain_energy(victim);
  }
  else if(forbin_sucks && environment(forbin_sucks) &&
    victim != forbin_sucks)
    if(present(forbin_sucks, victim) || 
      (environment(victim) &&
      environment(forbin_sucks) == environment(victim)) ||
      (environment(victim) && environment(environment(victim)) &&
      environment(forbin_sucks) == environment(environment(victim)))) 
      drain_energy(forbin_sucks);
  if(heat >= 4)
    heat -= 4;
  else
    heat = 0;
  return (call_out("zeusex", 34+random(29)));
}

/* generic save object code */
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


