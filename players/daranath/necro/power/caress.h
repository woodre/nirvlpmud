/* Caress replaces Sonic for same damage and spell
   cost, although the necro must pay components as well */
caress(str) {
int dam;
object ob, att;

dam = 15 + random(40);
ob = present("necro_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Who would you like to caress???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_spell_dam()) return 0;
if(tp->query_extra_level() < 5){
write("You must be at least level 19+5 to use Jester's Caress of Shadows.\n");
return 1; }
if(tp->query_sp() < 25) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_eye() < 1) || (ob->query_skin() < 2)) {
write("You do not have the spell components available for the spell.\n");
return 1; }
if(!att) {write(str+" is not here to cast caress upon.\n"); return 1; }
  if(!att->query_attack()) att->attacked_by(tp);
  tp->add_spell_point(-25);
  ob->add_val(2);
  ob->add_eye(-1);
  ob->add_skin(-2);
  ob->save_me();
write("You successfully cast the spell and a sphere appears in your hands.\n");
say(tp->query_name() +" throws a glowing sphere at "+att->query_name()+".\n");
if(random(3) == 0){
write("<"+HIW+"RoD"+NORM+"> The Realm of Death howls in anger, taking part of your soul.\n");
  tp->heal_self(-(random(20)));
  tp->raise_stamina(-1);
say(tp->query_name() +" grimaces in extreme pain.\n"); }
  tp->set_spell_dam(dam);
return 1; }

