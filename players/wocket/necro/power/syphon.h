/* Guild Level 6 - Neg heal attack spell plus healing effect
   healing effect from necro stealing the lifeforce of target
   TotalCost - 67 sp (25 sp, 1 Eye, 2 Skin, 3 Blood)  */
syphon(str) {
int dam, heal;
object ob, att;

dam = 15 + random(25);
heal = 3 + random(12);
ob = present("necro_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Syphon who???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_sp() < 25) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood() < 3) || (ob->query_skin() < 2) || (ob->query_eye() < 1)) {
write("You do not have the spell components available for the spell.\n");
return 1; }
if (!att) { write ("There is no "+str+" here to syphon"); return 1; }
if(att->is_player()) {write("You may not syphon off a player!\n");
return 1; }
  if(!att->query_attack()) att->attack_object(tp);
  tp->add_spell_point(-25);
  ob->add_val(2);
  ob->add_blood(-3);
  ob->add_skin(-2);
  ob->add_eye(-1);
  ob->save_me();
write("You open a channel between the Realm of Death and Nirvana.\n"+
      "You use the negative energy to Syphon the lifeforce from your foe.\n");
if(present("badmoon",environment(tp))) {
dam = dam + 5;
heal = heal + 3;
write("The badmoon increases the power of your spell.\n"); }
write("You feel healed and more powerful from the Syphon.\n");
say(tp->query_name()+"'s eyes flash with a burst of power.\n");
say(att->query_name()+" howls in pain and agnony.\n");
  tp->add_hit_point(heal);
  att->heal_self(-dam);
return 1; }
