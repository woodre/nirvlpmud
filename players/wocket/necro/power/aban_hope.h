/* Guild Level 4 - Misc spell
   Abandon Hope lowers the targets AC while slightly raising
   its Wc. Powers are greater within a graveyard.
   TotalCost - 37 sp (25 sp, 1 skin, 2 blood)    */
aban_hope(str) {
int dam, armorchange, wepchange;
object ob, ob2, att;

ob = present("necro_ob",this_player());
dam = random(5);
armorchange = 2;
wepchange = 1;

if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Abandon who???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_sp() < 25) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood() < 2) || (ob->query_skin() < 1)) {
write("You do not have the spell components available for the spell.\n");
return 1; }
if (!att) { write ("There is no "+str+" here to target"); return 1; }
if(att->is_player()) {write("You may not cast this spell at a player.\n");
return 1; }
  if(!att->query_attack()) att->attack_object(tp);
if(!(ob2 = present("ac_check",att))) {
  ob2 = clone_object("/players/daranath/guild/obj/misc/ac_check.c");
  move_object(ob2,att);
}
  if(ob2->query_ac_times() > 1) {
  write("You can only cast Abandon Hope twice at the same target.\n");
  return 1; }
  else ob2->add_ac_times(1);
  
  tp->add_spell_point(-25);
  ob->add_val(1);
  ob->add_blood(-2);
  ob->add_skin(-1);
  ob->save_me();
write("\nYou reach into the Realm of Death and summon pure despair.\n"+
      "You unleash the power of the spell at "+att->query_name()+".\n");
if((present("gsite_ob",environment(tp))) || (environment(tp)->graveyard())) {
write("<"+HIW+"RoD"+NORM+"> The Graveyard enhances the power of the spell.\n");
armorchange = armorchange + 1;
}
write(att->query_name() +" gives into the pure despair, lowering its guard.\n");
say(tp->query_name() +" gathers power from the Realm of Death.\n");
say(tp->query_name() +" targets "+att->query_name()+" with the dark spell.\n");
  att->set_ac(att->query_ac() - armorchange);
  att->set_wc(att->query_wc() + wepchange);
return 1; }

