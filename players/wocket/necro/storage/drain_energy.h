drain_energy(str) {
int dam;
object ob, att;

dam = random(25) + 10;
ob = present("necro_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Energydrain who???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_sp() < 50) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood() < 5) || (ob->query_skin() < 3) || (ob->query_spine() < 1)){
write("You do not have the spell components available for the spell.\n");
return 1; }
if (!att) { write ("There is no "+str+" here to touch"); return 1; }
if(att->is_player()) {write("You may not drain a player!\n");
return 1; }
  if(!att->query_attack()) att->attack_object(tp);
  att->heal_self(-dam);
  tp->heal_self(random(7));
  write("You feel stronger from the lifedrain.\n");
  tp->add_spell_point(-50);
  ob->add_val(1);
  ob->add_blood(-5);
  ob->add_skin(-3);
  ob->add_spine(-1);
  ob->save_me();
write("Your hand grows numb with the icy chill of the afterlife.\n"+
      "You reach out and grasp "+str+".\n");
say(tp->query_name() +" reaches out and touches "+att->query_name()+".\n");
return 1; }
