/* Sphere of Anguish replaces sh for the Necromancers. Component
   cost has been added to the spell, as well as a slight chance
   for damage to the necro. Due to increased cost, the 
   damage for the spell is slightly increased.
   TotalCost - 21sp (15sp, 3 blood)    */
sphere(str) {
int dam;
object ob, att;

dam = random(36);
ob = present("necro_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Who would you like to sphere???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_spell_dam()) return 0;
if(tp->query_level() < 10){
write("You must be at least level 10 to use Sphere of Anguish.\n");
return 1; }
if(tp->query_sp() < 15) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood()) < 3) {
write("You do not have the spell components available for the spell.\n");
return 1; }
if(!att) {write(str+" is not here to sphere.\n"); return 1; }
  if(!att->query_attack()) att->attacked_by(tp);
  tp->add_spell_point(-15);
  ob->add_val(1);
  ob->add_blood(-3);
  ob->save_me();
write("You successfully cast the spell and a sphere appears in your hands.\n");
write("The sphere launches itself at "+att->query_name()+".\n");
write(att->query_name()+" recoils from the pain of the spell.\n");
say(tp->query_name() +" throws a glowing sphere at "+att->query_name()+".\n");
if(random(5) == 0){
write("The Realm of Death disapproves of your spell choice!\n");
  tp->add_hit_point(-(random(15)));
say(tp->query_name() +" grimaces in pain.\n"); }
  tp->set_spell_dam(dam);
return 1; }

