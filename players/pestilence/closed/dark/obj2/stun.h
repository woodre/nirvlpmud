stun(str) {
int dam, armorchange, wepchange;
object ob, ob2, att;

ob = present("dknight_ob",this_player());
dam = random(5);
armorchange = 2;
wepchange = 1;

if(this_player()->query_guild_rank() < 7){ write("You can't use ability yet.\n"); return 1; }
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Stun who???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_sp() < 30) {
write("You do not have the spell points available for this spell.\n");


return 1; }
if (!att) { write ("There is no "+str+" here to target"); return 1; }
if(att->is_player()) {write("You may not cast this spell at a player.\n");
return 1; }
  if(!att->query_attack()) att->attack_object(tp);
if(!(ob2 = present("ac_check",att))) {
  ob2 = clone_object("/players/pestilence/closed/dark/obj/ac_check.c");
  move_object(ob2,att);
}
  if(ob2->query_ac_times() > 1) {
  write("You can only stun the same target twice.\n");
  return 1; }
  else ob2->add_ac_times(1);
  tp->add_spell_point(-35);

write("\nYou reach into your very soul, pulling out "+HIK+"darkness"+NORM+".\n"+
      "You totally stun "+att->query_name()+" with your "+HIK+"dark"+NORM+" magic.\n");
write(att->query_name() +" breaks down, and becomes slower.\n");
say(tp->query_name() +" gathers power from "+HIK+"dark"+NORM+" within the depths of "+HIR+"Hell"+NORM+".\n");
say(tp->query_name() +" weakens "+att->query_name()+" with a "+HIK+"dark"+NORM+" incantation.\n");
  att->set_ac(att->query_ac() - armorchange);
  att->set_wc(att->query_wc() + wepchange);
return 1; }
