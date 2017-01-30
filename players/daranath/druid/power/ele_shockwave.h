/* Guild Level 2 - basic attack spell
   TotalCost -> 7 spell points  */

ele_shockwave(str) {
int dam;
object ob, att;

dam = 2 + random(4);
ob = present("druid_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Shockwave who?\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_spell_dam()) return 0;
if(tp->query_sp() < 7) {
write(GRN+"<< "+HIG+"Druid"+NORM+GRN+" >>"+NORM+" Not enough spell points to generate a Shockwave.\n");
return 1; }
if (!att) { write ("There is no "+str+" here to cast a spark at"); return 1; }
if(tp->query_spell_dam()){ notify_fail("");
  return 0; }

  if(!att->query_attack()) att->attacked_by(tp);
  tp->add_spell_point(-7);
  ob->add_earthfav(1);
  ob->add_airfav(-2);
  ob->save_me();
  tp->set_spell_dam(1);
dam = dam + ob->query_eleskill();
if(ob->query_air() > 250) {dam = dam + 2; }

write("You tap your "+HIG+"Woodland Staff"+NORM+" down upon the ground...\n"+
      "causing a "+YEL+"Shockwave"+NORM+" to lash out at "+att->query_name()+".\n");
say(tp->query_name()+" taps "+tp->query_possessive()+" wooden staff upon the ground, causing the\n"+
      "earth itself to lash out at "+att->query_name()+".\n");
   att->hit_player(dam, "other|earth");
return 1; }
