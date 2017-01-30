/* Guild Level 1 - basic attack spell
  TotalCost -> 12 spell points (10 sp + 1 blood) */
touch_chill(str) {
int dam;
object ob, att;

dam = 4 + random(15);
ob = present("necro_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Touch who???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_spell_dam()) return 0;
if(tp->query_sp() < 10) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood()) < 1) {
write("You do not have the spell components available for the spell.\n");
return 1; }
if (!att) { write ("There is no "+str+" here to touch"); return 1; }
if(att->is_player()) {write("You may not cast this spell at a player.\n");
return 1; }
  if(!att->query_attack()) att->attacked_by(tp);
  tp->add_spell_point(-10);
  ob->add_val(1);
  ob->add_blood(-1);
  ob->save_me();
write("Your hand grows numb with the ice chill of the afterlife.\n");
if(present("badmoon",environment(tp))) {
write("<"+HIW+"RoD"+NORM+"> The Badmoon increases the power of your spell.\n");
dam = dam + 3; }
if((present("gsite_ob",environment(tp))) || (environment(tp)->gravesite())) {
write("<"+HIW+"RoD"+NORM+"> The Graveyard increases the power of your spell.\n");
dam = dam + 2; }
write("You reach out and grasp "+att->query_name()+".\n");
say(tp->query_name() +" reaches out and touches "+att->query_name()+".\n");
  tp->set_spell_dam(dam);
return 1; }
