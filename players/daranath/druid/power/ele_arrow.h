/* Guild Level 2 - basic attack spell
   TotalCost -> 7 spell points  */

ele_arrow(str) {
int dam;
object ob, att;

dam = 2 + random(4);
ob = present("druid_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Flame arrow who?\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_spell_dam()) return 0;
if(tp->query_sp() < 7) {
write(GRN+"<< "+HIG+"Druid"+NORM+GRN+" >>"+NORM+" Not enough spell points to generate a Flame arrow.\n");
return 1; }
if (!att) { write ("There is no "+str+" here to cast a flame arrow at"); return 1; }
if(tp->query_spell_dam()){ notify_fail("");
  return 0; }

  if(!att->query_attack()) att->attacked_by(tp);
  tp->add_spell_point(-7);
  ob->add_firefav(1);
  ob->add_waterfav(-2);
  ob->save_me();
  tp->set_spell_dam(1);
dam = dam + ob->query_eleskill();
if(ob->query_air() > 250) {dam = dam + 2; }

write("You hit "+att->query_name()+" with an arrow of pure "+HIR+"flame"+NORM+".\n");
say(tp->query_name()+" unleashes an arrow of pure "+HIR+"flame"+NORM+" at "+att->query_name()+".\n");
   att->hit_player(dam, "other|fire");
return 1; }
