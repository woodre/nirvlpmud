/* Guild Level 4 - Misc Spell
   Cloak of Confusion lowers the targets WC while slightly
   raising the AC of the target. 
   TotalCost - 37 sp (25sp, 1 skin, 2 blood)    */
conf_cloak(str) {
int dam, armchange, wepchange;
object ob, ob2, att;

ob = present("necro_ob",this_player());
dam = random(5);
armchange = 1;
wepchange = 3;

if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Who do you want to cloak???\n"); return 1; }
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
if(!(ob2 = present("wc_check",att))) {
  ob2 = clone_object("/players/daranath/guild/obj/misc/wc_check.c");
  move_object(ob2,att);
}
  if(ob2->query_wc_times() > 1) {
  write("You can only cast Cloak of Confusion twice at the same target.\n");
  return 1; }
  else ob2->add_wc_times(1);
  
  tp->add_spell_point(-25);
  ob->add_val(1);
  ob->add_blood(-2);
  ob->add_skin(-1);
  ob->save_me();
write("\nYou reach into the Realm of Death and summon negative energy.\n"+
      "You unleash the power of the spell at "+att->query_name()+".\n");
if((present("gsite_ob",environment(tp))) || (environment(tp)->gravesite())) {
write("<"+HIW+"RoD"+NORM+"> The graveyard strengthens the power of your spell.\n");
wepchange = wepchange + 1;
}
write(att->query_name()+" gives way the confusion, causing its attacks to suffer.\n");
say(tp->query_name()+" gathers power from the Realm of Death.\n");
say(tp->query_name() +" targets "+att->query_name()+" with the dark spell.\n");
  att->set_ac(att->query_ac() + armchange);
  att->set_wc(att->query_wc() - wepchange);
return 1; }

