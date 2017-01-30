/* Spectral Touch replaces Mi for the Necromancers. Comp cost
   has been added to the spell, 1 part blood. Damage is slightly
   increased over what Missile spell does, due to added cost.
   TotalCost - 12 sp (10 sp plus 1 part Blood)   */
touch_spect(str) {
int dam;
object ob, att;

dam = random(24);
ob = present("necro_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Who would you like to grasp???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_spell_dam()) return 0;
if(tp->query_level() < 5){
write("You must be at least level 5 to use Spectral Grasp.\n");
return 1; }
if(tp->query_sp() < 10) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood()) < 1) {
write("You do not have the spell components available for the spell.\n");
return 1; }
if(!att) {write(str+" is not here to grasp.\n"); return 1; }
  if(!att->query_attack()) att->attacked_by(tp);
  tp->add_spell_point(-10);
  ob->add_val(1);
  ob->add_blood(-1);
  ob->save_me();
write("You delve into your contacts with the Realm of Death.\n"+
      "Your hand grows insubstaintial and you rake "+att->query_name()+" with it.\n");
say(tp->query_name()+" reaches out and rakes "+att->query_name()+" with spectral claws.\n");
  tp->set_spell_dam(dam);
return 1; }
