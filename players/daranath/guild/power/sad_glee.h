/* Sadistic Glee replaces Fi for the necros although it adds
   component cost and a slightly chance of damage to the 
   necro. Damage is increased due to increased cost.
   TotalCost - 34sp (20sp, 1 skin, 3 blood)   */
sad_glee(str) {
int dam;
object ob, att;

dam = 8 + random(40);
ob = present("necro_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Who would you like to glee???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_spell_dam()) return 0;
if(tp->query_level() < 15){
write("You must be at least level 15 to use Sphere of Anguish.\n");
return 1; }
if(tp->query_sp() < 20) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood() < 3) || (ob->query_skin() < 1)) {
write("You do not have the spell components available for the spell.\n");
return 1; }
if(!att) {write(str+" is not here to cast glee upon.\n"); return 1; }
  if(!att->query_attack()) att->attacked_by(tp);
  tp->add_spell_point(-20);
  ob->add_val(-1);
  ob->add_blood(-3);
  ob->add_skin(-1);
  ob->save_me();
write("You successfully cast the sadistic glee,\n");
say(tp->query_name() +" unleashes a dark spell at "+att->query_name()+".\n");
say(att->query_name()+" howls in pain and fury.\n");
if(random(5) == 0){
write("The Realm of Death howls in anger, taking part of your soul.\n");
  tp->heal_self(-(4 + random(18)));
say(tp->query_name() +" grimaces in extreme pain from casting the spell.\n"); }
  tp->set_spell_dam(dam);
return 1; }

